/***********************************************************************************************************************
 *   \date 	  : 06.02.2023          
 *   \name 	  : Ahmed Elebaby       
 *	 \version : 1.0              
 *	 \SWC     : DIO driver          
 *   \brief   : Header file of GPIO MCAL module.
************************************************************************************************************************/
#ifndef __MCAL_GPIO_H__
#define __MCAL_GPIO_H__


/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 #include <stdint.h>
 

 
 
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
/*Pin Macros*/
#define GPIO_PIN_0 ((uint16_t)0x0001) /* Pin 0 selected    */
#define GPIO_PIN_1 ((uint16_t)0x0002) /* Pin 1 selected    */
#define GPIO_PIN_2 ((uint16_t)0x0004) /* Pin 2 selected    */
#define GPIO_PIN_3 ((uint16_t)0x0008) /* Pin 3 selected    */
#define GPIO_PIN_4 ((uint16_t)0x0010) /* Pin 4 selected    */
#define GPIO_PIN_5 ((uint16_t)0x0020) /* Pin 5 selected    */
#define GPIO_PIN_6 ((uint16_t)0x0040) /* Pin 6 selected    */
#define GPIO_PIN_7 ((uint16_t)0x0080) /* Pin 7 selected    */
/*Port Macros*/
#define GPIO_PORTA ((uint16_t)0x0001) /* PORT A selected    */
#define GPIO_PORTB ((uint16_t)0x0002) /* PORT B selected    */
#define GPIO_PORTC ((uint16_t)0x0004) /* PORT C selected    */
#define GPIO_PORTD ((uint16_t)0x0008) /* PORT D selected    */
#define GPIO_PORTE ((uint16_t)0x0010) /* PORT E selected    */
#define GPIO_PORTF ((uint16_t)0x0020) /* PORT F selected    */

/********************************************************************************************************************
 *    LOCAL DATA & DATA STRUCTURE
 ********************************************************************************************************************/
typedef enum
{
	
    PIN_RESET = 0, /*PIN in low*/
    PIN_SET   = 1  /*PIN in hogh*/

} GPIO_PinState;

typedef struct
{
    uint16_t Port; /* Specifies the GPIO Port to be configured.*/

    uint16_t Pin; /* Specifies the GPIO pins to be configured*/

    uint32_t Pull; /*Specifies the Pull-up or Pull-Down activation for the selected pins*/

    uint32_t Alternate; /*Peripheral to be connected to the selected pins*/
} GPIO_Init_Config;


/********************************************************************************************************************
 *    GLOBAL DATA
 ********************************************************************************************************************/

/********************************************************************************************************************
 *    LOCAL FUNCTION PROTOTYPES
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    LOCAL FUNCTION
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    GLOBAL FUNCTION
 ********************************************************************************************************************/
 /*Initialize the GPIO
 @ to init the congigured pins
 */
void GPIO_Init(GPIO_Init_Config *pstr_Init);

/*Control functions 
 @APIs to read,write and toggle pins on the ports
*/
GPIO_PinState GPIO_ReadPin(uint16_t *GPIOx, uint16_t GPIO_Pin);
void GPIO_WritePin(uint16_t GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void GPIO_TogglePin(uint16_t GPIOx, uint16_t GPIO_Pin);

/*Callack functions*/
void GPIO_EXTI_CallbackSet(uint16_t GPIOx,uint16_t GPIO_Pin,void (*EXTI_Callback)(void));
#endif /*End of file GPIO file*/