/*
* Arduino GCC Project.c
*
* Created: 1/31/2017 11:20:50 PM
* Author : UberV
*/

#include <avr/io.h>
#include <util/delay.h>
#include "BitMath.h"

const int MAX_DELAY=100;
const int MIN_DELAY=0;
const int STEP_DELAY=10;
int currentDelay;

void delay_ms(int ms);
void setup();
void loop();

int main(void)
{
	setup();
	while (1)
	{
		loop();
	}
}

void setup(){
	currentDelay=MAX_DELAY;
	
	// Configure data direction register DDR
	// 1 - output, 0 - input
	DDRB=0b00011111; // 8-12: output
	
	// also set 13th port as output too
	DDRB=DDRB | 0b00100000;
	//DDRD=0;
	//// set 13th pin to high
	//PORTB= 1<<5;
	//
	//int bit = (PINB>>2) & 1;
	//// esli mi zazgli 13th port, to zazgi i vtoroi
	////int bit = (PORTB>>5) & 1;
	//if(bit==1){
		////PORTD=0b00011111;
		//PORTB=1;
	//}else{
		//PORTB=1<<1;
	//}
}

void loop(){
	// LED on
	// PORTB maps to Arduino digital pins 8 to 13 (two high bits 6 & 7 are crystal pins)
	// DDB5 is 5, 1<<5 = 32 = 00100000 => set fifth bit in register to 1, thus turning on digital pin #13
	// 00000001 << 5 = 00100000
	//PORTB=(1<<DDB5);
	////PORTB=PORTB|1;
	//delay_ms(currentDelay);
	// LED off
	//PORTB=0;
	//delay_ms(currentDelay);

	for(int i=0;i<5;i++){
		//PORTB=1<<i;
		PORTB=setBitTo(PORTB,i,1);
		if(i!=4)
			delay_ms(currentDelay);
		PORTB=clearBit(PORTB,i);
	}
	for(int i=4;i>=0;i--){
		PORTB=1<<i;
		delay_ms(currentDelay);
	}
	PORTB=0;
	delay_ms(currentDelay);
	// blink all 5 LEDs (8, 9, 10, 11, 12)
	PORTB=0b00011111;
	delay_ms(currentDelay);
	PORTB=0;
	delay_ms(currentDelay);

	if(currentDelay>MIN_DELAY){
		currentDelay-=STEP_DELAY;
	}else{
		currentDelay=MAX_DELAY;
	}
}

void delay_ms(int ms){
	for(int i=0; i<ms;i++){
	_delay_ms(1);
	}
}

