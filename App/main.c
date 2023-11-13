#include "melt_mt_10t7.h"
#define COUNT 1

volatile int t = 0;

volatile uint32_t delay_dec = 0;// ���������� ���������� delay_dec

void SysTick_Handler(void)
{
	if (delay_dec !=0) 
		delay_dec--;
}

void delay_ms(uint32_t delay_ms)
{
	delay_dec = delay_ms;//��������� delay_dec �������� delay_ms
	
	while (delay_dec) {}; // ��������� ������� ���� delay_dec �� ������ ������ 0
}
uint16_t moving_average_filter(uint16_t* window, uint16_t newVal) {
    
		static uint8_t i = 0;
		static uint16_t sum = 0;
		if (++i >= 15) i = 0; 
		sum -= window[i];         
		sum += newVal;          
		window[i] = newVal;           
		return (sum / 15);
    
}


int main(void)
{
	SysTickInit();
	PORTS_Init();
	Init_MT_10T7();
	//writeNumberFloat(0, 10981.254);
	uint16_t but_cnt = 0, prev_but_cnt = 0;
	uint16_t count_buff[15] = {0,};
	
	if (COUNT) {
		for(int i = 0; i < 10; i++){
			writeNumber(0, but_cnt);
			delay_ms(1000);
			but_cnt = TIMER_GetCounter(MDR_TIMER1);	
		}
	}
	
	while(1)
	{
		if (!COUNT){
			prev_but_cnt = TIMER_GetCounter(MDR_TIMER1);
			delay_ms(1000);
			but_cnt = TIMER_GetCounter(MDR_TIMER1);
			writeNumber(0, moving_average_filter(count_buff, but_cnt - prev_but_cnt));
		}	
		//CLEAR_LCD_MELT();
		
	}
}
