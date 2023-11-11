#include "melt_mt_10t7.h"


volatile int t = 0;

volatile uint32_t delay_dec = 0;// объ€вление переменной delay_dec

void SysTick_Handler(void)
{
	if (delay_dec !=0) 
		delay_dec--;
}

void delay_ms(uint32_t delay_ms)
{
	delay_dec = delay_ms;//присвоить delay_dec значение delay_ms
	
	while (delay_dec) {}; // выполн€ть функцию пока delay_dec не станет равным 0
}



int main(void)
{

	
	SysTickInit();
	PORTS_Init();
	Init_MT_10T7();
	//writeNumberFloat(0, 10981.254);
	uint16_t but_cnt = 0;
	
	for(int i = 0; i < 10; i++){
		writeNumber(0, but_cnt);
		delay_ms(1000);
		but_cnt = TIMER_GetCounter(MDR_TIMER1);	
	}
	while(1)
	{
		
		//CLEAR_LCD_MELT();
		
	}
}
