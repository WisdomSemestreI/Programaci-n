#define _XTAL_FREQ 4000000
#include "GPIO.h"
#include <xc.h>

//OSCILLATOR SOURCE AND DIGITAL I/O CONFIGURATION BITS
#pragma config OSC = IRCIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

//DEBUGGER SETUP CONFIGURATION BITS
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))


int main()
{
  INIT_GPIO();  
  RB0_SetDigitalOutput();
  RA0_SetDigitalOutput();
  RD0_SetDigitalOutput();
  RC0_SetDigitalOutput();
  while(1)
  {
    RB0_SetHigh();
    RD0_SetHigh();
    RA0_SetLow();
    RC0_SetLow();
    __delay_ms(1000); // 1 Second Delay
    RB0_Toggle();
    RD0_Toggle();
    RA0_Toggle();
    RC0_Toggle();
    __delay_ms(1000); // 1 Second Delay
  }
  return 0;
}