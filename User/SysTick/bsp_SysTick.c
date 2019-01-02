/**
  ******************************************************************************
  * @file    bsp_SysTick.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   SysTick ??????10us?????,?????????,
  *          ???? 1us 10us 1ms ???     
  ******************************************************************************
  * @attention
  *
  * ????:?? ??? STM32 ??? 
  * ??    :http://www.firebbs.cn
  * ??    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
//SysTick_Config??????????,??STK_VAL???,??SysTick???AHB 
#include "./systick/bsp_SysTick.h"
 
static __IO uint32_t TimingDelay=0;
__IO uint32_t g_ul_ms_ticks=0;
//volatile uint32_t Minute = 0;
//volatile uint32_t Second = 0;
//volatile uint32_t Hour = 0;
//volatile uint32_t tenUs = 0;
 
/**
  * @brief  ????????? SysTick
  * @param  ?
  * @retval ?
  */
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms????
	 * SystemFrequency / 100000	 10us????
	 * SystemFrequency / 1000000 1us????
	 */
	if (SysTick_Config(SystemCoreClock/100000))	
	{ 
		/* Capture error */ 
		while (1);
	}
		// ¹Ø±ÕµÎ´ð¶¨Ê±Æ÷  
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
}



void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
		TimingDelay--;
}

void mdelay(unsigned long nTime) // actually 10us delay
{
	TimingDelay = nTime;
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;
	while(TimingDelay != 0);
}


int get_tick_count(unsigned long *count)
{
        count[0] = g_ul_ms_ticks;
	return 0;
}



void TimeStamp_Increment(void)
{
	g_ul_ms_ticks++;
}


/*********************************************END OF FILE**********************/
