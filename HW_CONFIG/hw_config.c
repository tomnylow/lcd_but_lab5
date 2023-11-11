#include "hw_config.h"
void initTimer1CaptureModeWithETR(void) {
    // Настройка структуры инициализации таймера
    TIMER_CntInitTypeDef timerInitStruct;

    // Сначала инициализируем значения структуры вручную
    timerInitStruct.TIMER_IniCounter = 0;        // Начальное значение счетчика
    timerInitStruct.TIMER_Prescaler = 0;         // Предделитель (отсутствует)
    timerInitStruct.TIMER_Period = 0xFFFF;       // Максимальное значение периода
    timerInitStruct.TIMER_CounterMode = TIMER_CntMode_EvtFixedDir;  // Режим счета 
    timerInitStruct.TIMER_CounterDirection = TIMER_CntDir_Up;  // Направление счета (вверх)

    // Источник события - ETR
    timerInitStruct.TIMER_EventSource = TIMER_EvSrc_ETR;

    // Настройка фильтра ETR
    timerInitStruct.TIMER_ETR_FilterConf = TIMER_Filter_8FF_at_FTDS_div_32;  // Фильтр ETR с питанием от fdts и длиной событий 8
		timerInitStruct.TIMER_ETR_Prescaler = TIMER_ETR_Prescaler_None;
		timerInitStruct.TIMER_ETR_Polarity = TIMER_ETRPolarity_NonInverted;
    // Настройка фильтра событий
    timerInitStruct.TIMER_FilterSampling = TIMER_FDTS_TIMER_CLK_div_4;  // Питание фильтра от частоты процессора 4
    timerInitStruct.TIMER_ARR_UpdateMode = TIMER_ARR_Update_Immediately; // Обновление ARR сразу

    // Инициализация таймера 1
    TIMER_CntInit(MDR_TIMER1, &timerInitStruct);
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
	
	PORT_InitTypeDef PORTD_InitStruct;
	
	PORTD_InitStruct.PORT_SPEED = PORT_SPEED_MAXFAST;
	PORTD_InitStruct.PORT_FUNC = PORT_FUNC_MAIN;
	PORTD_InitStruct.PORT_MODE = PORT_MODE_DIGITAL;
	PORTD_InitStruct.PORT_OE = PORT_OE_IN;
	PORTD_InitStruct.PORT_Pin = PORT_Pin_4;
	PORTD_InitStruct.PORT_PULL_UP = PORT_PULL_UP_OFF;
	PORTD_InitStruct.PORT_PULL_DOWN = PORT_PULL_DOWN_OFF;
	
	PORT_Init(MDR_PORTF, &PORTD_InitStruct);
}
