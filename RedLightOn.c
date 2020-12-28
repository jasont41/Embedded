#include <msp430.h>				

int main(void) {
    volatile int i; //Force the compliler to not optimize the variable 'i'
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    P1DIR&=~BIT3; // Sets button as input
    P1REN|=BIT3; //Enable pullup/pulldown resistors for P1.3
    P1OUT|=BIT3; //Set P1.3 to have pull up resistors

    P1DIR|=BIT0; //Set P1.0 and P1.6 as output pin
    while(1) //Keep toggling the LEDs forever
    {
        P1OUT|=BIT0; //Turn on red LED
    }
    return 0;
}
