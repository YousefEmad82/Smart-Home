//
//  i2c.h
//  Author :yousef
//
//  
//


#include "I2C_Interface.h"

static uint8 masterMode;

void i2c_init(void)
{
    TWSR_REG &= ~((1 << TWPS1_PIN) | (1 << TWPS0_PIN)); // pre-scalar 1
    TWBR_REG = ((F_CPU / F_I2C) - 16) / 2; // baud rate factor 12
}

uint8 i2c_tx_start(uint8 mode)
{
    sint8 status = 0;
    masterMode = mode; // set global state of R/W bit

    /* clear interrupt flag, issue start command (gain control of bus as
       master), enable I2C (SCL and SDA are automatically reconfigured) */
    TWCR_REG |=  (1 << TWINT_PIN) | (1 << TWSTA_PIN) | (1 << TWEN_PIN);

    /* wait until start transmitted */
    while (!(TWCR_REG & (1 << TWINT_PIN)));

    switch (TWSR_REG & 0xF8) {
        /* start condition sent from master */
        case 0x08:
            status = TRANSMISSION_SUCCESS;
            break;

        /* repeat start condition sent from master */
        case 0x10:
            status = TRANSMISSION_SUCCESS;
            break;

        default:
            status = TRANSMISSION_ERROR;
            break;
    }

    return status;
}

uint8 i2c_tx_address(uint8 address)
{
    sint8 status = 0;

    TWDR_REG = (address << 1) | masterMode;
    /* clear start command to release bus as master */
    TWCR_REG &= ~(1 << TWSTA_PIN);
    /* clear interrupt flag */
    TWCR_REG |=  (1 << TWINT_PIN);

    /* wait until address transmitted */
    while (!(TWCR_REG & (1 << TWINT_PIN)));

    if (masterMode == MASTER_TRANSMITTER) {
        switch (TWSR_REG & 0xF8) {
            /* address|write sent and ACK returned */
            case 0x18:
                status = TRANSMISSION_SUCCESS;
                break;

           /* address|write sent and NACK returned slave */
           case 0x20:
                status = TRANSMISSION_ERROR;
                break;

            /* address|write sent and bus failure detected */
            case 0x38:
                status = TRANSMISSION_ERROR;
                break;

            default:
                status = TRANSMISSION_ERROR;
                break;
        }
    } else if (masterMode == MASTER_RECEIVER) {
        switch (TWSR_REG & 0xF8) {
            /* address|read sent and ACK returned */
            case 0x40:
                status = TRANSMISSION_SUCCESS;
                break;

            /* address|read sent and NACK returned */
            case 0x48:
                status = TRANSMISSION_ERROR;
                break;

            case 0x38:
                status = TRANSMISSION_ERROR;
                break;

            default:
                status = TRANSMISSION_ERROR;
                break;
        }
    }

    return status;
}

uint8 i2c_tx_byte(uint8 byteData)
{
    sint8 status = 0;
    TWDR_REG  = byteData; // load data buffer with data to be transmitted
    TWCR_REG |= (1 << TWINT_PIN); // clear interrupt flag

    /* wait until data transmitted */
    while (!(TWCR_REG & (1 << TWINT_PIN)));

    /* retrieve transmission status codes */
    switch (TWSR_REG & 0xF8) {
        /* byte sent and ACK returned */
        case 0x28:
            status = TRANSMISSION_SUCCESS;
            break;

        /* byte sent and NACK returned */
        case 0x30:
            status = TRANSMISSION_ERROR;
            break;

        /* byte sent and bus failure detected */
        case 0x38:
            status = TRANSMISSION_ERROR;
            break;

        default:
            status = TRANSMISSION_ERROR;
            break;
    }

    return status;
}

sint8 i2c_timeout(void)
{
    uint8 time = TIMEOUT;
    sint8 status = BUS_DISCONNECTED;

    while (time-- > 0) {
        /* check to see if bus is ready */
        if ((TWCR_REG & (1 << TWINT_PIN))) {
            status = BUS_CONNECTED;
            break;
        }
    }

    return status;
}

uint8 i2c_rx_byte(uint8 response)
{
    sint8 status;

    if (response == ACK) {
        TWCR_REG |= (1 << TWEA_PIN); // generate ACK
    } else {
        TWCR_REG &= ~(1 << TWEA_PIN); // generate NACK
    }

    /* clear interrupt flag */
    TWCR_REG |= (1 << TWINT_PIN);

    /* detect bus time-out */
    if (i2c_timeout() != BUS_DISCONNECTED) {
        /* retrieve transmission status codes or received data */
        switch (TWSR_REG & 0xF8) {
            /* data byte read and ACK returned by master */
            case 0x50:
                status = TWDR_REG;
                break;

            /* data byte read and NACK returned by master */
            case 0x58:
                status = TWDR_REG;
                break;

            /* bus failure detected */
            case 0x38:
                status = TRANSMISSION_ERROR;
                break;

            default:
                status = TRANSMISSION_ERROR;
                break;
        }
    } else {
        status = TRANSMISSION_ERROR;
    }

    return status;
}

void i2c_tx_stop(void)
{
    /* clear interrupt flag, issue stop command (cleared automatically) */
    TWCR_REG |= (1 << TWINT_PIN) | (1 << TWSTO_PIN);

    while (!(TWCR_REG & (1 << TWSTO_PIN))); // wait until stop transmitted
}
