#include <xc.h>
#include "ADC.h"

void CONVERT_A_D() {
    GoADC();
    NOP();
    while (ADCON0bits.GO == 1) {
    }
    NOP();
    LSB = ADRESL;
    MSB = ADRESH;
}

