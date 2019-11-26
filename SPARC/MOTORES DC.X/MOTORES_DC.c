#include <xc.h>
#include "MOTORES_DC.h"
#include "GPIO.h"

void INIT_DC(void) {
    GPIO_RD4_SetDigitalOutput();
    GPIO_RD5_SetDigitalOutput();
    GPIO_RD6_SetDigitalOutput();
}

void MOV_R_DC(void) {
    GPIO_RD4_SetHigh();
    GPIO_RD5_SetHigh();
    GPIO_RD6_SetLow();
}

void MOV_L_DC(void) {
    GPIO_RD4_SetHigh();
    GPIO_RD6_SetHigh();
    GPIO_RD5_SetLow();
}

void MOV_STOP_DC(void) {
    GPIO_RD4_SetLow();
    GPIO_RD6_SetLow();
    GPIO_RD5_SetLow();

}