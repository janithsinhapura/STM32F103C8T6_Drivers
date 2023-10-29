#include "stm32f10x.h"
#include "systick.h"


#define CORE_CLOCK_FREQ 72000000

void DelayMS(uint32_t delay)
{
	SysTick->LOAD = (CORE_CLOCK_FREQ/1000) - 1;
	SysTick->VAL = 0; //set the current value of the systick;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE | SysTick_CTRL_ENABLE ; //set processor clock source and enable systick
	
	for(uint32_t i =0;i<delay;i++)
	{
		while(((SysTick->CTRL)&SysTick_CTRL_COUNTFLAG) == 0);
	}
	SysTick->CTRL = 0;
}
