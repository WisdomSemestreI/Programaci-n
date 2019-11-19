#ifndef UART
#define UART

unsigned char RX_Data;

void INIT_UART(void);

void SEND_UART(unsigned char TX_Data);

unsigned char RECEIVE_UART(void);

#endif
