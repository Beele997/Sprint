 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \Project_LED.c   
 *         \brief  
 *
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 #include "Std_types.h"
 #include "BIT_MATH.h"
 #include "Mcu_Hw.h"
 #include "IntCtrl.h"
 #include "IntCtrl_Cfg.h"
 #include "IntCtrl_Types.h"
 #include "GPIO.h"
 #include "GPIO_Cfg.h"
 #include "GPIO_Types.h"
 #include "GPT.h"
 #include "GPT_Cfg.h"
 #include "GPT_Types.h"
 #include "LED_INTERFACE.h"
 #include "Switch.h"
/********************************************************************************************************************/
 int main(void)
 {
	 IntCtrl_Init(Timer1A,UNDEFINED_EEXCEPTION,7,GR8_SUB0);
	 IntCtrl_Init(GPIO_Port_F,UNDEFINED_EEXCEPTION,7,GR8_SUB0);
	 uint8 SwitchValue1;
	 uint8 SwitchValue2;
	 GET_SWITCH(PULL_UP,GPIO_PORTF,GPIO_PIN4,&SwitchValue1);
	 GET_SWITCH(PULL_UP,GPIO_PORTF,GPIO_PIN4,&SwitchValue2);
	 uint32 u32_Counting_OPEN;
	 uint32 u32_Counting_CLOSE;
	 uint32 u32_wait;
	 while(1)
	 {
	     while (SwitchValue1 == 1)
		 {
			 u32_Counting_OPEN++;
			 GPT_COUNTING_TIME1(u32_Counting_OPEN);
			 
		 }
		 
		 for(u32_wait=0;u32_wait<64000;u32_wait++)
		 {
		 }
		 
		 while (SwitchValue2 == 1)
		 {
			 u32_Counting_CLOSE++;
			 GPT_COUNTING_TIME0(u32_Counting_CLOSE);
		 }
	 }
	 GPT_Init(GPT_TIMER_16_32BIT,GPT_Timer1,GPT_ENABLE_TIMER);
	 GPT_Init(GPT_TIMER_16_32BIT,GPT_Timer1,GPT_ENABLE_TIMER);
 }
 
 void GPT_timer1_SetCallBack(void(*POINTER_FUNC_GPT_TIMER1)(void))
{
	POINTER_FUNC_GPT_TIMER1 = &LED_ON(LED0);
}
 
 void GPT_timer0_SetCallBack(void(*POINTER_FUNC_GPT_TIMER0)(void))
{
	POINTER_FUNC_GPT_TIMER0 = &LED_OFF(LED1);
}
 

 
 /********************************************************************************************************************
 *    END OF FILE: Project_LED.c
 ********************************************************************************************************************/
 