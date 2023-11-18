#ifndef __HW_CONFIG_H
#define __HW_CONFIG_H

#include "MDR32Fx.h"                    // Device header
#include "MDR32F9Qx_rst_clk.h"          // Keil::Drivers:RST_CLK
#include "MDR32F9Qx_port.h"             // Keil::Drivers:PORT
#include "MDR32F9Qx_timer.h"            // Keil::Drivers:TIMER

#define A0_SET      PORT_SetBits(MDR_PORTA, PORT_Pin_6)
#define A0_RESET    PORT_ResetBits(MDR_PORTA, PORT_Pin_6)

#define WR1_SET     PORT_SetBits(MDR_PORTA, LCD_WR1)
#define WR1_RESET   PORT_ResetBits(MDR_PORTA, LCD_WR1)

#define WR2_SET     PORT_SetBits(MDR_PORTA, LCD_WR2)
#define WR2_RESET   PORT_ResetBits(MDR_PORTA, LCD_WR2)

#define DELAY_US(x)    for(int i = 0; i < x; i++)
#define DELAY_MS(x)    for(int i = 0; i < 1333*x; i++)


#define LCD_DB0			   PORT_Pin_0
#define LCD_DB1			   PORT_Pin_1
#define LCD_DB2			   PORT_Pin_1
#define LCD_DB3			   PORT_Pin_3

#define LCD_WR1				 PORT_Pin_2
#define LCD_WR2				 PORT_Pin_3

void SysTickInit(void);
void PORTS_Init(void);
void Timer1_ETRinit(void);
#endif
