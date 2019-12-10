#include "MENSAJES.h"
#include "UART.h"
#include "SERIAL.h"
#include <xc.h>

void ERROR_NO_COMANDO() {
    SEND_UART(10);
    SEND_STRING("Comando no reconocido");
    SEND_UART(13);
}

void ERROR_FUERA_LIMITE() {
    SEND_UART(10);
    SEND_STRING("coordenadas fuera del limite");
    SEND_UART(13);
}

void TERMINADO() {
    SEND_UART(10);
    SEND_STRING("Proceso completado");
    SEND_UART(13);
}

void PROCESO() {
    SEND_UART(10);
    SEND_STRING("En proceso");
    SEND_UART(13);
}

void FALTA_DATO() {
    SEND_UART(10);
    SEND_STRING("Falta Dato");
    SEND_UART(13);
}
