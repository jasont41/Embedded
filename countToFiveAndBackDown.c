#include <msp430.h>				

int main(void) {
    volatile int i,j,psBool = 0; //Force the compliler to not optimize the variable 'i'
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    P1DIR&=~BIT3; // Sets button as input
    P1REN|=BIT3; //Enable pullup/pulldown resistors for P1.3
    P1OUT|=BIT3; //Set P1.3 to have pull up resistors
    int bP = 1; //bP == button press
    P1DIR|=BIT0; //Set P1.0 and P1.6 as output pin

    while(1) //Keep toggling the LEDs forever
    {
        if((P1IN&BIT3)!=(BIT3)) //If P1.3 is logical HIGH
        {

           if(bP == 5){
               psBool = 1;
           }
           else if(bP == 1){
               psBool = 0;
           }
           if(psBool == 1){
               bP -= 1;
           }
           else if(psBool == 0){
               bP += 1;
           }
           for(i = 20000; i >0; i--); //delay

            for(i = bP; i > 0; i--){
                P1OUT|=BIT0; //Turn on red LED
                for(j = 20000; j>0;j--);
                P1OUT&=~BIT0; //Turn off red LED
                for(j = 20000; j>0;j--);
            }

        }

        for(i = 80000; i>0;i--);
    }
}
