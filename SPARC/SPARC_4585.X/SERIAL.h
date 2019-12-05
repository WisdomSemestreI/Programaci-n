#ifndef SERIAL
#define SERIAL
#define _XTAL_FREQ 4000000

void RECEIVE_STRING (unsigned char *guardarscan, unsigned char numcaracteres);

void SEND_STRING (unsigned char *PointString);


#endif