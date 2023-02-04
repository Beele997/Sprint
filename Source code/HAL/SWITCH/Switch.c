 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \Switch.c   
 *         
 *
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 
#include "Mcu_Hw.h"
#include "BIT_MATH.h"
#include "Std_types.h"

#include "GPIO.h"
#include "GPIO_Cfg.h"
#include "GPIO_Types.h"

#include "Switch.h"

/********************************************************************************************************************
 *    GLOBAL FUNCTION
 ********************************************************************************************************************/
uint8 GET_SWITCH(uint8 SwitchNum,uint8 GPIO_RESIS)
{
	static uint8 SwitchValue=0;
	switch(SwitchNum)
	{
		case SWITCH1:
		switch(GPIO_RESIS)
	  {
		case GPIO_PULLDOWN:
		GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN0,GPIO_PIN_INPUT);
		GPIO_SetPinResistance(GPIO_PORTF,GPIO_PIN0,GPIO_RESIS);
		SwitchValue = GPIO_GetPinValue(GPIO_PORTF,GPIO_PIN0);
		break;
		
		case GPIO_PULLUP:
		GPIO_SetPinDirection(GPIO_PORTF, GPIO_PIN0,GPIO_PIN_INPUT);
		GPIO_SetPinResistance(GPIO_PORTF,GPIO_PIN0,GPIO_RESIS);
		SwitchValue = GPIO_GetPinValue(GPIO_PORTF,GPIO_PIN0);
		break;
	  }
		break;
		
	  case SWITCH2:
			switch(GPIO_RESIS)
	  {
		case GPIO_PULLDOWN:
		GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_INPUT);
		GPIO_SetPinResistance(GPIO_PORTF,GPIO_PIN1,GPIO_RESIS);
		SwitchValue = GPIO_GetPinValue(GPIO_PORTF,GPIO_PIN1);
		break;
		
		case GPIO_PULLUP:
		GPIO_SetPinDirection(GPIO_PORTF, GPIO_PIN1,GPIO_PIN_INPUT);
		GPIO_SetPinResistance(GPIO_PORTF,GPIO_PIN1,GPIO_RESIS);
		SwitchValue = GPIO_GetPinValue(GPIO_PORTF,GPIO_PIN1);
		break;
	  }
	  break;
	}
	
	return SwitchValue;
}


 
 /********************************************************************************************************************
 *   \Syntax                  :  void S_Init(void)
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
 *    END OF FILE: Switch.c
 ********************************************************************************************************************/





