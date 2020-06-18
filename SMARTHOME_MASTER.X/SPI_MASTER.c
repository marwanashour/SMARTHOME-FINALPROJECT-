/*
 * File:   SPI_MASTER.c
 * Author: MARWAN
 *
 * Created on June 15, 2020, 4:01 AM
 */


#include <xc.h>

void SPI_MASTER_INIT()
{   
    DDRB |= (1<<4)|(1<<7)|(1<<5); // SS OUT PUT , MOSI OUTPUT , SCK OUTPUT
    DDRB &= ~(1<<6); // MISO INPUT
    SPCR |= (1<<SPE) | (1<<MSTR) |(1<<SPR1) | (1<<SPR0); // SPI ENABLE, MASTER, prescaler 128
 
}
void SPI_MASTER_SEND(char data_master )
{  
    SPDR = data_master ; // put data in the data register
    while(!(SPSR &(1<<SPIF))); // wait to transfer data

}