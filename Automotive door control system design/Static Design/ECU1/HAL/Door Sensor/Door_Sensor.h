	/***********************************************************************************************************************
 *   \date 	 : 02.02.2023          
 *   \name 	 : Ahmed Elebaby       
 *	 \version : 1.0              
 *	 \SWC     : Door Sensor         
 *   \brief   : header file for door sensor driver
************************************************************************************************************************/
#ifndef DOOR_SENSOR_H_
#define DOOR_SENSOR_H_


/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 #include <stdint.h>
 
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 #define DOOR_SENSOR_MESSAGE_ID                   0x100 /*Macro to define the ID of the sensor*/
/********************************************************************************************************************
 *    LOCAL DATA & DATA STRUCTURE
 ********************************************************************************************************************/
 /*
   @brief Door State structures definition
 */
 /*
 enum door state
 */
 typedef enum
{
    DOOR_CLOSED = 0, /* one door is opened        */
    DOOR_OPENED = 1  /* All the doors are closed  */

} DoorState;
/*
* @ struct of message to be buffered and sent by commu-control
*/
typedef struct {
	
    uint32_t message_id;      /*variable to carry the configured Id of the sensor*/
    DoorState door_state;     /*current door state*/
} DoorSensorMessage;
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
 /*Initialize the door sensor hardware here
	using DIO driver to set the required instruction for init
 */
void door_sensor_init(void); 

/*Control functions
  @using read state to get the read of the written data on the sensor pins
  @sending the buffered data on CAN bus as a buffered message on a frame
*/
DoorState door_sensor_read_state(void);
void door_sensor_send_message(void);

/*Callack functions
  @call back function to send data back to lower layer
*/
void DoorSensor_Open_SetCallback (void (*OpenState_CallBack)(void));
void DoorSensor_Close_SetCallback(void (*CloseState_CallBack)(void));
#endif /*End of file DOOR_SENSOR*/