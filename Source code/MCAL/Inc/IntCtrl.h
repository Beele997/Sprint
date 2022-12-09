 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \IntCtrl.h
 *         \IntCtrl   
 *
 *         \Header file for IntCtrl Module
 *
 ********************************************************************************************************************/
 #ifndef INT_CTRL_H_
 #define INT_CTRL_H_
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 
 #include "Std_types.h"
 #include "IntCtrl_Cfg.h"
 
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    LOCAL DATA
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    GLOBAL DATA
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    LOCAL FUNCTION PROTOTYPES
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    LOCAL FUNCTION
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    GLOBAL FUNCTION
 ********************************************************************************************************************/
 
 
 
 
 
 
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