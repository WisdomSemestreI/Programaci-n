#include <xc.h>
#include "STEP_MOTOR.h"

#define _XTAL_FREQ 4000000

void INIT_STEP(void) {
    TRISCbits.RC1 = 0; //step x
    TRISDbits.RD1 = 0; //dir x 
    TRISDbits.RD0 = 0; //En x
    TRISCbits.RC2 = 0; //step y
    TRISDbits.RD3 = 0; //dir y
    TRISDbits.RD2 = 0; //En y
}

unsigned short MOV_R_PASOS_X(unsigned short posicion, unsigned short coordenada) {
    if (posicion < coordenada) {
        PORTDbits.RD0 = 0;
        PORTDbits.RD1 = 1;
        for (; posicion < coordenada; posicion++) {
            for (unsigned char i = 0; i < 5; i++) {
                PORTCbits.RC1 = 1;
                __delay_ms(1);
                PORTCbits.RC1 = 0;
                __delay_ms(1);
            }
        }
        PORTDbits.RD0 = 1;
        posicion = coordenada;
        return posicion;
    }
}

unsigned short MOV_L_PASOS_X(unsigned short posicion, unsigned short coordenada) {
    if (posicion > coordenada) {
        PORTDbits.RD0 = 0;
        PORTDbits.RD1 = 0;
        for (; posicion > coordenada; posicion--) {
            for (unsigned char i = 0; i < 5; i++) {
                PORTCbits.RC1 = 1;
                __delay_ms(1);
                PORTCbits.RC1 = 0;
                __delay_ms(1);
            }
        }
        PORTDbits.RD0 = 1;
        posicion = coordenada;
        return posicion;
    }
}

unsigned short MOV_R_PASOS_Y(unsigned short posicion, unsigned short coordenada) {
    if (posicion < coordenada) {
        PORTDbits.RD2 = 0;
        PORTDbits.RD3 = 1;
        for (; posicion < coordenada; posicion++) {
            for (unsigned char i = 0; i < 5; i++) {
                PORTCbits.RC2 = 1;
                __delay_ms(1);
                PORTCbits.RC2 = 0;
                __delay_ms(1);
            }
        }
        PORTDbits.RD2 = 1;
        posicion = coordenada;
        return posicion;
    }
}

unsigned short MOV_L_PASOS_Y(unsigned short posicion, unsigned short coordenada) {
    if (posicion > coordenada) {
        PORTDbits.RD2 = 0;
        PORTDbits.RD3 = 0;
        for (; posicion > coordenada; posicion--) {
            for (unsigned char i = 0; i < 5; i++) {
                PORTCbits.RC2 = 1;
                __delay_ms(1);
                PORTCbits.RC2 = 0;
                __delay_ms(1);
            }
        }
        PORTDbits.RD2 = 1;
        posicion = coordenada;
        return posicion;
    }
}
