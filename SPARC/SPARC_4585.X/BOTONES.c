#include <xc.h>
#include "BOTONES.h"
#include "GPIO.h"
#include "MOTORES_DC.h"

void INIT_BUTTONS(void) {
    GPIO_RC4_SetDigitalInput(); //UP BUTTON
    GPIO_RC5_SetDigitalInput(); //DOWN BUTTON
    GPIO_RA5_SetDigitalInput(); //OK BUTTON
}

void UP_PLATFORM(void) {
    while (GPIO_RC4_GetValue() == 1) {
        MOV_R_DC();
    }
    MOV_STOP_DC();

}

void DOWN_PLATFORM(void) {
    while (GPIO_RC5_GetValue() == 1) {
        MOV_L_DC();
    }
    MOV_STOP_DC();
}