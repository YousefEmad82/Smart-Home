#ifndef LIB_CALCBIT_H_
#define LIB_CALCBIT_H_

#define setBit(REG,BIT) (REG|=(1<<BIT))
#define clearBit(REG,BIT) (REG&=(~(1<<BIT)))
#define toggleBit(REG,BIT) (REG^=(1<<BIT))
#define getBit(REG,BIT) ((REG>>BIT)&1)
#endif /* LIB_CALCBIT_H_ */
