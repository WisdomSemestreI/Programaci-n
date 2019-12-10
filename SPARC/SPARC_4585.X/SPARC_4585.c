#include <xc.h>
#include "BOTONES.h"
#include "CONFIG4585.h"
#include "GPIO.h"
#include "MOTORES_DC.h"
#include "SERIAL.h"
#include "STEP_MOTOR.h"
#include "UART.h"
#include "MENSAJES.h"
#include "LEDS.h"

void __interrupt() INT_isr(void); //Function for Interruptions

void INIT_INT(void); //Initialization of interruptions 0 to 1

unsigned char BuscandoHomeX = 0; //Variable to find HomeX
unsigned char BuscandoHomeY = 0; //Variable to find HomeY
unsigned char TaskReceive = 0; //Variable to check if there is an instruction
unsigned char AjusteZ = 0; //Variable to adjust the height
unsigned short X = 0; //Coordinate in X
unsigned short Y = 0; //Coordinate in Y
unsigned short XReceive = 0; //Variable to check if needs X coordinate
unsigned short YReceive = 0; //Variable to check if needs Y coordinate
unsigned short PosicionX = 0; //Position in X
unsigned short PosicionY = 0; //Position in Y
unsigned char NoNull = 0; //The array has no Nulls

void main(void) {
    
    RCREG = 0; //Clean of receive register

    TRISCbits.RC0 = 1;
    TRISAbits.RA4 = 1;

    ////////////////////////////////////////////////////////////////////////////
    ///////////////////////////PORT CLEANING////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    PORTE = 0x00;

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////INITIALIZATIONS/////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    INIT_GPIO(); //Initialization of GPIO
    INIT_INT(); //Initialization of INTERRUPTIONS
    INIT_UART(); //Initialization of UART
    INIT_STEP(); //Initialization of STEP MOTORS
    INIT_BUTTONS(); //Initialization of BUTTONS
    INIT_DC(); //Initialization of DC MOTORS
    INIT_LEDS(); //Initialization of LEDS

    TRISEbits.RE0 = 0; //Actuator

    union {
        unsigned char coordenadas[6];

        struct {
            unsigned char x[3];
            unsigned char y[3];
        } coordenada;
    } Instruccion;

    unsigned char Task = 0; //Variable to save the kind of task: H(HOME), G(GO), T(TOUCH), S(SWEEP)

    while (BuscandoHomeX == 0 || BuscandoHomeY == 0) {
        while (BuscandoHomeX == 0) {
            MOV_L_PASOS_X(300, 0); //Puts X in the origin
        }
        while (BuscandoHomeY == 0) {
            MOV_L_PASOS_Y(300, 0); //Puts Y in the origin
        }
    }
   
    while (AjusteZ == 0) {
        UP_PLATFORM(); //Move platform up
        DOWN_PLATFORM(); //Move platform down
        if (PORTAbits.RA5 == 1) { //If button ok is pressed
            AjusteZ = 1; //The adjust is ready
        }
    }

    while (1) {
        while (TaskReceive == 0) { //Meanwhile Task is not received

            Task = RECEIVE_UART(); //The task is receive and saved in Task

            if (Task != 72 && Task != 71 && Task != 84 && Task != 83) { //Task is wrong
                ERROR_NO_COMANDO(); //The command is wrong
                LEDS_OFF(); //LED off
                ERROR_LEDS(); //Error LED is on
            }
            if (Task == 72) { //Task is HOME
                LEDS_OFF(); //LED off
                PROCESO(); //Is in process
                PROCESO_LEDS(); //Process LED is on
                PORTEbits.RE0 = 0; //Actuator deactivation
                PosicionX = MOV_L_PASOS_X(PosicionX, 0); //Move X to HOME
                PosicionY = MOV_L_PASOS_Y(PosicionY, 0); //Move Y to HOME 
                TERMINADO_LEDS(); //Led of process done is on
                TERMINADO(); //Process is done
                TXSTAbits.TXEN = 0; //Transmit is off
                RCSTAbits.CREN = 0; //Receive is off
                TXSTAbits.TXEN = 1; //Transmit is on
                RCSTAbits.CREN = 1; //Receive is on
            }
            if (Task == 71) { //Task is GO
                LEDS_OFF(); //LED off
                PORTEbits.RE0 = 0; //Actuator deactivation
                TaskReceive = 1; //Task is correctly receive
                XReceive = 0; //X needs a coordinate
                YReceive = 0; //Y needs a coordinate
            }
            if (Task == 84) { //Task is TOUCH
                LEDS_OFF(); //LED off
                PROCESO(); //Is in process
                PROCESO_LEDS(); //Process LED is on
                PORTEbits.RE0 = 0; //Actuator deactivation
                __delay_ms(50); //delay of 50 mS
                PORTEbits.RE0 = 1; //Actuator activation
                __delay_ms(500); //delay of 500 mS
                PORTEbits.RE0 = 0; //Actuator deactivation
                TERMINADO_LEDS(); //Led of process done is on
                TERMINADO(); //Process is done
                TXSTAbits.TXEN = 0; //Transmit is off
                RCSTAbits.CREN = 0; //Receive is off
                TXSTAbits.TXEN = 1; //Transmit is on
                RCSTAbits.CREN = 1; //Receive is on
            }
            if (Task == 83) { //Task is SWEEP
                LEDS_OFF(); //LED off
                PORTEbits.RE0 = 1; //Actuator activation
                TaskReceive = 1; //Task is correctly receive
                XReceive = 0; //X needs a coordinate
                YReceive = 0; //Y needs a coordinate
            }
            RCREG = 0; //Clean of receive register
        }

        while (XReceive == 0 && YReceive == 0) {

            unsigned char *Ptrcoordenadas = (unsigned char*) &Instruccion.coordenadas[0]; //Pointer to coordinates address

            RECEIVE_STRING(Ptrcoordenadas, 6); //Values of coordinates are received

            unsigned short Centenasx = (Instruccion.coordenada.x[0] - 48) * 100; //Hundreds
            unsigned short Decenasx = (Instruccion.coordenada.x[1] - 48) * 10; //Tens
            unsigned short Unidadx = Instruccion.coordenada.x[2] - 48; //Units

            X = Centenasx + Decenasx + Unidadx; //Decimal value of X

            unsigned short Centenasy = (Instruccion.coordenada.y[0] - 48) * 100; //Hundreds
            unsigned short Decenasy = (Instruccion.coordenada.y[1] - 48) * 10; //Tens
            unsigned short Unidady = Instruccion.coordenada.y[2] - 48; //Units

            Y = Centenasy + Decenasy + Unidady; //Decimal value of Y
            
            if (Instruccion.coordenada.x[0] == NULL || Instruccion.coordenada.y[0] == NULL) {
                FALTA_DATO();
                NoNull = 1;
            }
            if (Instruccion.coordenada.x[1] == NULL || Instruccion.coordenada.y[1] == NULL) {
                FALTA_DATO();
                NoNull = 1;
            }
            if (Instruccion.coordenada.x[2] == NULL || Instruccion.coordenada.y[2] == NULL) {
                FALTA_DATO();
                NoNull = 1;
            }

            if (NoNull == 0) {
                if (X > 300 || Y > 300) { //Coordinates are bigger than the workspace
                    ERROR_FUERA_LIMITE();
                    ERROR_LEDS(); //Error LED is on
                }
                if (X < 301 && Y < 301) { //Coordinates are correct
                    LEDS_OFF(); //LED off
                    PROCESO(); //Is in process
                    PROCESO_LEDS(); //Process LED is on
                    if (PosicionX < X) { //X position is lower than the desired
                        TXSTAbits.TXEN = 0; //Transmit is off
                        RCSTAbits.CREN = 0; //Receive is off
                        PosicionX = MOV_R_PASOS_X(PosicionX, X); //Move X to the right
                    }
                    if (PosicionX > X) { //X position is higher than the desired
                        TXSTAbits.TXEN = 0; //Transmit is off
                        RCSTAbits.CREN = 0; //Receive is off
                        PosicionX = MOV_L_PASOS_X(PosicionX, X); //Move X to the left
                    }
                    if (PosicionY < Y) { //La posicion y actual es menor a la deseada
                        TXSTAbits.TXEN = 0; //Transmit is off
                        RCSTAbits.CREN = 0; //Receive is off
                        PosicionY = MOV_R_PASOS_Y(PosicionY, Y); //Move Y to the right
                    }
                    if (PosicionY > Y) { //La posicion Y actual es mayor a la deseada
                        TXSTAbits.TXEN = 0; //Transmit is off
                        RCSTAbits.CREN = 0; //Receive is off
                        PosicionY = MOV_L_PASOS_Y(PosicionY, Y); //Move Y to the left
                    }
                    TXSTAbits.TXEN = 1; //Transmit is on
                    RCSTAbits.CREN = 1; //Receive is on
                    TERMINADO_LEDS(); //Led of process done is on
                    TERMINADO(); //Process is done
                    TaskReceive = 0; //A new task is needed
                    XReceive = 1; //X was received
                    YReceive = 1; //Y was received
                }
            }
            NoNull = 0;
            RCREG = 0;//Clean of receive register
        }
    }
}

void __interrupt() INT_isr(void) {
    if (INTCONbits.INT0IF == 1) {
        MOV_L_PASOS_X(50, 0); //Move X to the left
        MOV_L_PASOS_Y(50, 0); //Move Y to the left
        INTCONbits.INT0IF = 0; //Clear Interruption Flag 0
        INTCON3bits.INT1IF = 0; //Clear Interruption Flag 1
        INTCON3bits.INT2IF = 0; //Clear Interruption Flag 1
    }
    if (INTCON3bits.INT1IF == 1) {
        MOV_R_PASOS_X(0, 10); //Adjust X
        BuscandoHomeX = 1; //HomeX was found
        INTCONbits.INT0IF = 0; //Clear Interruption Flag 0
        INTCON3bits.INT1IF = 0; //Clear Interruption Flag 1
        INTCON3bits.INT2IF = 0; //Clear Interruption Flag 1
    }
    if (INTCON3bits.INT2IF == 1) {
        MOV_R_PASOS_Y(0, 10); //Adjust Y
        BuscandoHomeY = 1; //HomeY was found
        INTCONbits.INT0IF = 0; //Clear Interruption Flag 0
        INTCON3bits.INT1IF = 0; //Clear Interruption Flag 1
        INTCON3bits.INT2IF = 0; //Clear Interruption Flag 1
    }
}

void INIT_INT(void) {
    TRISBbits.RB0 = 1; //Set RB0 as Input
    TRISBbits.RB1 = 1; //Set RB1 as Input
    TRISBbits.RB2 = 1; //Set RB2 as Input
    RCONbits.IPEN = 0; //No Priorities
    INTCONbits.GIE = 1; //Enable Interruptions
    INTCONbits.PEIE = 0; //Disables Peripherals Interruptions
    INTCONbits.INT0IE = 1; //Enable INT0
    INTCONbits.INT0IF = 0; //Clear Interruption Flag 0
    INTCON2bits.INTEDG0 = 1; //Interruption 0 Change from 0 to 1
    INTCON2bits.INTEDG1 = 1; //Interruption 1 Change from 0 to 1
    INTCON2bits.INTEDG2 = 1; //Interruption 2 Change from 0 to 1
    INTCON3bits.INT2IP = 1; //INT2 High Priority
    INTCON3bits.INT1IP = 1; //INT1 High Priority
    INTCON3bits.INT2IE = 1; //Enable INT2
    INTCON3bits.INT1IE = 1; //Enable INT1
    INTCON3bits.INT2IF = 0; //Clear Interruption Flag 2
    INTCON3bits.INT1IF = 0; //Clear Interruption Flag 1
}