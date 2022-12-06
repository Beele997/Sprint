/*
******************* Date : 25/8/2022      *********************************
******************* Name : Ahmed Elebaby  *********************************
******************* Version : 1.0         *********************************
******************* SWC  : BIT MATH       *********************************


*/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM) REG|=(1<<BIT_NUM)
#define RESET_BIT(REG,BIT_NUM) REG&=(~(1<<BIT_NUM))
#define TOGGLE(REG,BIT_NUM) REG^=(1<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM) ((REG>>BIT_NUM)&1)



#endif


