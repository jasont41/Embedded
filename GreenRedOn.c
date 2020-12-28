#include <msp430.h>				

int main(void) {
    volatile int i; //Force the compliler to not optimize the variable 'i'
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    P1DIR|=BIT0|BIT6; //Set P1.0 and P1.6 as output pin
    while(1) //Keep toggling the LEDs forever
    {
        P1OUT|=BIT0; //Turn on red LED
        P1OUT|=BIT6; //Turn on green LED
    }
    return 0;
}
