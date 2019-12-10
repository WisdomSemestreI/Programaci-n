#include <xc.h>
#include "UART.h"


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
    unsigned long Cont = 0;
    while (PIR1bits.RCIF == 0) {
        if (Cont == 750000) {
            return NULL;
        }
        Cont++;
    }
    RX_Data = RCREG;
    RCREG = 0;
    return RX_Data;
}
