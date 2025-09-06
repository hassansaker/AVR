#include <avr/io.h>
#include <avr/interrupt.h>


// Interrupt Service Routines (ISRs)
ISR (TIMER0_OVF_vect) {
	PORTA=PORTA ^ 0x01;
	TCNT0=192;
}



int main() {

	
	DDRA=0xFF;
	TCNT0=192;
	TCCR0=(1<<CS00)|(1<<CS01); // set the frequency of timer is Foc/64
	TIMSK=(1<<TOIE0);
	sei();
	
	// Add your main program code here
	while (1) {
		// Your main program logic
	
	}

	return 0;
}
