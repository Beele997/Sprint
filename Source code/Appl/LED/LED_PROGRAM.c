 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \LED.c   
 *            
 *
 *
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 
#include "STD_TYPES.h"
#include "Mcu_Hw.h"
#include "BIT_MATH.h"
#include "GPIO.h"

#include "LED_INTERFACE.h"

/********************************************************************************************************************
 *    GLOBAL FUNCTION
 ********************************************************************************************************************/
void LED_INIT(u8 LED_Num)
{
	    switch(LED_Num)
		{
		case LED0:
		GPIO_Set_PortDirection(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_OUTPUT);
		break;
		
		case LED1:
		GPIO_Set_PortDirection(GPIO_PORTF,GPIO_PIN2,GPIO_PIN_OUTPUT);
		break;
		
		case LED2:
		GPIO_Set_PortDirection(GPIO_PORTF,GPIO_PIN3,GPIO_PIN_OUTPUT);
		break;
		
		default:
		break
		}
}

void LED_ON(u8 LED_Num)
{
	switch(LED_Num)
		{
		case LED0:
		LED_INIT(u8 LED_Num);
		GPIO_SetPortValue(GPIO_PORTF,GPIO_PIN3,GPIO_PORT_HIGH);
		break;
		
		case LED1:
		LED_INIT(u8 LED_Num);
		GPIO_SetPortValue(GPIO_PORTF,GPIO_PIN3,GPIO_PORT_HIGH);
		break;
		
		case LED2:
		LED_INIT(u8 LED_Num);
		GPIO_SetPortValue(GPIO_PORTF,GPIO_PIN3,GPIO_PORT_HIGH);
		break;
		
		default:
		break
		}
}

void LED_OFF(u8 LED_Num)
{
	switch(LED_Num)
		{
		case LED0:
		LED_INIT(u8 LED_Num);
		GPIO_SetPortValue(GPIO_PORTF,GPIO_PIN3,GPIO_PORT_LOW);
		break;
		
		case LED1:
		LED_INIT(u8 LED_Num);
		GPIO_SetPortValue(GPIO_PORTF,GPIO_PIN3,GPIO_PORT_LOW);
		break;
		
		case LED2:
		LED_INIT(u8 LED_Num);
		GPIO_SetPortValue(GPIO_PORTF,GPIO_PIN3,GPIO_PORT_LOW);
		break;
		
		default:
		break
		}
}

/*void LED_Toggle(u8 LED_Num)
{
	switch(LED_Num)
		{
		case LED0:
		GPIO_Set_PortDirection(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_OUTPUT);
		break;
		
		case LED1:
		GPIO_Set_PortDirection(GPIO_PORTF,GPIO_PIN2,GPIO_PIN_OUTPUT);
		break;
		
		case LED2:
		GPIO_Set_PortDirection(GPIO_PORTF,GPIO_PIN3,GPIO_PIN_OUTPUT);
		break;
		
		default:
		break
		}
}*/
 
 /********************************************************************************************************************
 *   \Syntax                  :  void LED_Init(void)
 *   \Description             : 
 *
 *   \Sync\Async              :  Synchronous
 *   \Reentrancy              :  Non Reentrant
 *   \Parameters (in)         :  Parameter Name  Parameter Description
 *   \Parameters (out)        :  None
 *   \Return value            :  Std_ReturnType  E_OK
 *                                               E_NOT_OK
 ********************************************************************************************************************/
 
 /********************************************************************************************************************
 *    END OF FILE: LED_PROGRAM.c
 ********************************************************************************************************************/
//UTILS
