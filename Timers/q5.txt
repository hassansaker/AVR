/*
 * Q4_ex5.c
 *
 * Created: 4/29/2024 9:29:57 PM
 * Author : Hassan
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t x=0x01;
// Interrupt Service Routines (ISRs)
ISR (TIMER0_OVF_vect) {
	PORTA=(PORTA) ^ (1);
	TCNT0=0;
}
int main() {

	DDRB=0xFF;
	DDRA=0xFF;
	TCNT0=0;
	TCCR0=(1<<CS00)|(1<<CS01)|(1<<COM01)|(1<<WGM00)|(1<<WGM01) ;// set the frequency of timer is Foc/64
	OCR0=50;       //50 count in F=16/64 Mhz which is 200us 
	TIMSK=(1<<TOIE0);
	sei();
	
	// Add your main program code here
	while (1) {
		// Your main program logic
		
	}

	return 0;
}
