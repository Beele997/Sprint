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
 
#include "Std_types.h"
#include "Mcu_Hw.h"
#include "BIT_MATH.h"
#include "GPIO.h"

#include "LED_INTERFACE.h"

/********************************************************************************************************************
 *    GLOBAL FUNCTION
 ********************************************************************************************************************/
void LED_INIT(uint8 LED_Num)
{
	    switch(LED_Num)
		{
		case LED0:
		GPIO_InitPin(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_OUTPUT,GPIO_DIO_ENABLE,GPIO_8MA,GPIO_PULLUP);
		break;
		
		case LED1:
		GPIO_InitPin(GPIO_PORTF,GPIO_PIN2,GPIO_PIN_OUTPUT,GPIO_DIO_ENABLE,GPIO_8MA,GPIO_PULLUP);
		break;
		
		case LED2:
		GPIO_InitPin(GPIO_PORTF,GPIO_PIN3,GPIO_PIN_OUTPUT,GPIO_DIO_ENABLE,GPIO_8MA,GPIO_PULLUP);
		break;
		
		default:
		break;
		}
}

void LED_ON(uint8 LED_Num)
{
	LED_INIT(LED_Num);
	switch(LED_Num)
		{
		case LED0:
		GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_HIGH);
		break;
		
		case LED1:
	
		GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2,GPIO_PIN_HIGH);
		break;
		
		case LED2:

		GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN3,GPIO_PIN_HIGH);
		break;
		
		default:
		break;
		}
}

void LED_OFF(uint8 LED_Num)
{
	switch(LED_Num)
		{
		case LED0:

		GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_LOW);
		break;
		
		case LED1:

		GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2,GPIO_PIN_LOW);
		break;
		
		case LED2:
    
		GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN3,GPIO_PIN_LOW);
		break;
		
		default:
		break;
		}
}

  void LED_Toggle(uint8 LED_Num)
{
  uint32 count;
	switch(LED_Num)
		{
		case LED0:
		LED_ON(GPIO_PORTF);
    for(count=0;count<65000;count++)
    {
    }
    LED_OFF(GPIO_PORTF);
		break;
		
		case LED1:
		LED_ON(GPIO_PORTF);
    for(count=0;count<65000;count++)
    {
    }
    LED_OFF(GPIO_PORTF);
		break;
		
		case LED2:
		LED_ON(GPIO_PORTF);
    for(count=0;count<65000;count++)
    {
    }
    LED_OFF(GPIO_PORTF);
		break;
		
		default:
		break;
		}
}
 
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
 

