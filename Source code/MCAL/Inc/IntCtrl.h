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
 *    GLOBAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 #define VECTKEY                   0xFA05                 /*Key word Should be Used while Writting on APINT Register*/
//#define VECTKEY        		   0x05FA                 /*To Change The written on the Regiter bits               */
 
 
 #define PRI(i)         		   (0x4+i)
 #if CHOSEN_PRI_GROUP              GR8_SUB0
 #define PRIO_POSITION             (0x4<<8)
 #elif CHOSEN_PRI_GROUP            GR4_SUB2
 #define PRIO_POSITION             (0x5<<8)
 #elif CHOSEN_PRI_GROUP            GR2_SUB4
 #define PRIO_POSITION             (0x6<<8)
 #elif CHOSEN_PRI_GROUP            GR0_SUB8
 #define PRIO_POSITION             (0x7<<8)
 #endif
 
 

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
 void IntCtrl_Init(IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum,uint8 InterruptPriority,uint8 Priority_Group);
 
 #endif       /*IntCtrl.h*/
 /********************************************************************************************************************
 *    END OF FILE: IntCtrl.h	
 ********************************************************************************************************************/