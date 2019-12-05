#ifndef STEP_MOTOR
#define STEP_MOTOR

void INIT_STEP(void);

unsigned short MOV_R_PASOS_X(unsigned short posicion, unsigned short coordenada);

unsigned short MOV_L_PASOS_X(unsigned short posicion, unsigned short coordenada);

unsigned short MOV_R_PASOS_Y(unsigned short posicion, unsigned short coordenada);

unsigned short MOV_L_PASOS_Y(unsigned short posicion, unsigned short coordenada);



#endif