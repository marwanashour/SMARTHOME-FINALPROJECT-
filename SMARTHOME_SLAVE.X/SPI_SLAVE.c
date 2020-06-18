/*
 * File:   SPI_SLAVE.c
 * Author: MARWAN
 *
 * Created on June 17, 2020, 6:32 AM
 */


#include <xc.h>

void SPI_SLAVE_INIT()
{   
    DDRB |= (1<<6); // MISO 
    DDRB &= ~(1<<4); DDRB &= ~(1<<5); DDRB &= ~(1<<7); // inputs
    SPCR |= (1<<SPE)  |(1<<SPR1) | (1<<SPR0)|(1<<SPIE); // SPI ENABLE,, prescaler 128
    SPCR &= ~(1<<MSTR); //slave
 
}
char SPI_SLAVE_RECIEVE( )
{  
    
    while(!(SPSR &(1<<SPIF))); // wait to recieve
    return SPDR ;
}