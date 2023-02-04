 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \GPT.h   
 *         \General Purpose Timer Driver   
 *
 *         \The driver configure all MCU Timers  
 *          Enable and Initialize GPT
 *
 ********************************************************************************************************************/
#ifndef GPT_H_
#define GPT_H_
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 #define GPT_Timer0                      0
 #define GPT_Timer1                      1
 #define GPT_Timer2                      2
 #define GPT_Timer3                      3
 #define GPT_Timer4                      4
 #define GPT_Timer5                      5
 
 #define GPT_TIMER_16_32BIT              0
 #define GPT_TIMER_32_65BIT              1
 
 #define GPT_DISABLE_CLOCK               0
 #define GPT_ENABLE_CLOCK                1
 
 #define GPT_DISABLE_TIMER               0
 #define GPT_ENABLE_TIMER                1
 
 #define GPT_ONE_SHOT_MODE               0x1
 #define GPT_PERIODIC_MODE               0x2
 
 #define NORMAL_TIMER_MODE               0
 #define PWM_MODE                        1
 
/********************************************************************************************************************
 *    GLOBAL DATA
 ********************************************************************************************************************/

 
/********************************************************************************************************************
 *    GLOBAL FUNCTION PROTOTYPES
 ********************************************************************************************************************/
 
 void GPT_SetClcRunMode(uint8 GPT_TimerBit,uint8 GPT_TimerType,uint8 GPT_ClcState);
 void GPT_Init(uint8 TimerMode,uint8 GPT_TimerBit,uint8 GPT_TimerType,uint32 GPT_CTRL);
 void TIMER1A_Handler();
 void GPT_timer1_SetCallBack(void(*POINTER_FUNC)(void));
 void GPT_timer0_SetCallBack(void(*POINTER_FUNC)(void));
 
 
 
 /********************************************************************************************************************
 *   \Syntax                  :  void GPT_Init(void)
 *   \Description             :  Intialization GPT Module by parsing the configuration
 *                               
 *
 *   \Sync\Async              :  Synchronous
 *   \Reentrancy              :  Non Reentrant
 *   \Parameters (in)         :  Parameter Name  Parameter Description
 *   \Parameters (out)        :  None
 *   \Return value            :  Std_ReturnType  E_OK
 *                                               E_NOT_OK
 ********************************************************************************************************************/

 
 #endif
 /********************************************************************************************************************
 *    END OF FILE: GPT.c
 ********************************************************************************************************************/