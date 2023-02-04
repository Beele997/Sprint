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
 #include "BIT_MATH.h"
 #include "Mcu_Hw.h"
 
 #include "IntCtrl.h"
 #include "IntCtrl_Cfg.h"
 #include "IntCtrl_Types.h"
 
 
/********************************************************************************************************************
 *    GLOBAL DATA
 ********************************************************************************************************************/
 extern const uint8 G_PRIORITY_GROUPING;
/********************************************************************************************************************
 *    LOCAL FUNCTION PROTOTYPES
 ********************************************************************************************************************/

 static void SetPriorityGroup        (uint8 Priority_Group_Type);
 static void IntCtrl_SetPriority     (IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum,uint8 IntPriority_G,uint8 IntPriority_s,uint8 Priority_Group_Type);
 static void IntCtrl_EnableInterrupt (IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum);
 static void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntNum);
 
/********************************************************************************************************************
 *    LOCAL FUNCTION
 ********************************************************************************************************************/
 static void SetPriorityGroup(uint8 Priority_Group_Type)
 {
	 if(Priority_Group_Type<8)
	 {
	 uint32 APINT_OldValue         = APINT; 
	 APINT_OldValue &= ~((uint32)(VECTKEY_KEY_MSK|APINT_PRIGROUP_MSK));
	 APINT = (VECTKEY | APINT_OldValue | (Priority_Group_Type<<APINT_PRIGROUP_POS) );
	 }
	 else
	 {
		 /*Invalid Value*/
		 return;
	 }
	 
 }
 
 static void IntCtrl_SetPriority(IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum,uint8 IntPriority_G,uint8 IntPriority_s,uint8 Priority_Group_Type)
 {

	if(IntPriority_G<8 && IntPriority_s<8)
	 {
		 if(Priority_Group_Type==GR8_SUB0)
		 {
			 PRIx(IntNum) =  (IntPriority_G&0x7);
		 }
		 else if(Priority_Group_Type==GR4_SUB2 )
		 {
			 PRIx(IntNum) =  (((IntPriority_G&0x03)<<0x1)|((IntPriority_s&0x01)<<0x0));
		 }
		 else if(Priority_Group_Type==GR2_SUB4)
		 {
			 PRIx(IntNum) =  (((IntPriority_G&0x01)<<0x1)|((IntPriority_s&0x03)<<0x0));
		 }
		 else if(Priority_Group_Type==GR0_SUB8)
		 {
			 PRIx(IntNum) =  (IntPriority_s&0x7);
		 }
		 else
		 {
			 /*Invalid Priority*/
		 }
	   
	 }
	 else
	 {
		 /*Invalid Value*/
		 return;
	 }
	                      
	switch(ExepNum)
	{
		case Memory_Management:
		SYSPRI1 = ((ExepNum&0x07)>>5);
		break;
		
		case Bus_Fault:
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
		break;
	}
	
 }
 
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
		IntNUM_Correct = ((IntNum-144)&0xF);
	    SET_BIT(EN4,IntNUM_Correct);
	 }
 
	          
	switch(ExepNum)
	{
		case Memory_Management:
		SET_BIT(SYSHNDCTRL,16);
		break;
		
		case Bus_Fault:
		SET_BIT(SYSHNDCTRL,17);
		break;
		
		case Usage_Fault:
		SET_BIT(SYSHNDCTRL,18);
		break;
		
		default:
		break;
 }
 }
 
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
 }
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
 void IntCtrl_Init(IntCtrl_InterruptType IntNum,IntCtrl_Exception_Types ExepNum,uint8 IntPriority_G,uint8 IntPriority_s,uint8 Priority_Group_Type)
 {
	 /*Set the priority group*/
	 SetPriorityGroup(Priority_Group_Type);
		 
	 /*Set the priority for each interrupt*/
	 IntCtrl_SetPriority(IntNum,ExepNum,IntPriority_G,IntPriority_s,Priority_Group_Type);
	
	 /*Enable The wanted interrupts*/
	 IntCtrl_EnableInterrupt (IntNum,ExepNum);
 }
 
 /********************************************************************************************************************
 *    END OF FILE: IntCtrl.c
 ********************************************************************************************************************/
 
 
 