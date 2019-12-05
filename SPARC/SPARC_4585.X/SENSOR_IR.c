#include "SENSOR_IR.h"
#include <xc.h>
#include "ADC.h"
#include <math.h>
#include "UART.h"

unsigned char DISTANCIA() {
    
    analog_value = (MSB << 8) + LSB;
    
    float Distancia = (3143)*(pow(analog_value,-1.061));
    
    return Distancia;

}