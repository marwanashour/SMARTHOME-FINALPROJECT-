/*
 * File:   main.c
 * Author: MARWAN
 *
 * Created on May 22, 2020, 12:33 AM
 */


#define F_CPU 16000000UL
#include <xc.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "SPI_SLAVE.h"
#include "DIO.h"
ISR(SPI_STC_vect) //interrupt
{ char x = SPI_SLAVE_RECIEVE(); //data recieved
    if(x=='O')
    {PORTA |= (1<<0);}
    else if (x== 'C')
    { PORTA &=~(1<<0) ;}
    else if (x== 'M')
    { PORTC |=(1<<0) ;} 
    else if (x== 'N')
    { PORTC &=~(1<<0) ;}
    else ;
}
int main(void) {
    sei(); //interrupt enable 
    SPI_SLAVE_INIT(); //SPI slave intialize
    DDRA |= (1<<0) ;
    DDRC |= (1<<0) ;
    while(1)
    {  

    }
    
}
