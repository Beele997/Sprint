/***********************************************************************************************************************
 *   \date 	 : 06.02.2023          
 *   \name 	 : Ahmed Elebaby       
 *	 \version : 1.0              
 *	 \SWC     : CAN bus driver          
 *   \brief   : header file for CAN Bus driver
************************************************************************************************************************/
#ifndef __MCAL_CAN_H__
#define __MCAL_CAN_H__


/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 #include <stdint.h>
 

 
 
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 #define CAN_BAUD_RATE 500000  				/*Macro to set the baud rate of CAN*/
/********************************************************************************************************************
 *    LOCAL DATA & DATA STRUCTURE
 ********************************************************************************************************************/
/*Configured Comp use CAN Bus*/
typedef enum  
{
	
    DOOR_STATE, 					/*Door sensor uses CAN*/
    LIGHT_SWITCH_STATE,				/*Lght Switch uses CAN*/
    SPEED_STATE						/*Speed sensor uses CAN*/
	
}can_message_type;

typedef enum 
{
	
    CAN_OK,						/*return state is done*/
    CAN_ERROR					/*An error occured 	  */
	
} CanStatus_t;

typedef struct  
{
	can_message_type type;		/*Configure the component using CAN*/
    uint8_t data;				/*The buffered data to be sent on CAN*/
	uint8_t len;				/*Length of the message sent on CAN*/
	
}can_message;


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
 /*Initialize the can
 @initialize the CAN bus with the configured mode to receive the buffered data from the modules to transmit 
 them to ECUS need the data
 */
void can_init(void);

/*Control functions 
@
 @@ Control APIs to transmit and receive the data to and from the other ECUS 
@*/
CanStatus_t Can_Transmit(can_message* pst_CAN_message);
CanStatus_t Can_Receive(can_message* pst_CAN_message);

/*Callack functions*/
void can_register_message_received_callback(void (*callback)(can_message *message));

#endif /*End of file Can bus*/