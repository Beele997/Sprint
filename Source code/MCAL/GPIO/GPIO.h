 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \GPIO.h
 *         \GPIO   
 *
 *         \Header file for GPIO Module
 *
 ********************************************************************************************************************/
 #ifndef GPIO_H_
 #define GPIO_H_
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 #include "Std_types.h"
 
 
 #define GPIO_PORTA            0
 #define GPIO_PORTB            1
 #define GPIO_PORTC            2
 #define GPIO_PORTD            3
 #define GPIO_PORTE            4
 #define GPIO_PORTF            5
 
 #define GPIO_PIN0             0
 #define GPIO_PIN1             1
 #define GPIO_PIN2             2
 #define GPIO_PIN3             3
 #define GPIO_PIN4             4
 #define GPIO_PIN5             5
 #define GPIO_PIN6             6
 #define GPIO_PIN7             7
 
 #define GPIO_PORT_INPUT       0
 #define GPIO_PORT_OUTPUT      1
 
 #define GPIO_PIN_INPUT        0
 #define GPIO_PIN_OUTPUT       1        
 
 #define GPIO_PORT_LOW         0
 #define GPIO_PORT_HIGH        1
 
 #define GPIO_PIN_LOW          0
 #define GPIO_PIN_HIGH         1
 
 #define GPIO_2MA              0
 #define GPIO_4MA              1
 #define GPIO_8MA              2
 
 #define GPIO_PULLUP           0
 #define GPIO_PULLDOWN         1
 
 #define GPIO_DIO_ENABLE       1
 #define GPIO_DIO_DISABLE      0
 
 
 #define UART0                 0
 #define SSI0                  1
 #define I21C0                 2	
 
 
 
/********************************************************************************************************************
 *    LOCAL DATA
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    GLOBAL DATA
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    LOCAL FUNCTION PROTOTYPES
 ********************************************************************************************************************/


 
/********************************************************************************************************************
 *    GLOBAL FUNCTION PROTOTYPES
 ********************************************************************************************************************/
 void GPIO_Set_PortDirection(uint8 GPIO_PortType,uint8 GPIO_PortDir);
 void GPIO_SetPortValue(uint8 GPIO_PortType,uint8 GPIO_PortValue);
 void GPIO_EnDioPort(uint8 GPIO_PortType,uint8 GPIO_DIO);
 void GPIO_SetPortCurrent(uint8 GPIO_PortType,uint8 GPIO_Current);
 void GPIO_SetPortResistance(uint8 GPIO_PortType,uint8 GPIO_RESIS);
 void GPIO_InitPort(uint8 GPIO_PortType,uint8 GPIO_PortDir,uint8 GPIO_DIO,uint8 GPIO_Current,uint8 GPIO_RESIS);
 
 /*void GPIO_SetAltrFuncPort(uint8 FuncType);*/
 void GPIO_SetPinDirection(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_PinDir);
 void GPIO_SetPinValue(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_PinValue);
 void GPIO_SetPinResistance(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_RESIS);
 void GPIO_SetPinCurrent(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_Current);
 void GPIO_EnDioPin(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_DIO);
 uint8 GPIO_GetPinValue(uint8 GPIO_PortType,uint8 GPIO_PinNum);
 void GPIO_InitPin(uint8 GPIO_PortType,uint8 GPIO_PinNum,uint8 GPIO_PinDir,uint8 GPIO_DIO,uint8 GPIO_Current,uint8 GPIO_RESIS);
 /*Interrupt Handler*/
 void GPIO_PORTF_SetCallBack(void(*POINTER_FUNC)(void)) ;
 
void GPIO_EnablePinInterrupt(uint8 GPIO_PortType,uint8 GPIO_PinNum);
void GPIO_EnablePortInterrupt(uint8 GPIO_PortType);
 void GPIOF_Handler();
 
 
 #endif       /*GPIO.h*/
 /********************************************************************************************************************
 *    END OF FILE: GPIO.h	
 ********************************************************************************************************************/
 
 