#ifndef __MELT_MT_10T7_H
#define __MELT_MT_10T7_H

#include "hw_config.h"
#include <stdbool.h>
#include <stdio.h>

#define SEG_A				0x08
#define SEG_B				0x20  // 32
#define SEG_C				0x40  // 64
#define SEG_D				0x04
#define SEG_E				0x02
#define SEG_F				0x80 	// 128
#define SEG_G				0x01
#define SEG_H				0x10	// 16

#define DIGIT_ZERO	0xEE
#define DIGIT_ONE		0x60
#define DIGIT_TWO		0x2F
#define DIGIT_THREE 0x6D
#define DIGIT_FOUR	0xE1
#define DIGIT_FIVE	0xCD
#define DIGIT_SIX		0xCF
#define DIGIT_SEVEN 0x68
#define DIGIT_EIGHT 0xEF
#define DIGIT_NINE	0xED

#define WHITESPACE	0x00

#define SYMBOL_MINUS	0x01
#define SYMBOL_C			0x8E
#define SYMBOL_DEGREE	0xA9

void WR1_Latch(void);
void Init_MT_10T7(void);
void writeSymbol(uint8_t addr, uint8_t signum, bool dot);
void writeDigit(uint8_t pos, uint8_t digit, bool dot);
void CLEAR_LCD_MELT(void);
void writeNumber(uint8_t pos, int number);
void writeNumberFloat(uint8_t pos, float number);

#endif
