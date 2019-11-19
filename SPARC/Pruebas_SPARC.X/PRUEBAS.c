#include <xc.h>
#include "UART.h"
//OSCILLATOR SOURCE AND DIGITAL I/O CONFIGURATION BITS

#pragma config OSC = IRCIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

//DEBUGGER SETUP CONFIGURATION BITS
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))

int z;
unsigned char A[] = {"Apagado"};
unsigned char P[] = {"Prendido"};

void main(void) {

    
    //CLOCK FREQUENCY CONFIGURATION
    OSCCON = 0X60; //4 MHz internal oscillator

    //DISABLE PORT´s ANALOG FUNCTIONS
    CMCON = 0XFF; //Comparators OFF, to use PORT_D´s LSN
    CVRCONbits.CVREN = 0; //Comparator Voltage Reference Module OFF
    ADCON1 = 0X0F; //All ports as DIGITAL I/O

    TRISB0 = 0; //RB0 as Output PIN 

    INIT_UART();

    while (1) {

        z = RECEIVE_UART();
        
        if (z == 49) {
            RB0 = 1;

            for (unsigned char i = 0; i < (sizeof (P) - 1); i++) {
                SEND_UART(P[i]);
            }
        }
        if (z == 48) {
            RB0 = 0;

            for (unsigned char i = 0; i < (sizeof (A) - 1); i++) {
                SEND_UART(A[i]);

            }

        }

    }
    return;
}

