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
#include "SWITCH.h"
/********************************************************************************************************************
 *    GLOBAL FUNCTION
 ********************************************************************************************************************/
void GET_SWITCH(u8 PULL_TYPE,u8 PortId,u8 PinId,u8* SwitchValue)
{
	u8 SwitchState;
	switch(PULL_TYPE)
	{
		case PULL_DOWN:
		DIO_setPinDirection(PortId,PinId,GPIO_PIN_INPUT);
		DIO_getPinValue(PortId,PinId,&SwitchState);
		break;
		
		case PULL_UP:
		DIO_setPinDirection(PortId,PinId,GPIO_PIN_INPUT);
		DIO_setInputPinResistance(PortId,PinId);
		DIO_getPinValue(PortId,PinId,&SwitchState);
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





