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
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 
 #include "Std_types.h"
 #include "IntCtrl_Cfg.h"
 
/********************************************************************************************************************
 *    GLOBAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 #define VECTKEY                   0xFA05                 /*Key word Should be Used while Writting on APINT Register*/
//#define VECTKEY        		   0x05FA                 /*To Change The written on the Regiter bits               */
 
 
 #define PRI(i)         		   (0x04+i)
 #if Priority_Group_Checked         0
 #define PRIO_POSITION             (0x04)
 #elif Priority_Group_Checked       1
 #define PRIO_POSITION             (0x05)
 #elif Priority_Group_Checked       2
 #define PRIO_POSITION             (0x06)
 #elif Priority_Group_Checked       3
 #define PRIO_POSITION             (0x07)
 #endif
 
 #define SELECT_PRIGROUP         PRIO_POSITION<<8

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
 void IntCtrl_Init(void);
 
 #endif       /*IntCtrl.h*/
 /********************************************************************************************************************
 *    END OF FILE: IntCtrl.h	
 ********************************************************************************************************************/