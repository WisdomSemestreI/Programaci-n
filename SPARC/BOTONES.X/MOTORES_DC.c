#include <xc.h>
#include "MOTORES_DC.h"
#include "GPIO.h"

void INIT_DC(void) {
    GPIO_RD4_SetDigitalOutput(); //ENABLE
    GPIO_RD5_SetDigitalOutput(); //IN1
    GPIO_RD6_SetDigitalOutput(); //IN2
    GPIO_RD4_SetHigh(); //ENABLE = TRUE
}

void MOV_R_DC(void) {
    
    GPIO_RD5_SetHigh();
    GPIO_RD6_SetLow();
}

void MOV_L_DC(void) {
    GPIO_RD6_SetHigh();
    GPIO_RD5_SetLow();
}

void MOV_STOP_DC(void) {
    GPIO_RD6_SetLow();
    GPIO_RD5_SetLow();

}