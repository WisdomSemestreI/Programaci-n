#include "GPIO.h"
#include <xc.h>
#include <pic18.h>

void INIT_GPIO() {
    //CLOCK FREQUENCY CONFIGURATION
    OSCCON = 0X60; //4 MHz internal oscillator
    //DISABLE PORT´s ANALOG FUNCTIONS
    CMCON = 0XFF; //Comparators OFF, to use PORT_D´s LSN
    CVRCONbits.CVREN = 0; //Comparator Voltage Reference Module OFF
    ADCON1 = 0X0F; //All ports as DIGITAL I/O
}

