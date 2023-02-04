 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \IntCtrl_Types.h
 *            
 *
 *         \Header file for IntCtrl Data Types Module
 *
 ********************************************************************************************************************/
 #ifndef INTCTRL_TYPES_H_
 #define INTCTRL_TYPES_H_
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    GLOBAL DATA TYPES AND STRUCTURES
 ********************************************************************************************************************/
 typedef enum 
 {
	 Reset=1,
	 Non_Maskable_Interrupt,
	 Hard_Fault,
	 Memory_Management,
	 Bus_Fault,
	 Usage_Fault, 
	 SVCall=11,
	 Debug_Monitor,
	 PendSV=14,
	 SysTick
 }IntCtrl_Exception_Types;
 
 typedef enum 
 {
	GPIO_Port_A=16,
	GPIO_Port_B,
	GPIO_Port_C,
	GPIO_Port_D,
	GPIO_Port_E,
	UART0,
	UART1,
	SSI0,
	I2C0,
	PWM0_Fault,
	PWM0_Generator0,
	PWM0_Generator1,
	PWM0_Generator2,
	QEI0,
	ADC0_Sequence0,
	ADC0_Sequence1,
	ADC0_Sequence2,
	ADC0_Sequence3,
	Watchdog_Timers0,
	Watchdog_Timers1=34,
	Timer0A,
	Timer0B,
	Timer1A,
	Timer1B,
	Timer2A,
	Timer2B,
	Analog_Comparator0,
	Analog_Comparator1,
	Reserved,
	System_Control,
	Flash_EEPROM_Control,
	GPIO_Port_F,
	UART2=49,
	SSI1,
	Timer3A,
	Timer3B,
	I2C1,
	QEI1,
	CAN0,
	CAN1,
	Hibernation_Module=59,
	USB,
	PWM_Generator3,
	μDMA_Software,
	μDMA_Error,
	ADC1_Sequence0,
	ADC1_Sequence1,
	ADC1_Sequence2,
	ADC1_Sequence3,
	SSI2=73,
	SSI3,
	UART3,
	UART4,
	UART5,
	UART6,
	UART7,
	I2C2=84,
	I2C3,
	Timer4A,
	Timer4B,
	Timer5A=108,
	Timer5B,
	Timer0A_64,
	Timer0B_64,
	Timer1A_64,
	Timer1B_64,
	Timer2A_64,
	Timer2B_64,
	Timer3A_64,
	Timer3B_64,
	Timer4A_64,
	Timer4B_64,
	Timer5A_64,
	Timer5B_64,
	System_Exception,
	PWM1_Generator0=150,
	PWM1_Generator1,
	PWM1_Generator2,
	PWM1_Generator3,
	PWM1_Fault
 }IntCtrl_InterruptType;
 
 /*typedef struct 
 {
	 
	 uint8 Priority_Group;
	 
	 
 }User_data_type;
 
 User_data_type G_user_data[INTCTRL_NUM_CONFIGURED]={
	 {*/
 #endif /* End INTCTRL_TYPES_H_ */
 
 /********************************************************************************************************************
 *    END OF FILE: IntCtrl_Types.h
 ********************************************************************************************************************/