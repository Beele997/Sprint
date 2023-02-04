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
#include "Switch.h"

/********************************************************************************************************************
 *    GLOBAL FUNCTION
 ********************************************************************************************************************/
void GET_SWITCH(uint8 GPIO_RESIS,uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8* SwitchValue)
{
	uint8 SwitchState;
	switch(GPIO_RESIS)
	{
		case GPIO_PULLDOWN:
		GPIO_SetPinDirection(GPIO_PortType,GPIO_PinNum,GPIO_PIN_INPUT);
		GPIO_SetPinResistance(GPIO_PortType,GPIO_PinNum,GPIO_RESIS);
		GPIO_GetPinValue(GPIO_PortType,GPIO_PinNum,&SwitchState);
		break;
		
		case GPIO_PULLUP:
		GPIO_SetPinDirection(GPIO_PortType, GPIO_PinNum,GPIO_PIN_INPUT);
		GPIO_SetPinResistance( GPIO_PortType,GPIO_PinNum,GPIO_RESIS);
		GPIO_GetPinValue(GPIO_PortType,GPIO_PinNum,&SwitchState);
		break;
	}
	*SwitchValue = SwitchState;
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
 *    END OF FILE: LSwitch.c
 ********************************************************************************************************************/





