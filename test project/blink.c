#include <msp430.h>				


/**
 * blink.c
 */

#define LED1    BIT3
#define B1      BIT1
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P2OUT |= LED1;
	P2DIR = LED1;


	for(;;){
	    if((P2IN & B1) == 0){
	        P2OUT &= ~LED1;
	    }
	    else{
	        P2OUT |= LED1;
	    }
	}

	/*volatile unsigned int i;		// volatile to prevent optimization

	while(1)
	{
		P1OUT ^= 0x01;				// toggle P1.0

		for(i=10000; i>0; i--);     // delay
	}*/
}
