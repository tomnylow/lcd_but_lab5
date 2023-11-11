#include "melt_mt_10t7.h"

void WR1_Latch(void)
{
	DELAY_US(70);
	WR1_SET;
	DELAY_US(150);
	WR1_RESET;
	DELAY_US(70);
}

void Init_MT_10T7(void)
{
	A0_RESET;
	WR2_RESET;
	
	PORT_WriteBit(MDR_PORTC, LCD_DB0, Bit_SET);
	PORT_WriteBit(MDR_PORTC, LCD_DB1, Bit_SET);
	PORT_WriteBit(MDR_PORTF, LCD_DB2, Bit_SET);
	PORT_WriteBit(MDR_PORTF, LCD_DB3, Bit_SET);
	
	WR1_Latch();
	
	PORT_WriteBit(MDR_PORTC, LCD_DB0, Bit_SET);
	PORT_WriteBit(MDR_PORTC, LCD_DB1, Bit_RESET);
	PORT_WriteBit(MDR_PORTF, LCD_DB2, Bit_RESET);
	PORT_WriteBit(MDR_PORTF, LCD_DB3, Bit_RESET);
	
	A0_SET;
	WR1_Latch();
	CLEAR_LCD_MELT();
}

void writeSymbol(uint8_t addr, uint8_t signum, bool dot)
{
	BitAction data;
	
	A0_RESET;
	
	data = (BitAction)(addr & 0x01);
	PORT_WriteBit(MDR_PORTC, LCD_DB0, data);
	
	data = (BitAction)((addr >> 1) & 0x01);
	PORT_WriteBit(MDR_PORTC, LCD_DB1, data);
	
	data = (BitAction)((addr >> 2) & 0x01);
	PORT_WriteBit(MDR_PORTF, LCD_DB2, data);
	
	data = (BitAction)((addr >> 3) & 0x01);
	PORT_WriteBit(MDR_PORTF, LCD_DB3, data);
	
	WR1_Latch();	
	
	if (dot)
	signum += 16;
	
	data = (BitAction)(signum & 0x01);
	PORT_WriteBit(MDR_PORTC, LCD_DB0, data);
	
	data = (BitAction)((signum >> 1) & 0x01);
	PORT_WriteBit(MDR_PORTC, LCD_DB1, data);
	
	data = (BitAction)((signum >> 2) & 0x01);
	PORT_WriteBit(MDR_PORTF, LCD_DB2, data);
	
	data = (BitAction)((signum >> 3) & 0x01);
	PORT_WriteBit(MDR_PORTF, LCD_DB3, data);
	
	A0_SET;
	WR1_Latch();
	
	data = (BitAction)((signum >> 4) & 0x01);
	PORT_WriteBit(MDR_PORTC, LCD_DB0, data);
	
	data = (BitAction)((signum >> 5) & 0x01);
	PORT_WriteBit(MDR_PORTC, LCD_DB1, data);
	
	data = (BitAction)((signum >> 6) & 0x01);
	PORT_WriteBit(MDR_PORTF, LCD_DB2, data);
	
	data = (BitAction)((signum >> 7) & 0x01);
	PORT_WriteBit(MDR_PORTF, LCD_DB3, data);
	
	WR1_Latch();		
}

void writeDigit(uint8_t pos, uint8_t digit, bool dot)
{
	switch(digit)
	{
		case 0: writeSymbol(pos, DIGIT_ZERO, dot); break;
		case 1: writeSymbol(pos, DIGIT_ONE, dot); break;
		case 2: writeSymbol(pos, DIGIT_TWO, dot); break;
		case 3: writeSymbol(pos, DIGIT_THREE, dot); break;
		case 4: writeSymbol(pos, DIGIT_FOUR, dot); break;
		case 5: writeSymbol(pos, DIGIT_FIVE, dot); break;
		case 6: writeSymbol(pos, DIGIT_SIX, dot); break;
		case 7: writeSymbol(pos, DIGIT_SEVEN, dot); break;
		case 8: writeSymbol(pos, DIGIT_EIGHT, dot); break;
		case 9: writeSymbol(pos, DIGIT_NINE, dot); break;
		default: writeSymbol(pos, WHITESPACE, false); break;
	}
}

void CLEAR_LCD_MELT(void)
{
	for(uint8_t i = 0; i < 10; i++)
	{
		writeSymbol(i, 0, false);
	}	
}

void writeNumber(uint8_t pos, int number)
{
	char buff[10] = {'a',};
	uint8_t j = 0;
	
	j = sprintf(buff, "%d", number);
	
	for(uint8_t i = 0; i < j; i++)
	{
		writeDigit(pos + i, buff[i] - 48, false);
	}	
}

void writeNumberFloat(uint8_t pos, float number)
{
	char buff[10] = {'a',};
	uint8_t shiftcomp = 0;
	sprintf (buff, "%f", number);
	
	for(uint8_t i = 0; i < (10 - pos + shiftcomp); i++)
	{
		if (buff[i + 1] == 46)
		{
			writeDigit(pos + i, buff[i] - 48, true);
			i+=2;
			shiftcomp = 1;
		}
		writeDigit(pos + i - shiftcomp, buff[i] - 48, false);
	}	
}
