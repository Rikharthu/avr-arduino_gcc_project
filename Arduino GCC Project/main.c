/*
* Arduino GCC Project.c
*
* Created: 1/31/2017 11:20:50 PM
* Author : UberV
*/

#include <avr/io.h>
#include <util/delay.h>

const int MAX_DELAY=1000;
const int MIN_DELAY=0;
const int STEP_DELAY=10;

int main(void)
{
	/* Replace with your application code */
	while (1)
	{
		// LED on
		// PORTB maps to Arduino digital pins 8 to 13 (two high bits 6 & 7 are crystal pins)
		// DDB5 is 5, 1<<5 = 32 = 00100000 => set fifth bit in register to 1, thus turning on digital pin #13
		PORTB=(1<<DDB5);
		PORTB=PORTB|1;
		_delay_ms(DELAY);
		// LED off
		PORTB=0;
		_delay_ms(DELAY);
	}
}

