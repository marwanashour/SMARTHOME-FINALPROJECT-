/*
 * File:   main.c
 * Author: MARWAN
 *
 * Created on June 15, 2020, 3:59 AM
 */


#define F_CPU 16000000UL
#include <xc.h>
#include <util/delay.h>
#include "DIO.h"
#include <avr/interrupt.h>
#include "SPI_MASTER.h"
#include "USART.h"
char data;

ISR(USART_RXC_vect) //interrupt method
{

    data = UDR;                     //RECIEVE INTERRUPT
    while((UCSRA & (1<<RXC)));      //wait to recieve data
    SPI_MASTER_SEND(data);          //SEND DATA VIA SPI TO SLAVE
    if (data == 'O') {              //TO TEST THE UART ON THE FIRST MICROCONTROLLER
        PORTA |= (1 << PIN_0);      //TO TEST THE UART ON THE FIRST MICROCONTROLLER
    }                               //TO TEST THE UART ON THE FIRST MICROCONTROLLER
    else if (data == 'C') {         //TO TEST THE UART ON THE FIRST MICROCONTROLLER
        PORTA &= ~(1 << PIN_0);     //TO TEST THE UART ON THE FIRST MICROCONTROLLER
    }                               //TO TEST THE UART ON THE FIRST MICROCONTROLLER
}

int main(void) {
    SET_PIN_AS(PORT_A, PIN_0, OUTPUT);  //TEST UART
    sei();                              //interuppt enable
    SPI_MASTER_INIT();                  //intialize master SPI 
    uart_init(ON, OFF, ON, OFF, ASYNCHRONOUS);  //USART INTIALIZE
    while (1) {
    }
    return 0;
}
