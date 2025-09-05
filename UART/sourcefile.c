/*
 * Functions.c
 *
 * Created: 5/21/2024 2:56:14 AM
 *  Author: Hassan
 */ 
#include <avr/io.h>

void USART_Init(unsigned int ubrr)
{	
	
	/* Set baud rate */
	UBRRH =0x00;//(unsigned char)(ubrr>>8);
	UBRRL =0x33;//(unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN)| (1<<RXCIE); //enable (1<<RXCIE) to raise the recieve interrupt 
	/* Set frame format: 8data, 1 stop bit */
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); // if you want 2 stop bit use (1<<USBS)
	
}
void USART_Transmit( unsigned char data )
{	
	/* Put data into buffer, sends the data */
	
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	UDR = data;
	
}
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}
void UART_SendString( char *str)
{
	while (*str !=0)
	{
		USART_Transmit(*str++);
	}
	//USART_Transmit(str);
}
