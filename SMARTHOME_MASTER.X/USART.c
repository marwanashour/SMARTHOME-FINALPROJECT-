/*
 * File:   USART.c
 * Author: MARWAN
 *
 * Created on May 20, 2020, 8:12 PM
 */
/**/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "DIO.h"
void uart_init(char recieve , char transmit,char recieve_interrupt,char transmit_interrupt,char operation)
{   
    UBRRL = 103  ; // FOR 16MHz
    switch(recieve) //RECIEVE STATE
        { case ON : UCSRB |=(1<<RXEN);
            break;
          case OFF : UCSRB &=~(1<<RXEN);
            break;  
        }
    switch(transmit) //TRANSMIT STATE
        { case ON : UCSRB |=(1<<TXEN);
            break;
          case OFF : UCSRB &=~(1<<TXEN);
            break;  
        }   
    switch(recieve_interrupt) //RECIEVE INTERRUPT STATE
        { case ON : UCSRB |=(1<<RXCIE);
            break;
          case OFF : UCSRB &=~(1<<RXCIE);
            break;  
        }    
    switch(transmit_interrupt) //TRANSMIT INTERRUPT STATE
        { case ON : UCSRB |=(1<<TXCIE);
            break;
          case OFF : UCSRB &=~(1<<TXCIE);
            break;  
        }    
    switch(operation)  //OPERATION STATE
        { case SYNCHRONOUS : UCSRC |=(1<<URSEL)|(1<<UMSEL);
            break;
          case ASYNCHRONOUS : UCSRC &=~((1<<URSEL)|(1<<UMSEL));
            break;  
        }  
    
    //baud rate
    //float value = (16000000/(16*9600))-1 ;
   
}
 char uart_recieve()
{
    while(!(UCSRA & (1<<RXC))); //wait to recieve
    return UDR ;
} 

void uart_transmit(char senddata)
{
while(!(UCSRA & (1<<TXC))); //wait to transmit 
UDR = senddata;
} 

int uart_transmit_polling ()
{       char y ;
         y = uart_recieve();
        SPI_MASTER_SEND(y);
        if (y == 'O') {
            PORTA |= (1 << PIN_0);
        } else if (y == 'C') {
            PORTA &= ~(1 << PIN_0);
        }
}