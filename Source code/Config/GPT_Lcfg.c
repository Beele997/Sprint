 /********************************************************************************************************************
 * FILE DESCRIPTION 
 * -----------------------------------------------------------------------------------------------------------------*/
/**        \GPT_Lcfg.c
 *         \
 *
 *         \Header file for IntCtrl Module
 *
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    INCLUDES
 ********************************************************************************************************************/
 
 #include "Std_types.h"
 #include "GPT_Cfg.h"
/********************************************************************************************************************
 *    LOCAL MACROS CONTANTS/FUNTIONS
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    LOCAL DATA
 ********************************************************************************************************************/
 
/********************************************************************************************************************
 *    GLOBAL DATA
 ********************************************************************************************************************/
 Gpt_ConfigType STR_GptConfig[GPT_CONFIGURED_CHS] = {
	 {GPT_CH0, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_125KHZ, 0xFFFFFFFF, NULL_PTR},
	 {GPT_CH1, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH2, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH3, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH4, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH5, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH6, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH7, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH8, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH9, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH10, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
	 {GPT_CH11, GPT_CH_MODE_ONESHOT, GPT_CH_FREQ_16KHZ,0, NULL_PTR},
 };
 
	 
 /********************************************************************************************************************
 *    END OF FILE: GPT_Lcfg.h	
 ********************************************************************************************************************/