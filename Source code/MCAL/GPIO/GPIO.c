 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \GPIO.c   
 *         \General Purpose Input Output Driver   
 *
 *         \The driver configure all MCU GPIO  
 *          Enable GPIO Gates for prepherals
 *
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 
 #include "Std_types.h"
 #include "BIT_MATH.h"
 #include "GPIO.h"
 #include "GPIO_Cfg.h"
 #include "GPIO_Types"
 #include "Mcu_HW.h"
 
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
  void(*GPIO_POINTER_CALLBACK_PORTF)(void)=NULL;
/********************************************************************************************************************
 *    LOCAL DATA
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    GLOBAL DATA
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    LOCAL FUNCTION
 ********************************************************************************************************************/
 static void GPIO_Set_Bus_Type(uint8 GPIO_PortType)
 {
 #ifdef GPIO_AHB
 switch(PortType)
 {
	 case GPIO_PORTA:
	 SET_BIT(GPIOHBCTL,0);
	 break;
	 
	 case GPIO_PORTB:
	 SET_BIT(GPIOHBCTL,1);
	 break;
	 
	 case GPIO_PORTC:
	 SET_BIT(GPIOHBCTL,2);
	 break;
	 
	 case GPIO_PORTD:
	 SET_BIT(GPIOHBCTL,3);
	 break;
	 
	 case GPIO_PORTE:
	 SET_BIT(GPIOHBCTL,4);
	 break;
	 
	 case GPIO_PORTF:
	 SET_BIT(GPIOHBCTL,5);
	 break;
 }
 
 #elif CHOSEN_BUS==APB_BUS
 switch(PortType)
 {
	 case GPIO_PORTA:
	 RESET_BIT(GPIOHBCTL,0);
	 break;
	 
	 case GPIO_PORTB:
	 RESET_BIT(GPIOHBCTL,1);
	 break;
	 
	 case GPIO_PORTC:
	 RESET_BIT(GPIOHBCTL,2);
	 break;
	 
	 case GPIO_PORTD:
	 RESET_BIT(GPIOHBCTL,3);
	 break;
	 
	 case GPIO_PORTE:
	 RESET_BIT(GPIOHBCTL,4);
	 break;
	 
	 case GPIO_PORTF:
	 RESET_BIT(GPIOHBCTL,5);
	 break;
 }
 #endif
 }
 
 static void GPIO_Enable_Clock(uint8 GPIO_PortType)
 {
		 switch(GPIO_PortType)
		 {
			 case GPIO_PORTA :
			 if(GPIO_PORTA_CL==OPEN)
			 {
				RCGCGPIO = 0x1;
			 }
			 else
			 {
				 RCGCGPIO = 0x0;
			 }
			 break;
			 
			 case GPIO_PORTB :
			 if(GPIO_PORTB_CL==OPEN)
			 {
				RCGCGPIO = (0x1<<1);
			 }
			 else
			 {
				 RCGCGPIO = (0x0<<1);
			 }
			 break;
			 
			 case GPIO_PORTC :
			 if(GPIO_PORTC_CL==OPEN)
			 {
				RCGCGPIO = (0x1<<2);
			 }
			 else
			 {
				 RCGCGPIO = (0x0<<2);
			 }
			 break;
			 
			 case GPIO_PORTD :
			 if(GPIO_PORTD_CL==OPEN)
			 {
				RCGCGPIO = (0x1<<3);
			 }
			 else
			 {
				 RCGCGPIO = (0x0<<3);
			 }
			 break;
			 
			 case GPIO_PORTE :
			 if(GPIO_PORTE_CL==OPEN)
			 {
				RCGCGPIO = (0x1<<4);
			 }
			 else
			 {
				 RCGCGPIO = (0x0<<4);
			 }
			 break;
			 
			 case GPIO_PORTF :
			 if(GPIO_PORTF_CL==OPEN)
			 {
				RCGCGPIO = (0x1<<5);
			 }
			 else
			 {
				 RCGCGPIO = (0x0<<5);
			 }
			 break;
			 
			 default:
			 //Warning
			 break;
		 }
 }

 
 
/********************************************************************************************************************
 *    GLOBAL FUNCTION
 ********************************************************************************************************************/
 
  void GPIO_Set_PortDirection(uint8 GPIO_PortType,uint8 GPIO_PortDir)
 {
	 switch(GPIO_PortType)
		 {
			 case GPIO_PORTA :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PortDir==GPIO_PORT_OUTPUT)
			 {
				GPIODIR_A = 0x255;
			 }
			 else if(GPIO_PortDir==GPIO_PORT_INPUT)
			 {
				 GPIODIR_A = 0x000;
			 }
			 break;
			 
			 case GPIO_PORTB :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PortDir==GPIO_PORT_OUTPUT)
			 {
				GPIODIR_B = 0x255;
			 }
			 else if(GPIO_PortDir==GPIO_PORT_INPUT)
			 {
				 GPIODIR_B = 0x000;
			 }
			 break;
			 
			 case GPIO_PORTC :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PortDir==GPIO_PORT_OUTPUT)
			 {
				GPIODIR_C = 0x255;
			 }
			 else if(GPIO_PortDir==GPIO_PORT_INPUT)
			 {
				 GPIODIR_C = 0x000;
			 }
			 break;
			 
			 case GPIO_PORTD :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PortDir==GPIO_PORT_OUTPUT)
			 {
				GPIODIR_D = 0x255;
			 }
			 else if(GPIO_PortDir==GPIO_PORT_INPUT)
			 {
				 GPIODIR_D = 0x000;
			 }
			 break;
			 
			 case GPIO_PORTE :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PortDir==GPIO_PORT_OUTPUT)
			 {
				GPIODIR_E = 0x255;
			 }
			 else if(GPIO_PortDir==GPIO_PORT_INPUT)
			 {
				 GPIODIR_E= 0x000;
			 }
			 break;
			 
			 case GPIO_PORTF :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PortDir==GPIO_PORT_OUTPUT)
			 {
				GPIODIR_F = 0x255;
			 }
			 else if(GPIO_PortDir==GPIO_PORT_INPUT)
			 {
				 GPIODIR_F = 0x000;
			 }
			 break;
			 
			 default:
			 //False
			 break;
			 
		 }
	 
 }
 
 void GPIO_SetPortValue(uint8 GPIO_PortType,uint8 GPIO_PortValue)
 {
	 switch(GPIO_PortType)
		 {
			 case GPIO_PORTA :
			 if(GPIO_PortValue==GPIO_PORT_HIGH)
			 {
				GPIODATA_A = 0x255;
			 }
			 else if(GPIO_PortValue==GPIO_PORT_LOW)
			 {
				 GPIODATA_A = 0x000;
			 }
			 break;
			 
			 case GPIO_PORTB :
			 if(GPIO_PortValue==GPIO_PORT_HIGH)
			 {
				GPIODATA_B = 0x255;
			 }
			 else if(GPIO_PortValue==GPIO_PORT_LOW)
			 {
				 GPIODATA_B = 0x000;
			 }
			 break;
			 
			 case GPIO_PORTC :
			 if(GPIO_PortValue==GPIO_PORT_HIGH)
			 {
				GPIODATA_C = 0x255;
			 }
			 else if(GPIO_PortValue==GPIO_PORT_LOW)
			 {
				 GPIODATA_C = 0x000;
			 }
			 break;
			 
			 case GPIO_PORTD :
			 if(GPIO_PortValue==GPIO_PORT_HIGH)
			 {
				GPIODATA_D = 0x255;
			 }
			 else if(GPIO_PortValue==GPIO_PORT_LOW)
			 {
				 GPIODATA_D = 0x000;
			 }
			 break;
			 
			 case GPIO_PORTE :
			 if(GPIO_PortValue==GPIO_PORT_HIGH)
			 {
				GPIODATA_E = 0x255;
			 }
			 else if(GPIO_PortValue==GPIO_PORT_LOW)
			 {
				 GPIODATA_E = 0x000;
			 }
			 break;
			 
			 case GPIO_PORTF :
			 if(GPIO_PortValue==GPIO_PORT_HIGH)
			 {
				GPIODATA_F = 0x255;
			 }
			 else if(GPIO_PortValue==GPIO_PORT_LOW)
			 {
				 GPIODATA_F = 0x000;
			 }
			 break;
			 
			 default:
			 //Warning
			 break;
			 
		 }
	 
 }
 
 void GPIO_EnDioPort(uint8 GPIO_PortType,uint8 GPIO_DIO)
 {
	 switch(GPIO_PortType)
		 {
			 case GPIO_PORTA :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				GPIODEN_A = 0x3F;
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 GPIODEN_A = 0x0;
			 }
			 break;
			 
			 case GPIO_PORTB :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				GPIODEN_B = 0x3F;
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 GPIODEN_B = 0x0;
			 }
			 break;
			 
			 case GPIO_PORTC :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				 GPIODEN_C = 0x3F;
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 GPIODEN_C = 0x0;
			 }
			 break;
			 
			 case GPIO_PORTD :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				GPIODEN_D = 0x3F;
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 GPIODEN_D = 0x0;
			 }
			 break;
			 
			 case GPIO_PORTE :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				GPIODEN_E = 0x3F;
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 GPIODEN_E = 0x0;
			 }
			 break;
			 
			 case GPIO_PORTF :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				GPIODEN_F = 0x3F;
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				GPIODEN_F = 0x0;
			 }
			 break;
			 
			 default:
			 //Warning
			 break;
			 
		 }
 }
 
 /*void GPIO_SetAltrFuncPort(uint8 FuncType)
 {
	 switch(FuncType)
	 {
		 case UART0;
	 }
 }*/
 
 void GPIO_SetPinDirection(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_PinDir)
 {
	 switch(GPIO_PortType)
		 {
			 case GPIO_PORTA :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PinDir==GPIO_PIN_OUTPUT)
			 {
				SET_BIT(GPIODIR_A,GPIO_PinNum);
			 }
			 else if(GPIO_PinDir==GPIO_PIN_INPUT)
			 {
				 RESET_BIT(GPIODIR_A,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTB :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PinDir==GPIO_PIN_OUTPUT)
			 {
				SET_BIT(GPIODIR_B,GPIO_PinNum);
			 }
			 else if(GPIO_PinDir==GPIO_PIN_INPUT)
			 {
				 RESET_BIT(GPIODIR_B,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTC :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PinDir==GPIO_PIN_OUTPUT)
			 {
				SET_BIT(GPIODIR_C,GPIO_PinNum);
			 }
			 else if(GPIO_PinDir==GPIO_PIN_INPUT)
			 {
				 RESET_BIT(GPIODIR_C,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTD :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PinDir==GPIO_PIN_OUTPUT)
			 {
				SET_BIT(GPIODIR_D,GPIO_PinNum);
			 }
			 else if(GPIO_PinDir==GPIO_PIN_INPUT)
			 {
				 RESET_BIT(GPIODIR_D,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTE :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PinDir==GPIO_PIN_OUTPUT)
			 {
				SET_BIT(GPIODIR_E,GPIO_PinNum);
			 }
			 else if(GPIO_PinDir==GPIO_PIN_INPUT)
			 {
				 RESET_BIT(GPIODIR_E,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTF :
			 GPIO_Set_Bus_Type(GPIO_PortType);
			 GPIO_Enable_Clock(GPIO_PortType);
			 if(GPIO_PinDir==GPIO_PIN_OUTPUT)
			 {
				SET_BIT(GPIODIR_F,GPIO_PinNum);
			 }
			 else if(GPIO_PinDir==GPIO_PIN_INPUT)
			 {
				RESET_BIT(GPIODIR_F,GPIO_PinNum);
			 }
			 break;
			 
			 default:
			 //Warning
			 break;
			 
		 }
	 
 }
 
 void GPIO_SetPinValue(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_PinValue)
 {
	 switch(GPIO_PortType)
		 {
			 case GPIO_PORTA :
			 if(GPIO_PinValue==GPIO_PIN_HIGH)
			 {
				SET_BIT(GPIODATA_A,GPIO_PinNum);
			 }
			 else if(GPIO_PinValue==GPIO_PIN_LOW)
			 {
				 RESET_BIT(GPIODATA_A,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTB :
			 if(GPIO_PinValue==GPIO_PIN_HIGH)
			 {
				SET_BIT(GPIODATA_B,GPIO_PinNum);
			 }
			 else if(GPIO_PinValue==GPIO_PIN_LOW)
			 {
				 RESET_BIT(GPIODATA_B,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTC :
			 if(GPIO_PinValue==GPIO_PIN_HIGH)
			 {
				SET_BIT(GPIODATA_C,GPIO_PinNum);
			 }
			 else if(GPIO_PinValue==GPIO_PIN_LOW)
			 {
				 RESET_BIT(GPIODATA_C,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTD :
			 if(GPIO_PinValue==GPIO_PIN_HIGH)
			 {
				SET_BIT(GPIODATA_D,GPIO_PinNum);
			 }
			 else if(GPIO_PinValue==GPIO_PIN_LOW)
			 {
				 RESET_BIT(GPIODATA_D,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTE :
			 if(GPIO_PinValue==GPIO_PIN_HIGH)
			 {
				SET_BIT(GPIODATA_E,GPIO_PinNum);
			 }
			 else if(GPIO_PinValue==GPIO_PIN_LOW)
			 {
				 RESET_BIT(GPIODATA_E,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTF :
			 if(GPIO_PinValue==GPIO_PIN_HIGH)
			 {
				SET_BIT(GPIODATA_F,GPIO_PinNum);
			 }
			 else if(GPIO_PinValue==GPIO_PIN_LOW)
			 {
				RESET_BIT(GPIODATA_F,GPIO_PinNum);
			 }
			 break;
			 
			 default:
			 //Warning
			 break;
			 
		 }
 }
 
 void GPIO_GetPinValue(uint8 PortId,uint8 PinId,uint8* PinValue)
{
	switch(PortId)
	{
		case GPIO_PORTA:
		if( 1 ==GET_BIT(GPIO_PORTA,PinId))
		{
			*PinValue = GPIO_PIN_HIGH;
		}
		else
		{
			*PinValue = GPIO_PIN_LOW;
		}
		break;
		
		case GPIO_PORTB:
		if( 1 ==GET_BIT(GPIO_PORTB,PinId))
		{
			*PinValue = GPIO_PIN_HIGH;
		}
		else
		{
			*PinValue = GPIO_PIN_LOW;
		}
		break;
		
		case GPIO_PORTC:
		if( 1 ==GET_BIT(GPIO_PORTC,PinId))
		{
			*PinValue = GPIO_PIN_HIGH;
		}
		else
		{
			*PinValue = GPIO_PIN_LOW;
		}
		break;
		
		case GPIO_PORTD:
		if( 1 ==GET_BIT(GPIO_PORTD,PinId))
		{
			*PinValue = GPIO_PIN_HIGH;
		}
		else
		{
			*PinValue = GPIO_PIN_LOW;
		}
		break;
	}
}

 void GPIO_SetPinResistance(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_RESIS)
 {
	 switch(GPIO_PortType)
	 {
	 case GPIO_PORTA:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 SET_BIT(GPIOPUR_A,GPIO_PinNum);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 SET_BIT(GPIOPDR_A,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTB:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 SET_BIT(GPIOPUR_B,GPIO_PinNum);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 SET_BIT(GPIOPDR_B,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTC:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 SET_BIT(GPIOPUR_C,GPIO_PinNum);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 SET_BIT(GPIOPDR_C,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTD:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 SET_BIT(GPIOPUR_D,GPIO_PinNum);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 SET_BIT(GPIOPDR_D,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTE:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 SET_BIT(GPIOPUR_E,GPIO_PinNum);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 SET_BIT(GPIOPDR_E,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTF:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 SET_BIT(GPIOPUR_F,GPIO_PinNum);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 SET_BIT(GPIOPDR_F,GPIO_PinNum);
	 }
	 break;
	 
	 default:
	 //Warning
	 break;
	 }
	  
 }
 
 void GPIO_SetPinCurrent(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_Current)
 {
	 switch(GPIO_PortType)
	 {
	 case GPIO_PORTA:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 SET_BIT(GPIODR2R_A,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 SET_BIT(GPIODR4R_A,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 SET_BIT(GPIODR8R_A,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTB:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 SET_BIT(GPIODR2R_B,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 SET_BIT(GPIODR4R_B,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 SET_BIT(GPIODR8R_B,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTC:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 SET_BIT(GPIODR2R_C,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 SET_BIT(GPIODR4R_C,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 SET_BIT(GPIODR8R_C,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTD:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 SET_BIT(GPIODR2R_D,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 SET_BIT(GPIODR4R_D,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 SET_BIT(GPIODR8R_D,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTE:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 SET_BIT(GPIODR2R_E,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 SET_BIT(GPIODR4R_E,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 SET_BIT(GPIODR8R_E,GPIO_PinNum);
	 }
	 break;
	 
	 case GPIO_PORTF:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 SET_BIT(GPIODR2R_F,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 SET_BIT(GPIODR4R_F,GPIO_PinNum);
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 SET_BIT(GPIODR8R_F,GPIO_PinNum);
	 }
	 break;
	 
	 default:
	 //Warning
	 break;
	 }
 }
 
 
 

 
 void GPIO_EnDioPin(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_DIO)
 {
	 switch(GPIO_PortType)
		 {
			 case GPIO_PORTA :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				SET_BIT(GPIODEN_A,GPIO_PinNum);
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 RESET_BIT(GPIODEN_A,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTB :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				SET_BIT(GPIODEN_B,GPIO_PinNum);
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 RESET_BIT(GPIODEN_B,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTC :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				SET_BIT(GPIODEN_C,GPIO_PinNum);
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 RESET_BIT(GPIODEN_C,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTD :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				SET_BIT(GPIODEN_D,GPIO_PinNum);
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 RESET_BIT(GPIODEN_D,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTE :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				SET_BIT(GPIODEN_E,GPIO_PinNum);
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				 RESET_BIT(GPIODEN_E,GPIO_PinNum);
			 }
			 break;
			 
			 case GPIO_PORTF :
			 if(GPIO_DIO==GPIO_DIO_ENABLE)
			 {
				SET_BIT(GPIODEN_F,GPIO_PinNum);
			 }
			 else if(GPIO_DIO==GPIO_DIO_DISABLE)
			 {
				RESET_BIT(GPIODEN_F,GPIO_PinNum);
			 }
			 break;
			 
			 default:
			 //Warning
			 break;
			 
		 }
 }
 
 void GPIO_PORTF_SetCallBack(void(*POINTER_FUNC)(void))
{
	GPIO_POINTER_CALLBACK_PORTF = POINTER_FUNC;
}
 
 void GPIOF_Handler()
 {
	 GPIO_PORTF_SetCallBack();
 } 
 /********************************************************************************************************************
 *   \Syntax                  :  void GPIO_Init(void)
 *   \Description             :  Intialization GPIO Module by parsing the configuration
 *                               into GPIO registers
 *
 *   \Sync\Async              :  Synchronous
 *   \Reentrancy              :  Non Reentrant
 *   \Parameters (in)         :  Parameter Name  Parameter Description
 *   \Parameters (out)        :  None
 *   \Return value            :  Std_ReturnType  E_OK
 *                                               E_NOT_OK
 ********************************************************************************************************************/
 
 /********************************************************************************************************************
 *    END OF FILE: GPIO.c
 ********************************************************************************************************************/