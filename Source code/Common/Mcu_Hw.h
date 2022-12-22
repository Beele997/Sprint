	 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \Mcu_Hw.h
 *         \Mcu_Hw   
 *
 *         \Header file for Registers Definiation
 *
 ********************************************************************************************************************/
 #ifndef MCU_HW_H_
 #define MCU_HW_H_
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 
 #include "Std_types.h"

 /********************************************************************************************************************
 *    GLOBAL DATA TYPES AND STRUCTURES
 ********************************************************************************************************************/
 
 typedef struct
 {
	uint32 VECACT    : 8;
	uint32           : 3;
	uint32 RETBASE   : 1;
	uint32 VECACT    : 4;
	uint32 VECPEND   : 4;
	uint32           : 2;
	uint32 ISRPEND   : 1;
	uint32 ISRPRE    : 1;
	uint32           : 1;
	uint32 PENDSTCLR : 1;
	uint32 PENDSTSET : 1;
	uint32 UNPENDSV  : 1;
	uint32 PENDSV    : 1;
	uint32           : 2;
	uint32 NMISET    : 1;
 }INTCTRL_BF;
 
 
 
 typedef union
 {
	 uint32 R;
	 INTCTRL_BF B;
	 
 }INTCTRL_Tag;
 
/********************************************************************************************************************
 *    GLOBAL CONSTANT MACROS 
 ********************************************************************************************************************/
 /************************************* INTERRUPT DEFINITIONS *******************************************************/
 #define CRTEXM4_PERI_BASE_ADDRESS       0xE000E000
 #define GPIO_CLOCK_BASE_ADDRESS         0x400FE000
 
 #define APINT                           (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD0C)))
 #define INTCTRL                         (*((volatile INTCTRL_Tag*)(CRTEXM4_PERI_BASE_ADDRESS+0xD04)))
 #define CFGCTRL                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD14)))
 #define PRIx(Priority_Num)              (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+((0x400+((Priority_Num/4)*4))))))
 #define SWTRIG 						 (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xF00)))
 #define VTABLE    						 (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD08)))
 #define FAULTSTAT                       (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD28)))
 #define HFAULTSTAT                      (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD2C)))
 #define MMADDR                          (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD34)))
 #define SYSPRI1                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD18)))
 #define SYSPRI2                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD1C)))
 #define SYSPRI3                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD20)))
 #define SYSHNDCTRL 					 (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0xD24)))


 
 //Interrupts Enable Registers
 #define EN0                             (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x100)))    
 #define EN1                             (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x104)))     
 #define EN2                             (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x108)))    
 #define EN3                             (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x10C)))    
 #define EN4                             (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x110)))
//Interrupts Disable Registers
 #define DIS0                            (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x180)))
 #define DIS1                            (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x184)))
 #define DIS2                            (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x188)))
 #define DIS3                            (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x18C)))
 #define DIS4                            (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x190))) 
//Interrupts Pending Registers
 #define PEND0                           (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x200)))
 #define PEND1                           (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x204)))
 #define PEND2                           (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x208)))
 #define PEND3                           (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x20C)))
 #define PEND4                           (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x210)))
//Clear Unpending Interrupts Registers
 #define UNPEND0                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x280)))
 #define UNPEND1                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x284)))
 #define UNPEND2                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x288)))
 #define UNPEND3                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x28C)))
 #define UNPEND4                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x290)))
//Active Interrupts Registers
 #define ACTIVE0                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x300)))
 #define ACTIVE1                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x304)))
 #define ACTIVE2                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x308)))
 #define ACTIVE3                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x30C)))
 #define ACTIVE4                         (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x310)))

 /****************************************** GPIO DEFINITIONS *******************************************************/
 #define RCGCGPIO                        (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x608)))
 #define GPIOHBCTL                       (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x06C)))
 #define GPIOAFSEL					     (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x420)))
 #define GPIOPCR  					     (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+)))
 #define GPIOIS   					     (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x404)))
 #define GPIOIBE   					     (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x408)))
 #define GPIOIEV   					     (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x40C)))
 #define GPIOIM     				     (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x410))) //En-Dis Interrupts
 #define GPIORIS     				     (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x414)))//View the state of the interrupt
 #define GPIOMIS						 (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x418)))
 #define GPIOADCCTL						 (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x530)))
 #define GPIODMACTL						 (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x534)))
 #define GPIOLOCK                        (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x520))) //Lock register commit
 #define GPIOCR                          (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x524))) //commit register 
 
 // registers to control strength , pull up, pull down
 #define GPIOSLR  						 (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x518)))
 #define GPIOODR  						 (*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x50C)))
 
 #define GPIO_APB    //Chose The bus type
 #ifdef  GPIO_AHB
 //GPIO AHB Definiations
 #define GPIO_PortA_AHB                  0x40058000
 #define GPIODIR_A                       (*((volatile uint32*)(GPIO_PortA_AHB+0x400)))
 #define GPIODATA_A                      (*((volatile uint32*)(GPIO_PortA_AHB+0x000)))
 #define GPIOPCTL_A                      (*((volatile uint32*)(GPIO_PortA_AHB+0x52C)))
 #define GPIODR2R_A                      (*((volatile uint32*)(GPIO_PortA_AHB+0x500)))
 #define GPIODR4R_A                      (*((volatile uint32*)(GPIO_PortA_AHB+0x504)))
 #define GPIODR8R_A                      (*((volatile uint32*)(GPIO_PortA_AHB+0x508)))
 #define GPIOPUR_A                       (*((volatile uint32*)(GPIO_PortA_AHB+0x510)))
 #define GPIOPDR_A                       (*((volatile uint32*)(GPIO_PortA_AHB+0x514)))
 #define GPIODEN_A                       (*((volatile uint32*)(GPIO_PortA_AHB+0x51C)))
 
 #define GPIO_PortB_AHB                  0x40059000
 #define GPIODIR_B                       (*((volatile uint32*)(GPIO_PortB_AHB+0x400)))
 #define GPIODATA_B                      (*((volatile uint32*)(GPIO_PortB_AHB+0x000)))
 #define GPIOPCTL_B                      (*((volatile uint32*)(GPIO_PortB_AHB+0x52C)))
 #define GPIODR2R_B                      (*((volatile uint32*)(GPIO_PortB_AHB+0x500)))
 #define GPIODR4R_B                      (*((volatile uint32*)(GPIO_PortB_AHB+0x504)))
 #define GPIODR8R_B                      (*((volatile uint32*)(GPIO_PortB_AHB+0x508)))
 #define GPIOPUR_B                       (*((volatile uint32*)(GPIO_PortB_AHB+0x510)))
 #define GPIOPDR_B                       (*((volatile uint32*)(GPIO_PortB_AHB+0x514)))
 #define GPIODEN_B                       (*((volatile uint32*)(GPIO_PortB_AHB+0x51C)))
 
 #define GPIO_PortC_AHB                  0x4005A000
 #define GPIODIR_C                       (*((volatile uint32*)(GPIO_PortC_AHB+0x400)))
 #define GPIODATA_C                      (*((volatile uint32*)(GPIO_PortC_AHB+0x000)))
 #define GPIOPCTL_C                      (*((volatile uint32*)(GPIO_PortC_AHB+0x52C)))
 #define GPIODR2R_C                      (*((volatile uint32*)(GPIO_PortC_AHB+0x500)))
 #define GPIODR4R_C                      (*((volatile uint32*)(GPIO_PortC_AHB+0x504)))
 #define GPIODR8R_C                      (*((volatile uint32*)(GPIO_PortC_AHB+0x508)))
 #define GPIOPUR_C                       (*((volatile uint32*)(GPIO_PortC_AHB+0x510)))
 #define GPIOPDR_C                       (*((volatile uint32*)(GPIO_PortC_AHB+0x514)))
 #define GPIODEN_C                       (*((volatile uint32*)(GPIO_PortC_AHB+0x51C)))
 
 #define GPIO_PortD_AHB                  0x4005B000
 #define GPIODIR_D                       (*((volatile uint32*)(GPIO_PortD_AHB+0x400)))
 #define GPIODATA_D                      (*((volatile uint32*)(GPIO_PortD_AHB+0x000)))
 #define GPIOPCTL_D                      (*((volatile uint32*)(GPIO_PortD_AHB+0x52C)))
 #define GPIODR2R_D                      (*((volatile uint32*)(GPIO_PortD_AHB+0x500)))
 #define GPIODR4R_D                      (*((volatile uint32*)(GPIO_PortD_AHB+0x504)))
 #define GPIODR8R_D                      (*((volatile uint32*)(GPIO_PortD_AHB+0x508)))
 #define GPIOPUR_D                       (*((volatile uint32*)(GPIO_PortD_AHB+0x510)))
 #define GPIOPDR_D                       (*((volatile uint32*)(GPIO_PortD_AHB+0x514)))
 #define GPIODEN_D                       (*((volatile uint32*)(GPIO_PortD_AHB+0x51C)))
 
 #define GPIO_PortE_AHB                  0x4005C000
 #define GPIODIR_E                       (*((volatile uint32*)(GPIO_PortE_AHB+0x400)))
 #define GPIODATA_E                      (*((volatile uint32*)(GPIO_PortE_AHB+0x000)))
 #define GPIOPCTL_E                      (*((volatile uint32*)(GPIO_PortE_AHB+0x52C)))
 #define GPIODR2R_E                      (*((volatile uint32*)(GPIO_PortE_AHB+0x500)))
 #define GPIODR4R_E                      (*((volatile uint32*)(GPIO_PortE_AHB+0x504)))
 #define GPIODR8R_E                      (*((volatile uint32*)(GPIO_PortE_AHB+0x508)))
 #define GPIOPUR_E                       (*((volatile uint32*)(GPIO_PortE_AHB+0x510)))
 #define GPIOPDR_E                       (*((volatile uint32*)(GPIO_PortE_AHB+0x514)))
 #define GPIODEN_E                       (*((volatile uint32*)(GPIO_PortE_AHB+0x51C)))
 
 #define GPIO_PortF_AHB                  0x4005D000
 #define GPIODIR_F                       (*((volatile uint32*)(GPIO_PortF_AHB+0x400)))
 #define GPIODATA_F                      (*((volatile uint32*)(GPIO_PortF_AHB+0x000)))
 #define GPIOPCTL_F                      (*((volatile uint32*)(GPIO_PortF_AHB+0x52C)))
 #define GPIODR2R_F                      (*((volatile uint32*)(GPIO_PortF_AHB+0x500)))
 #define GPIODR4R_F                      (*((volatile uint32*)(GPIO_PortF_AHB+0x504)))
 #define GPIODR8R_F                      (*((volatile uint32*)(GPIO_PortF_AHB+0x508)))
 #define GPIOPUR_F                       (*((volatile uint32*)(GPIO_PortF_AHB+0x510)))
 #define GPIOPDR_F                       (*((volatile uint32*)(GPIO_PortF_AHB+0x514)))
 #define GPIODEN_F                       (*((volatile uint32*)(GPIO_PortF_AHB+0x51C)))
 
 #elif GPIO_APB
 //GPIO APB Definiations
 #define GPIO_PortA_APB                  0x40004000
 #define GPIODIR_A                       (*((volatile uint32*)(GPIO_PortA_APB+0x400)))
 #define GPIODATA_A                      (*((volatile uint32*)(GPIO_PortA_APB+0x000)))
 #define GPIOPCTL_A                      (*((volatile uint32*)(GPIO_PortA_APB+0x52C)))
 #define GPIODR2R_A                      (*((volatile uint32*)(GPIO_PortA_APB+0x500)))
 #define GPIODR4R_A                      (*((volatile uint32*)(GPIO_PortA_APB+0x504)))
 #define GPIODR8R_A                      (*((volatile uint32*)(GPIO_PortA_APB+0x508)))
 #define GPIOPUR_A                       (*((volatile uint32*)(GPIO_PortA_APB+0x510)))
 #define GPIOPDR_A                       (*((volatile uint32*)(GPIO_PortA_APB+0x514)))
 #define GPIODEN_A                       (*((volatile uint32*)(GPIO_PortA_APB+0x51C)))

 #define GPIO_PortB_APB                  0x40005000
 #define GPIODIR_B                       (*((volatile uint32*)(GPIO_PortB_APB+0x400)))
 #define GPIODATA_B                      (*((volatile uint32*)(GPIO_PortB_APB+0x000)))
 #define GPIOPCTL_B                      (*((volatile uint32*)(GPIO_PortB_APB+0x52C)))
 #define GPIODR2R_B                      (*((volatile uint32*)(GPIO_PortB_APB+0x500)))
 #define GPIODR4R_B                      (*((volatile uint32*)(GPIO_PortB_APB+0x504)))
 #define GPIODR8R_B                      (*((volatile uint32*)(GPIO_PortB_APB+0x508)))
 #define GPIOPUR_B                       (*((volatile uint32*)(GPIO_PortB_APB+0x510)))
 #define GPIOPDR_B                       (*((volatile uint32*)(GPIO_PortB_APB+0x514)))
 #define GPIODEN_B                       (*((volatile uint32*)(GPIO_PortB_APB+0x51C)))
 
 #define GPIO_PortC_APB                  0x40006000
 #define GPIODIR_C                       (*((volatile uint32*)(GPIO_PortC_APB+0x400)))
 #define GPIODATA_C                      (*((volatile uint32*)(GPIO_PortC_APB+0x000)))
 #define GPIOPCTL_C                      (*((volatile uint32*)(GPIO_PortC_APB+0x52C)))
 #define GPIODR2R_C                      (*((volatile uint32*)(GPIO_PortC_APB+0x500)))
 #define GPIODR4R_C                      (*((volatile uint32*)(GPIO_PortC_APB+0x504)))
 #define GPIODR8R_C                      (*((volatile uint32*)(GPIO_PortC_APB+0x508)))
 #define GPIOPUR_C                       (*((volatile uint32*)(GPIO_PortC_APB+0x510)))
 #define GPIOPDR_C                       (*((volatile uint32*)(GPIO_PortC_APB+0x514)))
 #define GPIODEN_C                       (*((volatile uint32*)(GPIO_PortC_APB+0x51C)))
 
 #define GPIO_PortD_APB                  0x40007000
 #define GPIODIR_D                       (*((volatile uint32*)(GPIO_PortD_APB+0x400)))
 #define GPIODATA_D                      (*((volatile uint32*)(GPIO_PortD_APB+0x000)))
 #define GPIOPCTL_D                      (*((volatile uint32*)(GPIO_PortD_APB+0x52C)))
 #define GPIODR2R_D                      (*((volatile uint32*)(GPIO_PortD_APB+0x500)))
 #define GPIODR4R_D                      (*((volatile uint32*)(GPIO_PortD_APB+0x504)))
 #define GPIODR8R_D                      (*((volatile uint32*)(GPIO_PortD_APB+0x508)))
 #define GPIOPUR_D                       (*((volatile uint32*)(GPIO_PortD_APB+0x510)))
 #define GPIOPDR_D                       (*((volatile uint32*)(GPIO_PortD_APB+0x514)))
 #define GPIODEN_D                       (*((volatile uint32*)(GPIO_PortD_APB+0x51C)))
 
 #define GPIO_PortE_APB                  0x40024000
 #define GPIODIR_E                       (*((volatile uint32*)(GPIO_PortE_APB+0x400)))
 #define GPIODATA_E                      (*((volatile uint32*)(GPIO_PortE_APB+0x000)))
 #define GPIOPCTL_E                      (*((volatile uint32*)(GPIO_PortE_APB+0x52C)))
 #define GPIODR2R_E                      (*((volatile uint32*)(GPIO_PortE_APB+0x500)))
 #define GPIODR4R_E                      (*((volatile uint32*)(GPIO_PortE_APB+0x504)))
 #define GPIODR8R_E                      (*((volatile uint32*)(GPIO_PortE_APB+0x508)))
 #define GPIOPUR_E                       (*((volatile uint32*)(GPIO_PortE_APB+0x510)))
 #define GPIOPDR_E                       (*((volatile uint32*)(GPIO_PortE_APB+0x514)))
 #define GPIODEN_E                       (*((volatile uint32*)(GPIO_PortE_APB+0x51C)))
 
 #define GPIO_PortF_APB                  0x40025000
 #define GPIODIR_F                       (*((volatile uint32*)(GPIO_PortF_APB+0x400)))
 #define GPIODATA_F                      (*((volatile uint32*)(GPIO_PortF_APB+0x000)))
 #define GPIOPCTL_F                      (*((volatile uint32*)(GPIO_PortF_APB+0x52C)))
 #define GPIODR2R_F                      (*((volatile uint32*)(GPIO_PortF_APB+0x500)))
 #define GPIODR4R_F                      (*((volatile uint32*)(GPIO_PortF_APB+0x504)))
 #define GPIODR8R_F                      (*((volatile uint32*)(GPIO_PortF_APB+0x508)))
 #define GPIOPUR_F                       (*((volatile uint32*)(GPIO_PortF_APB+0x510)))
 #define GPIOPDR_F                       (*((volatile uint32*)(GPIO_PortF_APB+0x514)))
 #define GPIODEN_F                       (*((volatile uint32*)(GPIO_PortF_APB+0x51C)))
 #endif
 /****************************************** GPT DEFINITIONS ********************************************************/
  
 
 #define GPTMTAV // Value 
 #define GPTMTBV 
 #define GPTMTAPR //Prescaler
 #define GPTMTBPR 
 #define GPTMTAPS //Prescaler snapshot
 #define GPTMTBPS
 #define GPTMTAPV//Prescaler Value
 #define GPTMTBPV
 #define GPTMCTL   // How to start/stop counting
 #define GPTMIMR   // How to Enable/Disable interrupt
 #define GPTMTAV   // how to get elapsed/remaining time value (Ticks)
 #define GPTMPP
 #define RCGCTIMER						(*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x604)))
 #define RCGCWTIMER						(*((volatile uint32*)(GPIO_CLOCK_BASE_ADDRESS+0x65C)))
 
 //Timers with 16-32 bit
 #define GPT_TIMER0_16_BASE_ADDRESS     0x4003.0000
 #define GPTMCFG_0_16   		    	(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x000)))
 #define GPTMCTL_0_16   	    		(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x00C)))
 #define GPTMTAMR_0_16   	    		(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x004)))
 #define GPTMTBMR_0_16   	    		(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x008)))
 #define GPTMTAILR_0_16 				(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x028)))
 #define GPTMTBILR_0_16 				(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x02C)))
 #define GPTMIMR_0_16 					(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x018)))
 #define GPTMRIS_0_16					(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x01C)))
 #define GPTMICR_0_16					(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x024)))
 #define GPTMMIS_0_16					(*((volatile uint32*)(GPT_TIMER0_16_BASE_ADDRESS+0x020)))
 
 #define GPT_TIMER1_16_BASE_ADDRESS     0x4003.1000
 #define GPTMCFG_1_16   				(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x000)))
 #define GPTMCTL_1_16   	    		(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x00C)))
 #define GPTMTAMR_1_16   	    		(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x004)))
 #define GPTMTBMR_1_16   	    		(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x008)))
 #define GPTMTAILR_1_16 				(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x028)))
 #define GPTMTBILR_1_16 				(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x02C)))
 #define GPTMIMR_1_16 					(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x018)))
 #define GPTMRIS_1_16					(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x01C)))
 #define GPTMICR_1_16					(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x024)))
 #define GPTMMIS_1_16					(*((volatile uint32*)(GPT_TIMER1_16_BASE_ADDRESS+0x020)))
 
 #define GPT_TIMER2_16_BASE_ADDRESS     0x4003.2000
 #define GPTMCFG_2_16   				(*((volatile uint32*)(GPT_TIMER2_16_BASE_ADDRESS+0x000)))
 #define GPTMCTL_2_16   	    		(*((volatile uint32*)(GPT_TIMER2_16_BASE_ADDRESS+0x00C)))
 
 #define GPT_TIMER3_16_BASE_ADDRESS     0x4003.3000
 #define GPTMCFG_3_16   		    	(*((volatile uint32*)(GPT_TIMER3_16_BASE_ADDRESS+0x000)))
 #define GPTMCTL_3_16   	    		(*((volatile uint32*)(GPT_TIMER3_16_BASE_ADDRESS+0x00C)))
 
 #define GPT_TIMER4_16_BASE_ADDRESS     0x4003.4000
 #define GPTMCFG_4_16   				(*((volatile uint32*)(GPT_TIMER4_16_BASE_ADDRESS+0x000)))
 #define GPTMCTL_4_16   	    		(*((volatile uint32*)(GPT_TIMER4_16_BASE_ADDRESS+0x00C)))
 
 #define GPT_TIMER5_16_BASE_ADDRESS     0x4003.5000
 #define GPTMCFG_5_16   				(*((volatile uint32*)(GPT_TIMER5_16_BASE_ADDRESS+0x000)))
 #define GPTMCTL_5_16   	    		(*((volatile uint32*)(GPT_TIMER5_16_BASE_ADDRESS+0x00C)))
 //Timers with 32-64 bit
 #define GPT_TIMER0_32_BASE_ADDRESS     0x4003.6000
 #define GPTMCFG_0_32   				(*((volatile uint32*)(GPT_TIMER0_32_BASE_ADDRESS+0x000)))
 #define GPTMCTL_0_32   	    		(*((volatile uint32*)(GPT_TIMER0_32_BASE_ADDRESS+0x00C)))
 
 #define GPT_TIMER1_32_BASE_ADDRESS     0x4003.7000
 #define GPTMCFG_1_32   				(*((volatile uint32*)(GPT_TIMER1_32_BASE_ADDRESS+0x000)))
 #define GPTMCTL_1_32   	    		(*((volatile uint32*)(GPT_TIMER1_32_BASE_ADDRESS+0x00C)))
 
 #define GPT_TIMER2_32_BASE_ADDRESS     0x4004.C000
 #define GPTMCFG_2_32   				(*((volatile uint32*)(GPT_TIMER2_32_BASE_ADDRESS+0x000)))
 #define GPTMCTL_2_32   	    		(*((volatile uint32*)(GPT_TIMER2_32_BASE_ADDRESS+0x00C)))
 
 #define GPT_TIMER3_32_BASE_ADDRESS     0x4004.D000
 #define GPTMCFG_3_32   				(*((volatile uint32*)(GPT_TIMER3_32_BASE_ADDRESS+0x000)))
 #define GPTMCTL_3_32   	    		(*((volatile uint32*)(GPT_TIMER3_32_BASE_ADDRESS+0x00C)))
 
 #define GPT_TIMER4_32_BASE_ADDRESS     0x4004.E000
 #define GPTMCFG_4_32   				(*((volatile uint32*)(GPT_TIMER4_32_BASE_ADDRESS+0x000)))
 #define GPTMCTL_4_32   	    		(*((volatile uint32*)(GPT_TIMER4_32_BASE_ADDRESS+0x00C)))
 
 #define GPT_TIMER5_32_BASE_ADDRESS     0x4004.F000 
 #define GPTMCFG_5_32   				(*((volatile uint32*)(GPT_TIMER5_32_BASE_ADDRESS+0x000)))
 #define GPTMCTL_5_32   	    		(*((volatile uint32*)(GPT_TIMER5_32_BASE_ADDRESS+0x00C))) 
 
 
 
 /****************************************** SYSTICK DEFINITIONS ****************************************************/
 #define STCTRL                          (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x010)))
 #define STRELOAD                        (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x014)))
 #define STCURRENT                       (*((volatile uint32*)(CRTEXM4_PERI_BASE_ADDRESS+0x018)))


 /********************************************************************************************************************
 *    GLOBAL DATA PROTOTYPES
 ********************************************************************************************************************/
 


 #endif       /*MCU_HW.h*/
 /********************************************************************************************************************
 *    END OF FILE: MCU_HW.h	
 ********************************************************************************************************************/