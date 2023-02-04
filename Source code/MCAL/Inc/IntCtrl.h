 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \IntCtrl.h
 *         \IntCtrl   
 *
 *         \Header file for IntCtrl Module
 *
 ********************************************************************************************************************/
 #ifndef INTCTRL_H_
 #define INTCTRL_H_

#include "IntCtrl_Types.h"
/********************************************************************************************************************
 *    GLOBAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 #define VECTKEY_KEY_MSK           0xFA05                 /*To Change The written on the Regiter bits****************/
 #define VECTKEY        		   0x05FA                 /*Key word Should be Used while Writting on APINT Register*/
 #define APINT_PRIGROUP_MSK        0x0                    /*Reset PRIGROUP Bits**************************************/
 #define APINT_PRIGROUP_POS        0x8                    /*PRIGROUP BitsPostions in APINT***************************/
 


 #define GR8_SUB0             (0x4)
 #define GR4_SUB2             (0x5)
 #define GR2_SUB4             (0x6)
 #define GR0_SUB8             (0x7)
 
 

 /********************************************************************************************************************
 *   \Syntax                  :  void IntCtrl_Init(void)
 *   \Description             :  Intialization NVIC/SCB Module by parsing the configuration
 *                               into NVIC/SCB registers
 *
 *   \Sync\Async              :  Synchronous
 *   \Reentrancy              :  Non Reentrant
 *   \Parameters (in)         :  Parameter Name  Parameter Description
 *   \Parameters (out)        :  None
 *   \Return value            :  Std_ReturnType  E_OK
 *                                               E_NOT_OK
 ********************************************************************************************************************/
 void IntCtrl_Init(IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum,uint8 IntPriority_G,uint8 IntPriority_s,uint8 Priority_Group_Type);
 
 #endif       /*IntCtrl.h*/
 /********************************************************************************************************************
 *    END OF FILE: IntCtrl.h	
 ********************************************************************************************************************/