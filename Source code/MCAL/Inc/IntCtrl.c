 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \IntCtrl.c   
 *         \Nested Vector Interrupt Controller Driver   
 *
 *         \The driver configure all MCU interrupts priority into groups and sub-groups  
 *          Enable NVIC Interrupt Gates for prepherals
 *
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 
 #include "Std_types.h"
 #include "IntCtrl.h"
 #include "IntCtrl_Cfg.h"
 #include "IntCtrl_Types.h"
 #include "Mcu_HW.h"
 
/********************************************************************************************************************
 *    GLOBAL DATA
 ********************************************************************************************************************/
 extern const uint8 G_PRIORITY_GROUPING;
/********************************************************************************************************************
 *    LOCAL FUNCTION PROTOTYPES
 ********************************************************************************************************************/

 static void SetPriorityGroup        (uint8 Priority_Group);
 static void IntCtrl_SetPriority     (IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum,uint8_t u8_IntPriority);
 static void IntCtrl_EnableInterrupt (IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum);
 static void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntNum);
 
/********************************************************************************************************************
 *    LOCAL FUNCTION
 ********************************************************************************************************************/
 static void SetPriorityGroupType(uint8* Priority_Group)
 {
	 uint32 APINT_OldValue         = APINT;                                //save the value was written on APINT
	 uint8 Priority_Group_Checked = Priority_Group[index] & 0x07           //make sure to get only the needed value

	 APINT = (VECTKEY | (SELECT_PRIGROUP) | APINT_OldValue);
 };
 
 static void IntCtrl_SetPriority(IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum,uint8 InterruptPriority)
 {

	uint8 InterruptPriority_Checked = ((InterruptPriority&0x07)<<5);
	PRIx(IntNum) =  InterruptPriority_Checked;                            //Set Interrupt Group
	switch(ExepNum)
	{
		case Memory_Management:
		SYSPRI1 = ((ExepNum&0x07)>>5);
		break;
		
		case Bus Fault:
		SYSPRI1 = ((ExepNum&0x07)>>13);
		break;
		
		case Usage_Fault:
		SYSPRI1 = ((ExepNum&0x07)>>21);
		break;
		
		case SVCall:
		SYSPRI2 = ((ExepNum&0x07)>>29);
		break;
		
		case Debug_Monitor:
		SYSPRI3 = ((ExepNum&0x07)>>5);
		break;
		
		case PendSV:
		SYSPRI3 = ((ExepNum&0x07)>>21);
		break;
		
		case SysTick:
		SYSPRI3 = ((ExepNum&0x07)>>29);
		break;
		
		default:
		//warning Invalid_Value
		break;
	};
	
 };
 
 static void IntCtrl_EnableInterrupt (IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum)
 {
	 uint8 IntNUM_Correct=0;
	 if(IntNum<48 && IntNum>=16)
	 {
		IntNUM_Correct = (IntNum-16);
		SET_BIT(EN0,IntNUM_Correct);
	 }
	 else if(IntNum<80 && IntNum>=48)
	 {
		IntNUM_Correct = (IntNum-48);
	    SET_BIT(EN1,IntNUM_Correct);
	 }
	 else if(IntNum<112 && IntNum>=80)
	 {
		IntNUM_Correct = (IntNum-80);
	    SET_BIT(EN2,IntNUM_Correct);
	 }
	 else if(IntNum<144 && IntNum>=112)
	 {
		IntNUM_Correct = (IntNum-112);
	    SET_BIT(EN3,IntNUM_Correct);
	 }
	 else if(IntNum<176 && IntNum>=144)
	 {
		IntNUM_Correct = ((IntNum-144)&0xF));
	    SET_BIT(EN4,IntNUM_Correct);
	 }
	 else
	 {
		 //warning INVALID_ENTRY
	 }
 
	          
	switch(ExepNum)
	{
		case Memory_Management:
		SET_BIT(SYSHNDCTRL,16);
		break;
		
		case Bus Fault:
		SET_BIT(SYSHNDCTRL,17);
		break;
		
		case Usage_Fault:
		SET_BIT(SYSHNDCTRL,18);
		break;
		
		default:
		//warning Invalid_Value
		break;
 };
 
 static void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntNum)
 {
	 uint8 IntNUM_Correct=0;
	 if(IntNum<48 && IntNum>=16)
	 {
		IntNUM_Correct = (IntNum-16);
		SET_BIT(DIS0,IntNUM_Correct);
	 }
	 else if(IntNum<80 && IntNum>=48)
	 {
		IntNUM_Correct = (IntNum-48);
	    SET_BIT(DIS1,IntNUM_Correct);
	 }
	 else if(IntNum<112 && IntNum>=80)
	 {
		IntNUM_Correct = (IntNum-80);
	    SET_BIT(DIS2,IntNUM_Correct);
	 }
	 else if(IntNum<144 && IntNum>=112)
	 {
		IntNUM_Correct = (IntNum-112);
	    SET_BIT(DIS3,IntNUM_Correct);
	 }
	 else if(IntNum<154 && IntNum>=144)
	 {
		IntNUM_Correct = ((IntNum-144)&0xF);
	    SET_BIT(DIS4,IntNUM_Correct);
	 }
	 else
	 {
		 #warning INVALID_ENTRY
	 }
 };
 
/********************************************************************************************************************
 *    GLOBAL FUNCTION
 ********************************************************************************************************************/
 
 /********************************************************************************************************************
 *   \Syntax                  :  void IntCtrl_Init(void)
 *   \Description             :  Intialization NVIC/SCB Module by parsing the configuration
 *                               into NVIC/SCB registers
 *
 *   \Sync\Async              :  Synchronous
 *   \Reentrancy              :  Non Reentrant
 *   \Parameters (in)         :  Parameter Name  Parameter Description
 *   \Parameters (out)        :  None
 *   \Return value            :  None
 ********************************************************************************************************************/
 void IntCtrl_Init(void)
 {
	 Priority_Group = &G_PRIORITY_GROUPING;
	 uint8 index;
	 for(u8_index=0;u8_index>INTCTRL_NUM_CONFIGURED;u8_index++)
	 {
	 SetPriorityGroup(Priority_Group[u8_index]);
		 
	 //Set the priority for each interrupt
	 IntCtrl_SetPriority(IntNum,ExepNum,InterruptPriority)
	
	 //Enable The wanted interrupts
	 IntCtrl_EnableInterrupt (IntNum,ExepNum);
	 };
	
	
	
 }
 
 /********************************************************************************************************************
 *    END OF FILE: IntCtrl.c
 ********************************************************************************************************************/