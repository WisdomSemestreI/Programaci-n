#include "PWM.h"
#include <xc.h>

void INIT_PWM() {
    //PWM Period =( PR2 + 1 ) * 4 * Tosc * Prescaler
    //PR2 + 1 = PWM Period / 4 * Tosc * Prescaler
    //PR2 + 1 = (1/250Hz) / * 4 * (1/4MHz) * 16
    //PR2 + 1 = 250
    //PR2 = 249  --> F9 Hex

    //PWM Duty Cycle = (ECCPR1L:ECCP1CON<5:4>) * Tosc * Prescaler
    //ECCPR1L = PWM / Tosc * Prescaler
    // = (1/250 Hz)/ (1/4MHz) * 16 = 1000

    //1000 => 100%
    //x    => 50% : x = 500 => 111110100
    //                         01111101  00

    PR2 = 0xF9;
    CCPR1L=0x7D;
    TRISCbits.RC2 = 0;
    T2CON = 0x03; //Prescaler 16  TIMER 2 OFF
    CCP1CON = 0x0C;
    TMR2 = 0;
    T2CONbits.TMR2ON = 1; //TIMER 2 ON
    
}
