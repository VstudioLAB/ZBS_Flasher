#include "board.h"
#include "cpu.h"
#include "u1.h"


uint8_t eepromByte(uint8_t v)
{
	U0DBUF = v;
	while (!(U0CSR & 0x02));
	U0CSR &= (uint8_t)~0x02;
	while (U0CSR & 0x01);
	return U0DBUF;
}

void powerPortsDownForSleep(void)
{
	P0 = 0b01000000;
	P1 = 0b01000000;
	P2 = 0b00000001;
	P0DIR = 0b11111111;
	P1DIR = 0b01101110;
	P2DIR = 0b00000001;
	P0SEL = 0;
	P1SEL = 0;
	P2SEL = 0;
}

void boardInit(void)
{
	u1init();
	
//eeprom
	U0BAUD = 0;
	U0GCR = 0x31;
	U0CSR = 0x40;
	P0SEL |= (1 << 2) | (1 << 3) | (1 << 5);
	
	//P2.0 is nCS
	P2SEL &= (uint8_t)~(1 << 0);
	P2DIR |= 1 << 0;
	P2 |= 1 << 0;
}

