#include <avr/io.h>
#include <avr/interrupt.h>

// Interrupt Service Routines (ISRs)
ISR(INT0_vect) {
	// Code to handle INT0 interrupt
	// Add your desired functionality here
	PORTA=0x01;
}

ISR(INT1_vect) {
	// Code to handle INT1 interrupt
	// Add your desired functionality here
	PORTA=0x02;
}

int main() {
	// Configure INT0 and INT1 for rising edge interrupts
	MCUCR = (1 << ISC11) | (1 << ISC01) | (1<< ISC10) | (1<<ISC00); // Set ISC11 and ISC01 bits for rising edge

	// Enable INT0 and INT1 interrupts
	GICR = (1 << INT1) | (1 << INT0);

	// Enable global interrupts
	sei();
	
	DDRA=0xFF;
	
	// Add your main program code here
	while (1) {
		// Your main program logic
	}

	return 0;
}
