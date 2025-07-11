.include "m16def.inc" ; Include the definitions for the microcontroller

.org 0x0000 ; Start at location 0x0000
 jmp init ; Jump to the initialization routine

.ORG 0x100
init:
    ldi r16, low(RAMEND) ; Load the low byte of the RAMEND into r16
    out SPL, r16 ; Set the Stack Pointer Low Byte
    ldi r16, high(RAMEND) ; Load the high byte of the RAMEND into r16
    out SPH, r16 	 ; Set the Stack Pointer High Byte
	ldi r16,0xFF	 ;intialize portA for output
	out DDRC,r16
	out DDRD,r16
	rjmp main
; Initialize ADC
 ADC_Init:
  ldi r16, 0x00 ; Set DDRA to 0x00
  out DDRA, r16 
  ldi r16, 0x87 ; Set ADCSRA to 0x87 
  out ADCSRA, r16 
  ldi r16, 0x40 ; Set ADMUX to 0xC0 internal Vref
  out ADMUX, r16  
  ret
 ; Read ADC value 
ADC_Read:
  ldi r17,0x40
  in r16,ADCSRA
  or r16,r17  ; Set input channel to read
  out ADCSRA, r16 
wait_loop:
   sbic ADCSRA, ADIF ; Monitor end of conversion interrupt 
   rjmp wait_loop
   sbi ADCSRA,ADIF   ;write 1 to clear ADIT flag
   in r16,ADCL ; Read lower byte
   in r17, ADCH ; Read higher 2 bits 
   out PORTC,r16
   out PORTD,r17
   ret 
 ; Main function
main:
    ldi r16, 0x00 ; Initialize temp register
	out DDRA, r16 ; Set DDRA to 0x00 
	call ADC_Init ; Call ADC_Init function
loop:
 
	call ADC_Read ; 
	
rjmp loop ; Repeat indefinitely
