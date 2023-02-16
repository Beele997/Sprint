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
#define TIMER_PRESCALER_1    1   /*PRESCALER Value 1 selected*/
#define TIMER_PRESCALER_8    8	 /*PRESCALER Value 8 selected*/
#define TIMER_PRESCALER_64 	64	 /*PRESCALER Value 64 selected*/
#define TIMER_PRESCALER_256 256  /*PRESCALER Value 265 selected*/

#define TIMER_CLOCK_INTERNAL 		0 /*Internal timer is used*/
#define TIMER_CLOCK_EXTERNAL 		1 /*External timer is used*/

#define TIM0 ((uint32_t)0X0000001)  /*Timer 0 sellected*/
#define TIM1 ((uint32_t)0X0000010)	/*Timer 1 sellected*/
#define TIM2 ((uint32_t)0X0000100)	/*Timer 2 sellected*/
#define TIM3 ((uint32_t)0X0001000)	/*Timer 3 sellected*/
#define TIM4 ((uint32_t)0X0010000)	/*Timer 4 sellected*/
#define TIM5 ((uint32_t)0X0100000)	/*Timer 5 sellected*/

/********************************************************************************************************************
 *    LOCAL DATA & DATA STRUCTURE
 ********************************************************************************************************************/
typedef enum 
{
	
  TIMER_OK,						/*return state is done*/
  TIMER_ERROR					/*An error occured 	  */
  
} Timer_Status_t;

typedef enum
{
	
    GPT_MODE_CONT,   			/*Continues mode sellected*/
    GPT_MODE_ONESHOT,			/*one shot mode sellected*/
    GPT_MODE_SPEC				/*Spec mode sellected*/

} GPT_ModeType;

typedef struct 
{
  GPT_ModeType ChannelMode;					/* configured mode*/
  uint8_t prescaler;						/* configured prescaler */
  uint8_t clock_source;						/* configured Timer type */
  uint32_t TickFrequency;					/* configured frequency */
  void (*PeriodElapsedCallback)(void);		/*Set call back to Elapsed API */
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
 /*Initialize the Timer*/
Timer_Status_t Timer_Init(Timer_Config_t* config, Timer_Callback_t callback);

/*Control functions */
Timer_Status_t GPT_Timer_Start(void);
Timer_Status_t GPT_Timer_Stop(void);
uint32_t GPT_GetTimeElapsed(TIM_TypeDef Channel);
uint32_t GPT_GetTimeRemaining(TIM_TypeDef Channel);

/*Callack functions*/
void GPT_Timer_Callback_t(void (*callback)(void));

#endif /*End of file Timer file*/