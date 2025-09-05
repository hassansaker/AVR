.include "m16def.inc" ; Include the definitions for the microcontroller

;ADC with interrupt service routine

.org 0x0000 ; Start at location 0x0000
   jmp init ; Jump to the initialization routine

.org 0x001C ; ADC conversion complete interrupt vector
  jmp ADC_ISR  ; Jump to the ADC interrupt service routine

.ORG 0x100
init:
    ldi r16, low(RAMEND) ; Load the low byte of the RAMEND into r16
    out SPL, r16 ; Set the Stack Pointer Low Byte
    ldi r16, high(RAMEND) ; Load the high byte of the RAMEND into r16
    out SPH, r16 	 ; Set the Stack Pointer High Byte
	ldi r16,0xFF	 ;initialize PORTC and PORTD for output
	out DDRC,r16
	out DDRD,r16
	call ADC_Init  ; Call the ADC initialization routine
	sei			   ; Enable global interrupts
	rjmp main

; Initialize ADC
ADC_Init:
  ldi r16, 0x00 ; Set DDRA to 0x00 (input)
  out DDRA, r16 
  ldi r16, (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) ; Set ADCSRA to enable ADC, enable ADC interrupt, and set prescaler to 128
  out ADCSRA, r16 
  ldi r16, (1 << REFS0) ; Set ADMUX to use external Vref
  out ADMUX, r16  
  sbi ADCSRA,ADSC
  ret

; Main function
main:
    ; Do what you want in the main loop
    rjmp main ; Repeat indefinitely

; ADC Interrupt Service Routine
ADC_ISR:
   in r16,ADCL ; Read lower byte of ADC result
   in r17, ADCH ; Read higher 2 bits of ADC result
   out PORTC,r16 ; Output lower byte to PORTC
   out PORTD,r17 ; Output higher 2 bits to PORTD
   sbi ADCSRA,ADSC ; Start the next ADC conversion
   sbi ADCSRA,ADIF ; Clear the ADC interrupt flag
   reti ; Return from interrupt
