/***********************************************************************************************************************
 *   \date 	 : 02.02.2023          
 *   \name 	 : Ahmed Elebaby       
 *	 \version : 1.0              
 *	 \SWC     : Speed Sensor          
 *   \brief   : header file for Speed Sensor  driver
************************************************************************************************************************/
#ifndef SPEED_SENSOR_H_
#define SPEED_SENSOR_H_


/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 #include <stdint.h>
 

 
 
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 #define SPEED_SENSOR_MESSAGE_ID 0x102
/********************************************************************************************************************
 *    LOCAL DATA & DATA STRUCTURE
 ********************************************************************************************************************/
typedef struct {
	
    uint32_t message_id;
    uint16_t speed;
	
} SpeedSensorMessage;

typedef uint16_t SpeedMeasure;

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
 /*Initialize the speed sensor*/
void speed_sensor_init(void);

/*Control functions : Read the speed of the car and return it*/
SpeedMeasure speed_sensor_read_speed(void);
void speed_sensor_send_message(void);


/*Callack functions*/


#endif /*End of file Speed Sensor*/