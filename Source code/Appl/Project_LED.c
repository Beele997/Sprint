 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
 /**       \Project: Project_LED.c   
 *         \brief  :Interfacing TM4C123GH6PM Prephrals
 *   			 \details:Blinking Led from user by switch and timer
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
/********************************************************************************************************************
*       LOCAL FUNCTIONS PROTOTYPES																																									*
*********************************************************************************************************************/

static void LED_ON_FUNC(void);
static void LED_OFF_FUNC(void);
static void SWITCHFunc(void);


/********************************************************************************************************************
*       GLOBAL DATA               																																									*
*********************************************************************************************************************/
 static uint8* DesiredOffTime=0;
 static uint8* DesiredOnTime=0;
/********************************************************************************************************************
*        APPl                      																																									*
*********************************************************************************************************************/

int main(void)
 {
	 uint8 switchFlage=0;
	 /*Switch init*/
	 GPIO_InitPin(GPIO_PORTF,GPIO_PIN0,GPIO_PIN_INPUT,GPIO_DIO_ENABLE,GPIO_8MA,GPIO_PULLUP);
	 GPIO_InitPin(GPIO_PORTF,GPIO_PIN4,GPIO_PIN_INPUT,GPIO_DIO_ENABLE,GPIO_8MA,GPIO_PULLUP);
	 
	 /*LED init*/
	 LED_INIT(LED0);
	 
	 /*Interrupts init*/
	 IntCtrl_Init(Timer0A,UNDEFINED_EEXCEPTION,0x4,0x1,GR4_SUB2);
	 IntCtrl_Init(Timer1A,UNDEFINED_EEXCEPTION,0x4,0x1,GR4_SUB2);
	 IntCtrl_Init(GPIO_Port_F,UNDEFINED_EEXCEPTION,0x8,0x0,GR8_SUB0);
	 
	 /*Enable interrupts for the switches*/
	 GPIO_EnablePinInterrupt(GPIO_PORTF,GPIO_PIN0);
	 //GPIO_EnablePinInterrupt(GPIO_PORTF,GPIO_PIN4);
	 
	 /*Get the funcs back to Mcal(GPIO PortF)*/
	 GPIO_PORTF_SetCallBack(SWITCHFunc);
	 
	 /*Get the funcs back to Mcal (Timers)*/
	 GPT_timer1_SetCallBack(LED_OFF_FUNC);
	 GPT_timer0_SetCallBack(LED_ON_FUNC);
	 
	 /*Polling till press on switch 1 for declartion of on time*/
	 if(switchFlage==0)
	 {
		 while(GET_SWITCH(SWITCH1,PULL_UP)!=1);  /*Polling on switch till user press on the switch*/
		 switchFlage=1;
	 }
	 while(switchFlage==1)
	 {
		 break;
	 }
	 switchFlage=0;
	 /*Polling till press on switch 1 for declartion of on time*/
	 if(switchFlage==0)
	 {
		 while(GET_SWITCH(SWITCH1,PULL_UP)!=1);  /*Polling till press on the switch*/
		 switchFlage=1;
	 }
	 while(switchFlage==1)
	 {
		 break;
	 }
	 switchFlage=0;
	 
	 
		
		 
	 while(1)
	 {
		 GPT_Init(GPT_TIMER_16_32BIT,GPT_Timer0,GPT_ENABLE_TIMER,&DesiredOnTime);
		 GPT_Init(GPT_TIMER_16_32BIT,GPT_Timer1,GPT_ENABLE_TIMER,&DesiredOffTime);
		 
	 }
 }
void LED_ON_FUNC(void)
{
	LED_OFF(LED0);
}

void LED_OFF_FUNC(void)
{
	LED_ON(LED0);
}
 

void SWITCHFunc(void)
{
	static uint8 switch_triger=0;
	if(GET_BIT(GPIOMIS_F,0)==1)
	 {
		 
		 if(switch_triger==0||(switch_triger%2)==0)            /* On time decleratoin */
		 {
			 
			  *DesiredOnTime=0;
			 uint32 u32_idx;
			 for(u32_idx=0;u32_idx<160000000;u32_idx++)
			 {
			 if(GET_SWITCH(SWITCH2,GPIO_PULLUP)==1)
			 {
				 *DesiredOnTime++;
			 }
		   }
			 
		 }
		 else if((switch_triger%2)!=0)                         /* Off time decleratoin */
		 {
			 *DesiredOffTime=0;
			 uint32 u32_idx;
			 for(u32_idx=0;u32_idx<160000000;u32_idx++)
			 {
			 if(GET_SWITCH(SWITCH2,GPIO_PULLUP)==1)
			 {
				 *DesiredOffTime++;
			 }
		   }
		 }
	 }
	 switch_triger++;
	 
}
 /********************************************************************************************************************
 *    END OF FILE: Project_LED.c
 ********************************************************************************************************************/
 
 
 