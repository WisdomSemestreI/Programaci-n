#include <xc.h>
#include <pic18f4585.h>
#include "UART.h"
#include "SERIAL.h"


#pragma config OSC = IRCIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

//DEBUGGER SETUP CONFIGURATION BITS
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))

void main() {

    //CLOCK FREQUENCY CONFIGURATION
    OSCCON = 0X60; //4 MHz internal oscillator

    //DISABLE PORT´s ANALOG FUNCTIONS
    CMCON = 0XFF; //Comparators OFF, to use PORT_D´s LSN
    CVRCONbits.CVREN = 0; //Comparator Voltage Reference Module OFF
    ADCON1 = 0X0F; //All ports as DIGITAL I/O

    INIT_UART();
    unsigned char Texto[] = "Hola Mundo\n";
    unsigned char* Ptr;

    Ptr = &Texto[0];

    while (1) {
        SEND_STRING(Ptr);
        RECEIVE_STRING(Ptr,10);
    }

    return;
}