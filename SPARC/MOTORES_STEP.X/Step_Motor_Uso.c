#include <xc.h>
#include "STEP_MOTOR.h"
#include "PWM.h"

//OSCILLATOR SOURCE AND DIGITAL I/O CONFIGURATION BITS
#pragma config OSC = IRCIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

//DEBUGGER SETUP CONFIGURATION BITS
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))

void INIT_UART(void);
void SEND_UART(unsigned char TX_Data);
unsigned char RECEIVE_UART();

#define _XTAL_FREQ 4000000
unsigned char TX_Data;
unsigned char RX_Data;

void main(void) {

    //CLOCK FREQUENCY CONFIGURATION
    OSCCON = 0X60; //4 MHz internal oscillator
    //DISABLE PORT´s ANALOG FUNCTIONS
    CMCON = 0XFF; //Comparators OFF, to use PORT_D´s LSN
    CVRCONbits.CVREN = 0; //Comparator Voltage Reference Module OFF
    ADCON1 = 0X0F; //All ports as DIGITAL I/O

    INIT_UART();
    //INIT_PWM();
    while (1) {
        unsigned short posicion = 0;
        unsigned char Lectura = RECEIVE_UART();
        unsigned short coordenada = Lectura - 48;

        TRISCbits.RC1 = 0; //step x
        TRISDbits.RD1 = 0; //dir x 

        if (posicion < coordenada) {
            PORTDbits.RD1 = 1;
            for (posicion; posicion < coordenada;) {
                for (unsigned char i = 0; i < 5; i++) {
                    PORTCbits.RC1 = 1;
                    __delay_ms(1.25);
                    PORTCbits.RC1 = 0;
                    __delay_ms(1.25);
                }
                posicion++;
            }
            posicion = coordenada;
        }
        SEND_UART(82);
    }

    return;
}

void INIT_UART() {
    ///////////////////////////////////////////////
    //inicialización del módulo USART PIC en el XC8 modo asíncrono, a 8bits,
    //a 9600 baudios
    TRISCbits.TRISC7 = 1; //pin RX como una entrada digital
    TRISCbits.TRISC6 = 0; //pin TX como una salida digital
    TXSTA = 0b00100110; // 8bits, transmisión habilitada, asíncrono, alta velocidad
    RCSTA = 0b10010000; //habilitado el USART PIC, recepción 8 bits,  
    //habilitada, asíncrono
    SPBRG = 25; //((__XTAL_FREQ/BAUD)/64)-1; //para una velocidad de 9600 baudios con un oscilador de 4Mhz
}

void SEND_UART(unsigned char TX_Data) {
    while (TXSTAbits.TRMT == 0) {
    }
    TXREG = TX_Data;
    return;
}

unsigned char RECEIVE_UART() {
    while (PIR1bits.RCIF == 0) {
    }

    RX_Data = RCREG;
    RCREG = 0;
    return RX_Data;
}


