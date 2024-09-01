/*
 * Project_Name    :   Logic_Analyzer_UART
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <avr/io.h>      
#include <util/delay.h>  

#define USART_BAUDRATE 4800 
#define BAUD_PRESCALER (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define ASYNCHRONOUS (0 << UMSEL00) 

#define DISABLED    (0 << UPM00)
#define EVEN_PARITY (2 << UPM00)
#define ODD_PARITY  (3 << UPM00)
#define PARITY_MODE  DISABLED // USART Parity Bit Selection

#define ONE_BIT (0 << USBS0)
#define TWO_BIT (1 << USBS0)
#define STOP_BIT ONE_BIT      // USART Stop Bit Selection

#define FIVE_BIT  (0 << UCSZ00)
#define SIX_BIT   (1 << UCSZ00)
#define SEVEN_BIT (2 << UCSZ00)
#define EIGHT_BIT (3 << UCSZ00)
#define DATA_BIT   EIGHT_BIT  // USART Data Bit Selection

void USART_Init(void) {

	// Set Baud Rate
	UBRR0H = BAUD_PRESCALER >> 8;
	UBRR0L = BAUD_PRESCALER;
	
	// Set Frame Format
	UCSR0C = ASYNCHRONOUS | PARITY_MODE | STOP_BIT | DATA_BIT;
	
	// Enable Receiver and Transmitter
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
}



void send_char(char data) {

	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}


void send_String(char myString[]) {

	uint8_t a = 0;
	while (myString[a]) {
		send_char(myString[a]);
		a++;
	}
}

int main(void) {
	
	char z[30] = "Hello, Logic_Analyzer !\r\n";
	USART_Init();
	
	for (;;)
	{
		send_String(z);
		_delay_ms(1000);
	}
	return 0;
}






