#include "GPIO.h"
#include "LEDS.h"
#include <xc.h>

void INIT_LEDS(void) {
    GPIO_RB5_SetDigitalOutput();
    GPIO_RB6_SetDigitalOutput();
    GPIO_RB7_SetDigitalOutput();
}

void LEDS_OFF(void) {
    GPIO_RB5_SetLow();
    GPIO_RB6_SetLow();
    GPIO_RB7_SetLow();
}

void ERROR_LEDS(void) {
    GPIO_RB5_SetHigh();
    GPIO_RB6_SetLow();
    GPIO_RB7_SetLow();
}

void PROCESO_LEDS(void) {
    GPIO_RB5_SetLow();
    GPIO_RB6_SetLow();
    GPIO_RB7_SetHigh();
}

void TERMINADO_LEDS(void) {
    GPIO_RB5_SetLow();
    GPIO_RB6_SetHigh();
    GPIO_RB7_SetLow();
}
