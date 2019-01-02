#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"


#define TASK_ENABLE 0
#define NumOfTask 5


void SysTick_Init(void);
void mdelay(unsigned long nTime); // actually 10 us delay
#define Delay_us(x) mdelay(x); // actually 10 us delay
#define Delay_ms(x) mdelay(100*x); // ms delay
int get_tick_count(unsigned long *count);
void TimeStamp_Increment(void);

#endif /* __SYSTICK_H */
