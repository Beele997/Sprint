	/***********************************************************************************************************************
 *   \date 	 : 02.02.2023          
 *   \name 	 : Ahmed Elebaby       
 *	 \version : 1.0              
 *	 \SWC     : Lightswitch          
 *   \brief   : header file for Light Switch driver
************************************************************************************************************************/
#ifndef LIGHT_SWITCH_H_
#define LIGHT_SWITCH_H_


/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
#include <stdint.h>
 

 
 
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 #define LIGHT_SWITCG_MESSAGE_ID                   0x101 /*Macro to define the ID of the sensor*/
/********************************************************************************************************************
 *    LOCAL DATA & DATA STRUCTURE
 ********************************************************************************************************************/
 /*
   @brief light State structures definition
 */
 /*
 enum light switch
 */
 typedef enum
{

    SWITCH_STATE_OFF = 1, /* LIGHT SWITCH IS NOT PRESSED     */
    SWITCH_STATE_ON = 0   /* LIGHT SWITCH IS PRESSED         */

} LightSwitchState;
/*
* @ struct of message to be buffered and sent by commu-control
*/
typedef struct {
	
	LightSwitchState switch_state; /*current soor state*/
    uint32_t message_id;		   /*variable to carry the configured Id of the switch*/
    
} LightSwitchMessage;


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
 /*Initialize the light switch hardware here*/
void light_switch_init(void);


/*Control functions
  @using read state to get the read of the written data on the switch pins
  @sending the buffered data on CAN bus as a buffered message on a frame
*/
LightSwitchState light_switch_read_state(void); /*Read the state of the light switch*/
void light_switch_send_message(void);

/*Callack functions
  @call back function to send data back to lower layer
*/
void LightSwitch_On_SetCallback(void (*OnState_CallBack)(void));
void  LightSwitch_Off_SetCallback(void (*OffState_CallBack)(void));
#endif /*End of file Light Switch*/