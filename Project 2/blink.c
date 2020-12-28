#include <msp430.h>				


/**
 * blink.c
 */
int main(void) {

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    P1DIR&=~BIT3; //Set P1.3 as input
    P1REN|=BIT3; //Enable pullup/pulldown resistors for P1.3
    P1OUT|=BIT3; //Set P1.3 to have pull up resistors

    P1DIR|=BIT0; //Set P1.0 as output

    while(1) //Run the below code forever
    {
        if((P1IN&BIT3)==(BIT3)) //If P1.3 is logical HIGH
            P1OUT&=~BIT0; //Turn off the LED
        else
            P1OUT|=BIT0; //Else, turn on the LED
    }
    return 0;
}
