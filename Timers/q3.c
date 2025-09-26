
#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t x=0x01;
uint8_t i=0;
// Interrupt Service Routines (ISRs)
ISR (TIMER0_COMP_vect) {
	if(i==13)
	{
	PORTA=x;
	x=~x;
	x=x&(0x01);
	i=0;
	}
	i++;
}
int main() {

	
	DDRA=0xFF;
	TCNT0=0;
	TCCR0=(1<<CS00) ;// set the frequency of timer is Foc/64
	OCR0=128;
	TIMSK=(1<<OCIE0);
	sei();
	
	// Add your main program code here
	while (1) {
		// Your main program logic
		
	}

	return 0;

}
