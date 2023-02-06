/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"
#include "semphr.h"

/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )


/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/
/* Handlers*/
xQueueHandle string;
xQueueHandle string_length;
TaskHandle_t Task_1_Handler;
TaskHandle_t Task_2_Handler;
TaskHandle_t Task_3_Handler;
TaskHandle_t Task_4_Handler;
TaskHandle_t Task_5_Handler;
TaskHandle_t Task_6_Handler;

/***********************************************************************************************************************/
/*Global Variables*/
float CPU_Load;
int System_Time;
int Task1_Time_Start=0,Task1_Time_End=0,Task1_Total_Time=0;
int Task2_Time_Start=0,Task2_Time_End=0,Task2_Total_Time=0;
int Task3_Time_Start=0,Task3_Time_End=0,Task3_Total_Time=0;
int Task4_Time_Start=0,Task4_Time_End=0,Task4_Total_Time=0;
int Task5_Time_Start=0,Task5_Time_End=0,Task5_Total_Time=0;
int Task6_Time_Start=0,Task6_Time_End=0,Task6_Total_Time=0;

char (reciever_buffer)[23];
char Button_1_LastState;
char Button_1_LevelState;
char Button_2_LastState;
char Button_2_LevelState;

uint32_t index_1;
uint32_t index_2;
TickType_t Tick1;
TickType_t Tick2;
TickType_t Tick3;
TickType_t Tick4;
TickType_t Tick5;
TickType_t Tick6;
/*************************************************************************************************************************/
/*Button 1 Monitor*/
void Task_1(void * ptr) 
{
	vTaskSetApplicationTaskTag( NULL, (TaskHookFunction_t) 1 );
	
	Tick1=xTaskGetTickCount();
	for(;;)
	{
	Button_1_LevelState=GPIO_read(PORT_1,PIN0);
	if(Button_1_LevelState>Button_1_LastState)
	{

		xQueueSendToBack(string,"Switch 1 Raising Edge\n",0);
		
	}
	else if(Button_1_LevelState<Button_1_LastState)
		{

		xQueueSendToBack(string,"Switch 1 Falling Edge\n",0);

		}
		Button_1_LastState=Button_1_LevelState;
		
	vTaskDelayUntil(&Tick1,50);

	}
}
/*Button_2_Monitor*/
void Task_2(void * ptr) 
{
	vTaskSetApplicationTaskTag( NULL, (TaskHookFunction_t) 2 );
	
	Tick2=xTaskGetTickCount();
	for(;;)
	{
	
	Button_2_LevelState=GPIO_read(PORT_1,PIN1);
	if(Button_2_LevelState>Button_2_LastState)
	{
	
		xQueueSendToBack(string,"Switch 2 Raising Edge\n",0);

		
	}
	else if(Button_2_LevelState<Button_2_LastState)
		{
			
		xQueueSendToBack(string,"Switch 2 Falling Edge\n",0);

		}
		Button_2_LastState=Button_2_LevelState;

	  vTaskDelayUntil(&Tick2,50);

	}
}
/*Periodic_Transmitter*/
void Task_3(void * ptr)  
{
	  vTaskSetApplicationTaskTag( NULL, (TaskHookFunction_t) 3 );
	
	  Tick3=xTaskGetTickCount();
	  for(;;)
	  {

		xQueueSendToBack(string,"-> Periodic String  \n",0);

	  vTaskDelayUntil(&Tick3,100);
	  }
}
 /*Uart_Receiver*/
void Task_4(void * ptr) 
{
	vTaskSetApplicationTaskTag( NULL, (TaskHookFunction_t) 4 );
	
	Tick4=xTaskGetTickCount();
	for(;;)
	{
  if(xQueueReceive(string,reciever_buffer,0)==pdTRUE)
	{
	 vSerialPutString((signed char*)(reciever_buffer),23);
	}
	else
	{
		
	}
	vTaskDelayUntil(&Tick4,20);
	}
}
/*Load_1_Simulation*/
void Task_5(void * ptr) 
{
	vTaskSetApplicationTaskTag( NULL, (TaskHookFunction_t) 5 );
	
	Tick5=xTaskGetTickCount();
	for(;;)
	{
	
	for(index_2=0;index_2<=11910;index_2++)
		{
      //Load for 5ms
		}
	vTaskDelayUntil(&Tick5,10);
		
	}
}
/*Load_2_Simulation*/
void Task_6(void * ptr) 
{
	vTaskSetApplicationTaskTag( NULL, (TaskHookFunction_t) 6 );
	
	Tick6=xTaskGetTickCount();
	for(;;)
	{
	
	for(index_1=0;index_1<=28620;index_1++)
		{
			 //Load for 12ms
		}
		
	  vTaskDelayUntil(&Tick6,100);
		
	}
}


void vApplicationTickHook()
{
	
	GPIO_write(PORT_1,PIN9,PIN_IS_HIGH);
	GPIO_write(PORT_1,PIN9,PIN_IS_LOW);
	 
	
}
	
int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();
	
	/* Start the demo/test application tasks. */
	string=xQueueCreate(6,sizeof(char [23]));
	xTaskPeriodicCreate(Task_1,"Button_1_Monitor",100,(void*)0,&Task_1_Handler,50);
  xTaskPeriodicCreate(Task_2,"Button_2_Monitor",100,(void*)0,&Task_2_Handler,50);
	xTaskPeriodicCreate(Task_3,"Periodic_Transmitter",100,(void*)0,&Task_3_Handler,100);
  xTaskPeriodicCreate(Task_4,"Uart_Receiver",100,(void*)0,&Task_4_Handler,20);
	xTaskPeriodicCreate(Task_5,"Load_1_Simulation",100,(void*)0,&Task_5_Handler,10);
  xTaskPeriodicCreate(Task_6,"Load_2_Simulation",100,(void*)0,&Task_6_Handler,100);
   

	vTaskStartScheduler();
	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


