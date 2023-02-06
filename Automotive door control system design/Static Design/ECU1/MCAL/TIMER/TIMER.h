/***********************************************************************************************************************
 *   \date 	  : 06.02.2023          
 *   \name 	  : Ahmed Elebaby       
 *	 \version : 1.0              
 *	 \SWC     : Timer driver          
 *   \brief   : Header file of Timer MCAL module.
************************************************************************************************************************/
#ifndef __MCAL_TIMER_H__
#define __MCAL_TIMER_H__


/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 #include <stdint.h>
 
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
#define TIMER_PRESCALER_1    1
#define TIMER_PRESCALER_8    8
#define TIMER_PRESCALER_64 	64
#define TIMER_PRESCALER_256 256

#define TIMER_CLOCK_INTERNAL 0
#define TIMER_CLOCK_EXTERNAL 1

#define TIM0 ((uint32_t)0X0000001)
#define TIM1 ((uint32_t)0X0000010)
#define TIM2 ((uint32_t)0X0000100)
#define TIM3 ((uint32_t)0X0001000)
#define TIM4 ((uint32_t)0X0010000)
#define TIM5 ((uint32_t)0X0100000)

/********************************************************************************************************************
 *    LOCAL DATA & DATA STRUCTURE
 ********************************************************************************************************************/
typedef enum 
{
	
  TIMER_OK,
  TIMER_ERROR
  
} Timer_Status_t;

typedef enum
{
	
    GPT_MODE_CONT,
    GPT_MODE_ONESHOT,
    GPT_MODE_SPEC

} GPT_ModeType;

typedef struct 
{
	
  uint8_t prescaler;
  uint8_t clock_source;
  uint32_t TickFrequency;
  void (*PeriodElapsedCallback)(void);
} Timer_Config_t;



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
 /*Initialize the can*/
Timer_Status_t Timer_Init(Timer_Config_t* config, Timer_Callback_t callback);

/*Control functions */
Timer_Status_t GPT_Timer_Start(void);
Timer_Status_t GPT_Timer_Stop(void);
uint32_t GPT_GetTimeElapsed(TIM_TypeDef Channel);
uint32_t GPT_GetTimeRemaining(TIM_TypeDef Channel);

/*Callack functions*/
void GPT_Timer_Callback_t(void (*callback)(void));

#endif /*End of file Timer file*/