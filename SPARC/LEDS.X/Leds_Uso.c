#include <xc.h>
#include "GPIO.h"
#include "LEDS.h"

//OSCILLATOR SOURCE AND DIGITAL I/O CONFIGURATION BITS
#pragma config OSC = IRCIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

//DEBUGGER SETUP CONFIGURATION BITS
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))



void main(void) {
    INIT_GPIO();
    INIT_LEDS();
    
    while(1){
    ERROR_LEDS();
    __delay_ms(1000);
    PROCESO_LEDS();
    __delay_ms(1000);
    TERMINADO_LEDS();
    __delay_ms(1000);
    LEDS_OFF();
    __delay_ms(1000);
    }
    return;
}
