/*
 * File:   DIO.c
 * Author: MARWAN
 *
 * Created on May 20, 2020, 8:13 PM
 *
 * File:   DIO.c
 * Author: MARWAN
 *
 * Created on May 13, 2020, 6:53 AM
 */


#include <xc.h>
#include <avr/interrupt.h>
#include "DIO.h"
void SET_PORT_AS(char port ,char direction,char state)
{
    if (port == PORT_A)
    {  
        switch(direction)
        {   case INPUT : DDRA = 0x00 ;
            break;
            case OUTPUT: DDRA = 0xFF ;
            break;
        }
        switch(state)
        {   case OFF : PORTA = 0x00 ;
            break;
            case ON: PORTA = 0xFF ;
            break;
        }        
    }
    else if (port == PORT_B)
    {  
        switch(direction)
        {   case INPUT : DDRB= 0x00 ;
            break;
            case OUTPUT: DDRB = 0xFF ;
            break;
        }
        switch(state)
        {   case OFF : PORTB = 0x00 ;
            break;
            case ON: PORTB = 0xFF ;
            break;
        }         
    } 
    else if (port == PORT_C)
    {  
        switch(direction)
        {   case INPUT : DDRC= 0x00 ;
            break;
            case OUTPUT: DDRC = 0xFF ;
            break;
        }
        switch(state)
        {   case OFF : PORTC = 0x00 ;
            break;
            case ON: PORTC = 0xFF ;
            break;
        }         
    }
    else if (port == PORT_D)
    {  
        switch(direction)
        {   case INPUT : DDRD= 0x00 ;
            break;
            case OUTPUT: DDRD = 0xFF ;
            break;
        }
        switch(state)
        {   case OFF : PORTD = 0x00 ;
            break;
            case ON: PORTD = 0xFF ;
            break;
        }         
    }    
}



void SET_PIN_AS(char port,char pin ,char direction)
{ //PORT A IF
    if (port == PORT_A)
    //pin 0
        { if (pin == PIN_0)
            { switch (direction)
                { case INPUT : DDRA &= ~(1<<PIN_0); break ;
                  case OUTPUT : DDRA |= (1<<PIN_0); break ; 
                }
            }
    //PIN1    
          else if (pin == PIN_1)
           { switch (direction)
                { case INPUT : DDRA &= ~(1<<PIN_1); break ;
                  case OUTPUT : DDRA |= (1<<PIN_1); break ; 
                }
            }
    //PIN2    
          else if (pin == PIN_2)
           { switch (direction)
                { case INPUT : DDRA &= ~(1<<PIN_2); break ;
                  case OUTPUT : DDRA |= (1<<PIN_2); break ; 
                }
            }
    //PIN3   
          else if (pin == PIN_3)
           { switch (direction)
                { case INPUT : DDRA &= ~(1<<PIN_3); break ;
                  case OUTPUT : DDRA |= (1<<PIN_3); break ; 
                }
            }
    //PIN4    
          else if (pin == PIN_4)
           { switch (direction)
                { case INPUT : DDRA &= ~(1<<PIN_4); break ;
                  case OUTPUT : DDRA |= (1<<PIN_4); break ; 
                }
            }
    //PIN5   
          else if (pin == PIN_5)
           { switch (direction)
                { case INPUT : DDRA &= ~(1<<PIN_5); break ;
                  case OUTPUT : DDRA |= (1<<PIN_5); break ; 
                }
            }
    //PIN6      
          else if (pin == PIN_6)
           { switch (direction)
                { case INPUT : DDRA &= ~(1<<PIN_6); break ;
                  case OUTPUT : DDRA |= (1<<PIN_6); break ; 
                }
            }
    //PIN7 
          else if (pin == PIN_7)
           { switch (direction)
                { case INPUT : DDRA &= ~(1<<PIN_7); break ;
                  case OUTPUT : DDRA |= (1<<PIN_7); break ; 
                }
            }
//end if pins        
        }

    
    // PORT B IF
    else if (port == PORT_B)
    //pin 0
        { if (pin == PIN_0)
            { switch (direction)
                { case INPUT : DDRB &= ~(1<<PIN_0); break ;
                  case OUTPUT : DDRB |= (1<<PIN_0); break ; 
                }
            }
    //PIN1    
          else if (pin == PIN_1)
           { switch (direction)
                { case INPUT : DDRB &= ~(1<<PIN_1); break ;
                  case OUTPUT : DDRB |= (1<<PIN_1); break ; 
                }
            }
    //PIN2    
          else if (pin == PIN_2)
           { switch (direction)
                { case INPUT : DDRB &= ~(1<<PIN_2); break ;
                  case OUTPUT : DDRB |= (1<<PIN_2); break ; 
                }
            }
    //PIN3   
          else if (pin == PIN_3)
           { switch (direction)
                { case INPUT : DDRB &= ~(1<<PIN_3); break ;
                  case OUTPUT : DDRB |= (1<<PIN_3); break ; 
                }
            }
    //PIN4    
          else if (pin == PIN_4)
           { switch (direction)
                { case INPUT : DDRB &= ~(1<<PIN_4); break ;
                  case OUTPUT : DDRB |= (1<<PIN_4); break ; 
                }
            }
    //PIN5   
          else if (pin == PIN_5)
           { switch (direction)
                { case INPUT : DDRB &= ~(1<<PIN_5); break ;
                  case OUTPUT : DDRB |= (1<<PIN_5); break ; 
                }
            }
    //PIN6      
          else if (pin == PIN_6)
           { switch (direction)
                { case INPUT : DDRB &= ~(1<<PIN_6); break ;
                  case OUTPUT : DDRB |= (1<<PIN_6); break ; 
                }
            }
    //PIN7 
          else if (pin == PIN_7)
           { switch (direction)
                { case INPUT : DDRB &= ~(1<<PIN_7); break ;
                  case OUTPUT : DDRB |= (1<<PIN_7); break ; 
                }
            }
//end if pins        
        }
    
    // PORT C IF
    else if (port == PORT_C)
    //pin 0
        { if (pin == PIN_0)
            { switch (direction)
                { case INPUT : DDRC &= ~(1<<PIN_0); break ;
                  case OUTPUT : DDRC |= (1<<PIN_0); break ; 
                }
            }
    //PIN1    
          else if (pin == PIN_1)
           { switch (direction)
                { case INPUT : DDRC &= ~(1<<PIN_1); break ;
                  case OUTPUT : DDRC |= (1<<PIN_1); break ; 
                }
            }
    //PIN2    
          else if (pin == PIN_2)
           { switch (direction)
                { case INPUT : DDRC &= ~(1<<PIN_2); break ;
                  case OUTPUT : DDRC |= (1<<PIN_2); break ; 
                }
            }
    //PIN3   
          else if (pin == PIN_3)
           { switch (direction)
                { case INPUT : DDRC &= ~(1<<PIN_3); break ;
                  case OUTPUT : DDRC |= (1<<PIN_3); break ; 
                }
            }
    //PIN4    
          else if (pin == PIN_4)
           { switch (direction)
                { case INPUT : DDRC &= ~(1<<PIN_4); break ;
                  case OUTPUT : DDRC |= (1<<PIN_4); break ; 
                }
            }
    //PIN5   
          else if (pin == PIN_5)
           { switch (direction)
                { case INPUT : DDRC &= ~(1<<PIN_5); break ;
                  case OUTPUT : DDRC |= (1<<PIN_5); break ; 
                }
            }
    //PIN6      
          else if (pin == PIN_6)
           { switch (direction)
                { case INPUT : DDRC &= ~(1<<PIN_6); break ;
                  case OUTPUT : DDRC |= (1<<PIN_6); break ; 
                }
            }
    //PIN7 
          else if (pin == PIN_7)
           { switch (direction)
                { case INPUT : DDRC &= ~(1<<PIN_7); break ;
                  case OUTPUT : DDRC |= (1<<PIN_7); break ; 
                }
            }
//end if pins        
        }

    //PORT D IF 
    else  if (port == PORT_D)
    //pin 0
        { if (pin == PIN_0)
            { switch (direction)
                { case INPUT : DDRD &= ~(1<<PIN_0); break ;
                  case OUTPUT : DDRD |= (1<<PIN_0); break ; 
                }
            }
    //PIN1    
          else if (pin == PIN_1)
           { switch (direction)
                { case INPUT : DDRD &= ~(1<<PIN_1); break ;
                  case OUTPUT : DDRD |= (1<<PIN_1); break ; 
                }
            }
    //PIN2    
          else if (pin == PIN_2)
           { switch (direction)
                { case INPUT : DDRD &= ~(1<<PIN_2); break ;
                  case OUTPUT : DDRD |= (1<<PIN_2); break ; 
                }
            }
    //PIN3   
          else if (pin == PIN_3)
           { switch (direction)
                { case INPUT : DDRD &= ~(1<<PIN_3); break ;
                  case OUTPUT : DDRD |= (1<<PIN_3); break ; 
                }
            }
    //PIN4    
          else if (pin == PIN_4)
           { switch (direction)
                { case INPUT : DDRD &= ~(1<<PIN_4); break ;
                  case OUTPUT : DDRD |= (1<<PIN_4); break ; 
                }
            }
    //PIN5   
          else if (pin == PIN_5)
           { switch (direction)
                { case INPUT : DDRD &= ~(1<<PIN_5); break ;
                  case OUTPUT : DDRD |= (1<<PIN_5); break ; 
                }
            }
    //PIN6      
          else if (pin == PIN_6)
           { switch (direction)
                { case INPUT : DDRD &= ~(1<<PIN_6); break ;
                  case OUTPUT : DDRD |= (1<<PIN_6); break ; 
                }
            }
    //PIN7 
          else if (pin == PIN_7)
           { switch (direction)
                { case INPUT : DDRD &= ~(1<<PIN_7); break ;
                  case OUTPUT : DDRD |= (1<<PIN_7); break ; 
                }
            }
//end if pins        
        }
}