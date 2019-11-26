#ifndef UART
#define UART

#define __XTAL_FREQ 4000000

unsigned char RX_Data;


void INIT_UART(void);

void SEND_UART(unsigned char TX_Data);

unsigned char RECEIVE_UART(void);

#endif
