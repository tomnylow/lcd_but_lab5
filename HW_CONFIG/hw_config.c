#include "hw_config.h"

void Timer1_ETRinit(void)
{
    RST_CLK_PCLKcmd(RST_CLK_PCLK_TIMER1, ENABLE);
    RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTD, ENABLE);

    TIMER_CntInitTypeDef TIM_CntInitStr;
    TIMER_ChnInitTypeDef sTIM_ChnInit;
    PORT_InitTypeDef PORT_InitStructure;
  
    PORT_InitStructure.PORT_Pin = PORT_Pin_4;
    PORT_InitStructure.PORT_OE = PORT_OE_IN;
    PORT_InitStructure.PORT_FUNC = PORT_FUNC_MAIN;
    PORT_InitStructure.PORT_MODE = PORT_MODE_DIGITAL;
    PORT_InitStructure.PORT_SPEED = PORT_SPEED_FAST;
    PORT_Init(MDR_PORTD, &PORT_InitStructure);

    /* Настройка счетчика TIMER1 */
		TIM_CntInitStr.TIMER_IniCounter = 0; 
    TIM_CntInitStr.TIMER_Prescaler = 0; // предделитель было 8000
    TIM_CntInitStr.TIMER_Period = 0xFFFF; // период таймера
    TIM_CntInitStr.TIMER_CounterMode = TIMER_CntMode_EvtChangeDir; //режим счета
    TIM_CntInitStr.TIMER_CounterDirection = TIMER_CntDir_Up; //направление счета
    TIM_CntInitStr.TIMER_EventSource = TIMER_EvSrc_ETR; // источник событий для таймера
    TIM_CntInitStr.TIMER_FilterSampling = TIMER_FDTS_TIMER_CLK_div_1; // указывает фильтр событий
    TIM_CntInitStr.TIMER_ARR_UpdateMode = TIMER_ARR_Update_On_CNT_Overflow; // режим сброса счетчика
    TIM_CntInitStr.TIMER_ETR_FilterConf = TIMER_Filter_1FF_at_TIMER_CLK;// задает параметры выхода ETR
    TIM_CntInitStr.TIMER_ETR_Prescaler = TIMER_ETR_Prescaler_None; //задает предделитель выхода ETR
    TIM_CntInitStr.TIMER_ETR_Polarity = TIMER_ETRPolarity_NonInverted; // задает полярность выхода ETR
    TIM_CntInitStr.TIMER_BRK_Polarity = TIMER_BRKPolarity_NonInverted; // задает полярность выхода BRK

    TIMER_CntInit(MDR_TIMER1, &TIM_CntInitStr); // Инициализируем таймер
    
    sTIM_ChnInit.TIMER_CH_ETR_Ena = ENABLE; // номер канала
    
    TIMER_ChnInit(MDR_TIMER1, &sTIM_ChnInit);

    TIMER_BRGInit(MDR_TIMER1, TIMER_HCLKdiv1); // Включить тактирование TIMER1
    TIMER_Cmd(MDR_TIMER1, ENABLE); //включить TIMER1
}
void SysTickInit(void)
{
	SysTick->LOAD |= (8000)-1;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Pos;
	SysTick->CTRL |= SysTick_CTRL_COUNTFLAG_Pos;
	SysTick->CTRL |= ~SysTick_CTRL_ENABLE_Pos;	
}

void PORTS_Init(void)
{
	RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTA, ENABLE);
	
	PORT_InitTypeDef PORTA_InitStruct;
	
	PORTA_InitStruct.PORT_SPEED = PORT_SPEED_MAXFAST;
	PORTA_InitStruct.PORT_FUNC = PORT_FUNC_PORT;
	PORTA_InitStruct.PORT_MODE = PORT_MODE_DIGITAL;
	PORTA_InitStruct.PORT_OE = PORT_OE_OUT;
	PORTA_InitStruct.PORT_Pin = PORT_Pin_1 | PORT_Pin_2 | PORT_Pin_3 | PORT_Pin_6;
	PORTA_InitStruct.PORT_PULL_UP = PORT_PULL_UP_OFF;
	PORTA_InitStruct.PORT_PULL_DOWN = PORT_PULL_DOWN_OFF;
	
	PORT_Init(MDR_PORTA, &PORTA_InitStruct);
	
	RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTC, ENABLE);
	
	PORT_InitTypeDef PORTC_InitStruct;
	
	PORTC_InitStruct.PORT_SPEED = PORT_SPEED_MAXFAST;
	PORTC_InitStruct.PORT_FUNC = PORT_FUNC_PORT;
	PORTC_InitStruct.PORT_MODE = PORT_MODE_DIGITAL;
	PORTC_InitStruct.PORT_OE = PORT_OE_OUT;
	PORTC_InitStruct.PORT_Pin = PORT_Pin_0 | PORT_Pin_1;
	PORTC_InitStruct.PORT_PULL_UP = PORT_PULL_UP_OFF;
	PORTC_InitStruct.PORT_PULL_DOWN = PORT_PULL_DOWN_OFF;
	
	PORT_Init(MDR_PORTC, &PORTC_InitStruct);
	
	RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTF, ENABLE);
	
	PORT_InitTypeDef PORTF_InitStruct;
	
	PORTF_InitStruct.PORT_SPEED = PORT_SPEED_MAXFAST;
	PORTF_InitStruct.PORT_FUNC = PORT_FUNC_PORT;
	PORTF_InitStruct.PORT_MODE = PORT_MODE_DIGITAL;
	PORTF_InitStruct.PORT_OE = PORT_OE_OUT;
	PORTF_InitStruct.PORT_Pin = PORT_Pin_1 | PORT_Pin_3;
	PORTF_InitStruct.PORT_PULL_UP = PORT_PULL_UP_OFF;
	PORTF_InitStruct.PORT_PULL_DOWN = PORT_PULL_DOWN_OFF;
	
	PORT_Init(MDR_PORTF, &PORTF_InitStruct);
	
}
