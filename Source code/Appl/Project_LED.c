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
 #include "Mcu_HW.h"
 #include "GPIO.h"
 #include "GPIO_Cfg.h"
 #include "GPIO_Types.h"
 #include "GPT.h"
 #include "GPT_Cfg.h"
 #include "GPT_Types.h"
 #include "LED_INTERFACE.h"
/********************************************************************************************************************/
 int main()
 {
	 IntCtrl_Init(Timer1A,UNDEFINED_EEXCEPTION,7);
	 u8 SwitchState = GET_SWITCH(PULL_UP,GPIO_PORTA,GPIO_PIN4,&SwitchState);
	 
	 uint32 u32_Counting_OPEN;
	 uint32 u32_Counting_CLOSE;
	 unit32 u32_wait;
	 while(1)
	 {
	     while (SwitchState == 1)
		 {
			 u32_Counting_OPEN++;
			 
		 }
		 
		 for(u32_wait=0;u32_wait<64000;u32_wait++)
		 {
		 }
		 
		 while (SwitchState == 1)
		 {
			 u32_Counting_CLOSE++;
			 
		 }
	 }
	 GPT_Init(GPT_TIMER_16_32BIT,GPT_Timer1,GPT_ENABLE_TIMER);
	 GPT_Init(GPT_TIMER_16_32BIT,GPT_Timer1,GPT_ENABLE_TIMER);
 }
 
 void GPT_timer1_SetCallBack(void(*POINTER_FUNC)(void))
{
	GPT_POINTER_CALLBACK_T1 = &LED_ON(LED0);
}
 
 void GPT_timer1_SetCallBack(void(*POINTER_FUNC)(void))
{
	GPT_POINTER_CALLBACK_T0 = &LED_OFF(LED1);
}
 
 
 
 
 
 
 
 
 
 /********************************************************************************************************************
 *    END OF FILE: Project_LED.c
 ********************************************************************************************************************/
 