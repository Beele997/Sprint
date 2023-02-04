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
 #include "Mcu_Hw.h"
 
 #include "GPIO.h"
 #include "GPIO_Cfg.h"
 #include "GPIO_Types.h"
 
 
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 static void GPIO_Set_Bus_Type(uint8 GPIO_PortType);
 static void GPIO_Enable_Clock(uint8 GPIO_PortType);
 void GPIOF_Handler(void);
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
 /* Used for the simulation 0x40000000, 0x400FFFFF*/
 
 static void GPIO_Set_Bus_Type(uint8 GPIO_PortType)
 {
 #ifdef GPIO_AHB 
 switch(GPIO_PortType)
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
 
 #elif GPIO_APB
 switch(GPIO_PortType)
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
				SET_BIT(RCGCGPIO,0);
			 }
			 else
			 {
				 RESET_BIT(RCGCGPIO,0);
			 }
			 break;
			 
			 case GPIO_PORTB :
			 if(GPIO_PORTB_CL==OPEN)
			 {
				SET_BIT(RCGCGPIO,1);
			 }
			 else
			 {
				 RESET_BIT(RCGCGPIO,1);
			 }
			 break;
			 
			 case GPIO_PORTC :
			 if(GPIO_PORTC_CL==OPEN)
			 {
				SET_BIT(RCGCGPIO,2);
			 }
			 else
			 {
				 RESET_BIT(RCGCGPIO,2);
			 }
			 break;
			 
			 case GPIO_PORTD :
			 if(GPIO_PORTD_CL==OPEN)
			 {
				SET_BIT(RCGCGPIO,3);
			 }
			 else
			 {
				 RESET_BIT(RCGCGPIO,3);
			 }
			 break;
			 
			 case GPIO_PORTE :
			 if(GPIO_PORTE_CL==OPEN)
			 {
				SET_BIT(RCGCGPIO,4);
			 }
			 else
			 {
				 RESET_BIT(RCGCGPIO,4);
			 }
			 break;
			 
			 case GPIO_PORTF :
			 if(GPIO_PORTF_CL==OPEN)
			 {
				SET_BIT(RCGCGPIO,5);
			 }
			 else
			 {
				 RESET_BIT(RCGCGPIO,5);
			 }
			 break;
			 
			 default: 
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
			 GPIOLOCK_F = 0x4C4F434B;                                        /* unlock commit register */
			 GPIOCR_F = 0x01;                                               /* make PORTF0 configurable */
			 GPIOLOCK_F = 0; 
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
				GPIODATA_F = 0xFF;
			 }
			 else if(GPIO_PortValue==GPIO_PORT_LOW)
			 {
				 GPIODATA_F = 0x000;
			 }
			 break;
			 
			 default:
			 break;
			 
		 }
	 
 }
 
 void GPIO_EnDioPort(uint8 GPIO_PortType,uint8 GPIO_DIO)
 {
	 
	 switch(GPIO_PortType)
		 {
			 case GPIO_PORTA :
			 GPIOAFSEL_A = 0x0000;
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
			 GPIOAFSEL_B = 0x0000;
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
			 GPIOAFSEL_C = 0x0000;
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
			 GPIOAFSEL_D = 0x0000;
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
			 GPIOAFSEL_E = 0x0000;
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
			 GPIOAFSEL_F = 0x0000;
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
			 break;
			 
		 }
 }
 
 void GPIO_SetPortCurrent(uint8 GPIO_PortType,uint8 GPIO_Current)
 {
	 switch(GPIO_PortType) 
	 {
	 case GPIO_PORTA:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 GPIODR2R_A = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
	   GPIODR4R_A = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 GPIODR8R_A = 0xFF;
	 }
	 break;
	 
	 case GPIO_PORTB:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 GPIODR2R_B = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 GPIODR4R_B = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 GPIODR8R_B = 0xFF;
	 }
	 break;
	 
	 case GPIO_PORTC:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 GPIODR2R_C = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 GPIODR4R_C = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 GPIODR8R_C = 0xFF;
	 }
	 break;
	 
	 case GPIO_PORTD:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 GPIODR2R_D = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 GPIODR4R_D = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 GPIODR8R_D = 0xFF;
	 }
	 break;
	 
	 case GPIO_PORTE:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 GPIODR2R_E = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 GPIODR4R_E = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 GPIODR8R_E = 0xFF;
	 }
	 break;
	 
	 case GPIO_PORTF:
	 if(GPIO_Current==GPIO_2MA)
	 {
		 GPIODR2R_F = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_4MA)
	 {
		 GPIODR4R_F = 0xFF;
	 }
	 else if(GPIO_Current==GPIO_8MA)
	 {
		 GPIODR8R_F = 0xFF;
	 }
	 break;
	 
	 default:
	 break;
	 }
 }
 
 void GPIO_SetPortResistance(uint8 GPIO_PortType,uint8 GPIO_RESIS)
 {
	 switch(GPIO_PortType)
	 {
	 case GPIO_PORTA:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		GPIOPUR_A=(0xFF<<0);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		GPIOPDR_A=(0xFF<<0);
	 }
	 break;
	 
	 case GPIO_PORTB:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 GPIOPUR_B=(0xFF<<0);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 GPIOPDR_B =(0xFF<<0);
	 }
	 break;
	 
	 case GPIO_PORTC:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 GPIOPUR_C =(0xFF<<0);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 GPIOPDR_C = (0xFF<<0);
	 }
	 break;
	 
	 case GPIO_PORTD:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 GPIOPUR_D =(0xFF<<0);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 GPIOPDR_D =(0xFF<<0);
	 }
	 break;
	 
	 case GPIO_PORTE:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 GPIOPUR_E =(0xFF<<0);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 GPIOPDR_E =(0xFF<<0);
	 }
	 break;
	 
	 case GPIO_PORTF:
	 if(GPIO_RESIS==GPIO_PULLUP)
	 {
		 GPIOPUR_F =(0xFF<<0);
	 }
	 else if(GPIO_RESIS==GPIO_PULLDOWN)
	 {
		 GPIOPDR_F =(0xFF<<0);
	 }
	 break;
	 
	 default:
	 break;
	 }
 }
 
 void GPIO_InitPort(uint8 GPIO_PortType,uint8 GPIO_PortDir,uint8 GPIO_DIO,uint8 GPIO_Current,uint8 GPIO_RESIS)
 { 
	
			 GPIO_Set_PortDirection(GPIO_PortType,GPIO_PortDir);
	     switch(GPIO_PortType)
		   {
			 case GPIO_PORTA : 
			 GPIOAFSEL_A = 0x0000;
			 break;
			 
			 case GPIO_PORTB :
			 GPIOAFSEL_B = 0x0000;
			 break;
			 
			 case GPIO_PORTC :
			 GPIOAFSEL_C = 0x0000;
			 break;
			 
			 case GPIO_PORTD :
			 GPIOAFSEL_D = 0x0000;
			 break;
			 
			 case GPIO_PORTE :
			 GPIOAFSEL_E = 0x0000;
			 break;
			 
			 case GPIO_PORTF :
			 GPIOAFSEL_F = 0x0000;
			 break;
			 
			 default:
			 break;
		 }
			 GPIO_SetPortCurrent(GPIO_PortType,GPIO_Current);
	     GPIO_SetPortResistance(GPIO_PortType,GPIO_RESIS);
		   GPIO_EnDioPort(GPIO_PortType,GPIO_DIO);
}
 
void GPIO_EnablePortInterrupt(uint8 GPIO_PortType)
{
	     switch(GPIO_PortType)
		   {
			 case GPIO_PORTA :
			 GPIOIM_A |= 0xFF;
			 GPIOIS_A |= 0xFF;
			 GPIOIEV_A|= 0xFF;
			 GPIOIBE_A|= 0xFF;
			 break;
			 
			 case GPIO_PORTB :
			 GPIOIM_B |= 0xFF;
			 GPIOIS_B |= 0xFF;
			 GPIOIEV_B|= 0xFF;
			 GPIOIBE_B|= 0xFF;
			 break;
			 
			 case GPIO_PORTC :
			 GPIOIM_C |= 0xFF;
			 GPIOIS_C |= 0xFF;
			 GPIOIEV_C|= 0xFF;
			 GPIOIBE_C|= 0xFF;
			 break;
			 
			 case GPIO_PORTD :
			 GPIOIM_D |= 0xFF;
			 GPIOIS_D |= 0xFF;
			 GPIOIEV_D|= 0xFF;
			 GPIOIBE_D|= 0xFF;
			 break;
			 
			 case GPIO_PORTE :
			 GPIOIM_E |= 0xFF;
			 GPIOIS_E |= 0xFF;
			 GPIOIEV_E|= 0xFF;
			 GPIOIBE_E|= 0xFF;
			 break;
			 
			 case GPIO_PORTF :
			 GPIOIM_F |= 0xFF;
			 GPIOIS_F |= 0xFF;
			 GPIOIEV_F|= 0xFF;
			 GPIOIBE_F|= 0xFF;
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
			 break;
			 
		 }
 }
 
 uint8 GPIO_GetPinValue(uint8 PortId,uint8 PinId)
{
	static uint8 PinValue=0;
	switch(PortId)
	{
		case GPIO_PORTA:
		if( 1 ==GET_BIT(GPIO_PORTA,PinId))
		{
			PinValue = GPIO_PIN_HIGH;
		}
		else
		{
			PinValue = GPIO_PIN_LOW;
		}
		break;
		
		case GPIO_PORTB:
		if( 1 ==GET_BIT(GPIO_PORTB,PinId))
		{
			PinValue = GPIO_PIN_HIGH;
		}
		else
		{
			PinValue = GPIO_PIN_LOW;
		}
		break;
		
		case GPIO_PORTC:
		if( 1 ==GET_BIT(GPIO_PORTC,PinId))
		{
			PinValue = GPIO_PIN_HIGH;
		}
		else
		{
			PinValue = GPIO_PIN_LOW;
		}
		break;
		
		case GPIO_PORTD:
		if( 1 ==GET_BIT(GPIO_PORTD,PinId))
		{
			PinValue = GPIO_PIN_HIGH;
		}
		else
		{
			PinValue = GPIO_PIN_LOW;
		}
		break;
	}
	return PinValue; 
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
			 break;
			 
		 }
 }
 
void GPIO_InitPin(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_PinDir,uint8 GPIO_DIO,uint8 GPIO_Current,uint8 GPIO_RESIS)
{
	GPIO_SetPinDirection(GPIO_PortType,GPIO_PinNum,GPIO_PinDir);
	     switch(GPIO_PortType)
		   {
			 case GPIO_PORTA : 
			 GPIOAFSEL_A = 0x0000;
			 break;
			 
			 case GPIO_PORTB :
			 GPIOAFSEL_B = 0x0000;
			 break;
			 
			 case GPIO_PORTC :
			 GPIOAFSEL_C = 0x0000;
			 break;
			 
			 case GPIO_PORTD :
			 GPIOAFSEL_D = 0x0000;
			 break;
			 
			 case GPIO_PORTE :
			 GPIOAFSEL_E = 0x0000;
			 break;
			 
			 case GPIO_PORTF :
			 GPIOAFSEL_F = 0x0000;
			 break;
			 
			 default:
			 break;
		 }
			 GPIO_SetPinCurrent(GPIO_PortType,GPIO_PinNum,GPIO_Current);
	     GPIO_SetPinResistance(GPIO_PortType,GPIO_PinNum,GPIO_RESIS);
		   GPIO_EnDioPin(GPIO_PortType,GPIO_PinNum,GPIO_DIO);
}

void GPIO_EnablePinInterrupt(uint8 GPIO_PortType,uint8 GPIO_PinNum)
{
	     switch(GPIO_PortType)
		   {
			 case GPIO_PORTA :
			 GPIOIS_A |= (1<<GPIO_PinNum);
			 GPIOIBE_A |= (1<<GPIO_PinNum);
			 GPIOIEV_A|= (1<<GPIO_PinNum);
			 GPIOICR_A|= (1<<GPIO_PinNum);
			 GPIOIM_E|= (1<<GPIO_PinNum);
			 break;
			 
			 case GPIO_PORTB :
			 GPIOIS_B |= (1<<GPIO_PinNum);
			 GPIOIBE_B |= (1<<GPIO_PinNum);
			 GPIOIEV_B|= (1<<GPIO_PinNum);
			 GPIOICR_B|= (1<<GPIO_PinNum);
			 GPIOIM_B|= (1<<GPIO_PinNum);
			 break;
			 
			 case GPIO_PORTC :
			 GPIOIS_C |= (1<<GPIO_PinNum);
			 GPIOIBE_C |= (1<<GPIO_PinNum);
			 GPIOIEV_C|= (1<<GPIO_PinNum);
			 GPIOICR_C|= (1<<GPIO_PinNum);
			 GPIOIM_C|= (1<<GPIO_PinNum);
			 break;
			 
			 case GPIO_PORTD :
			 GPIOIS_D |= (1<<GPIO_PinNum);
			 GPIOIBE_D |= (1<<GPIO_PinNum);
			 GPIOIEV_D|= (1<<GPIO_PinNum);
			 GPIOICR_D|= (1<<GPIO_PinNum);
			 GPIOIM_D|= (1<<GPIO_PinNum);
			 break;
			 
			 case GPIO_PORTE :
			 GPIOIS_E |= (1<<GPIO_PinNum);
			 GPIOIBE_E |= (1<<GPIO_PinNum);
			 GPIOIEV_E|= (1<<GPIO_PinNum);
			 GPIOICR_E|= (1<<GPIO_PinNum);
			 GPIOIM_E|= (1<<GPIO_PinNum);
			 break;
			 
			 case GPIO_PORTF :
			
			 GPIOIS_F |= (1<<GPIO_PinNum);
			 GPIOIBE_F|= (1<<GPIO_PinNum);
			 GPIOIEV_F|= (1<<GPIO_PinNum);
			 GPIOICR_F |= (1<<GPIO_PinNum);                                           
			 GPIOIM_F |= (1<<GPIO_PinNum);
			 break;
		 }
}



void GPIO_PORTF_SetCallBack(void(*POINTER_FUNC)(void))
{
	GPIO_POINTER_CALLBACK_PORTF = POINTER_FUNC;
}

void GPIOF_Handler(void)
{
	 GPIO_POINTER_CALLBACK_PORTF();
	 SET_BIT(GPIOICR_F,0); 
}
