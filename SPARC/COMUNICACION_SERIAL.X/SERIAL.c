#include "UART.h"
#include "SERIAL.h"
#include <xc.h>

void SEND_STRING(unsigned char *PointString) {
    for (unsigned char i = 0; i < 255; i++) {
        if (PointString[i] == NULL) {
            break;
        }
        SEND_UART(PointString[i]);
        //__delay_ms(300);
    }
}


void RECEIVE_STRING(unsigned char *guardarscan, unsigned char numcaracteres) {
    for (unsigned char i = 0; i < numcaracteres; i++) {
        guardarscan[i] = RECEIVE_UART();
    }
}
