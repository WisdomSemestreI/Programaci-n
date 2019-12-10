#ifndef ADC
#define ADC

#define __XTAL_FREQ 4000000 //Frecuencia del oscilador 
#define MinTAD 70 //Tiempo de conversión mínimo, checar datasheet del integrado, 1us = 100
#define MinTAQC 1286 //Tiempo mínimo de adquisición de datos, checar datasheet, 1us = 100
unsigned short TAD;  //Tiempo de conversión
unsigned short Tosc; //Periodo del oscilador

//Variables para guardar los bits de los registros ADRESL y ADRESH
unsigned char LSB; //Bits menos significativos
unsigned char MSB; //Bits más significativos

//Selección de puerto análogo
#define ADC_SelAN0()      do{ ADCON0bits.CHS = 0b000000;} while(0)
#define ADC_SelAN1()      do{ ADCON0bits.CHS = 0b000001;} while(0)
#define ADC_SelAN2()      do{ ADCON0bits.CHS = 0b000010;} while(0)
#define ADC_SelAN3()      do{ ADCON0bits.CHS = 0b000011;} while(0)
#define ADC_SelAN4()      do{ ADCON0bits.CHS = 0b000100;} while(0)
#define ADC_SelAN5()      do{ ADCON0bits.CHS = 0b000101;} while(0)
#define ADC_SelAN6()      do{ ADCON0bits.CHS = 0b000110;} while(0)
#define ADC_SelAN7()      do{ ADCON0bits.CHS = 0b000111;} while(0)
#define ADC_SelAN8()      do{ ADCON0bits.CHS = 0b001000;} while(0)
#define ADC_SelAN9()      do{ ADCON0bits.CHS = 0b001001;} while(0)
#define ADC_SelAN10()     do{ ADCON0bits.CHS = 0b001010;} while(0)
#ifdef PIC18F4550
#define ADC_SelAN11()     do{ ADCON0bits.CHS = 0b001011;} while(0)
#define ADC_SelAN12()     do{ ADCON0bits.CHS = 0b001100;} while(0)
#endif

//Activación de la conversión
#define ADC_GoADC()       do{ADCON0bits.GO_DONE = 1;} while(0)

//Habilitar o Deshabilitar módulo convertidor
#define ADC_EnADC()       do{ADCON0bits.ADON = 1;}while(0)
#define ADC_DisADC()      do{ADCON0bits.ADON = 0;}while(0)

//Bits para utilizar Voltage de Referencia
#define ADC_VrefP()       do{ADCON1bits.VCFG0 = 1;}while(0)
#define ADC_VrefN()       do{ADCON1bits.VCFG1 = 1;}while(0)
#define ADC_NoVref()      do{ADCON1bits.VCFG = 0;}while(0)

//Configuración de los puertos analógos
#define ADC_ActAN0()      do{ADCON1bits.PCFG = 0xE;} while(0)
#define ADC_ActAN0to1()   do{ADCON1bits.PCFG = 0xD;} while(0)
#define ADC_ActAN0to2()   do{ADCON1bits.PCFG = 0xC;} while(0)
#define ADC_ActAN0to3()   do{ADCON1bits.PCFG = 0xB;} while(0)
#define ADC_ActAN0to4()   do{ADCON1bits.PCFG = 0xA;} while(0)
#define ADC_ActAN0to5()   do{ADCON1bits.PCFG = 0x9;} while(0)
#define ADC_ActAN0to6()   do{ADCON1bits.PCFG = 0x8;} while(0)
#define ADC_ActAN0to7()   do{ADCON1bits.PCFG = 0x7;} while(0)
#define ADC_ActAN0to8()   do{ADCON1bits.PCFG = 0x6;} while(0)
#define ADC_ActAN0to9()   do{ADCON1bits.PCFG = 0x5;} while(0)
#define ADC_ActAN0to10()  do{ADCON1bits.PCFG = 0x4;} while(0)
#ifdef PIC18F4550
#define ADC_ActAN0to11()     do{ ADCON0bits.CHS = 0x3;} while(0)
#define ADC_ActAN0to12()     do{ ADCON0bits.CHS = 0X2;} while(0)
#endif

//Selección de justificación
#define ADC_RightJust()   do{ADCON2bits.ADFM = 1;}while(0)
#define ADC_LeftJust()    do{ADCON2bits.ADFM = 0;}while(0)

//Selección del tiempo de adquisición
#define ADC_TACQ_20TAD()  do{ADCON2bits.ACQT = 0b111;} while(0)
#define ADC_TACQ_16TAD()  do{ADCON2bits.ACQT = 0b110;} while(0)
#define ADC_TACQ_12TAD()  do{ADCON2bits.ACQT = 0b101;} while(0)
#define ADC_TACQ_8TAD()   do{ADCON2bits.ACQT = 0b100;} while(0)
#define ADC_TACQ_6TAD()   do{ADCON2bits.ACQT = 0b011;} while(0)
#define ADC_TACQ_4TAD()   do{ADCON2bits.ACQT = 0b010;} while(0)
#define ADC_TACQ_2TAD()   do{ADCON2bits.ACQT = 0b001;} while(0)
#define ADC_TACQ_0TAD()   do{ADCON2bits.ACQT = 0b000;} while(0)

//Selección del tiempo de conversión
#define ADC_ConvClkRC()   do{ADCON2bits.ADCS = 0b111;} while(0)
#define ADC_ConvClk64()   do{ADCON2bits.ADCS = 0b110;} while(0)
#define ADC_ConvClk16()   do{ADCON2bits.ADCS = 0b101;} while(0)
#define ADC_ConvClk4()    do{ADCON2bits.ADCS = 0b100;} while(0)
#define ADC_ConvClkrc()   do{ADCON2bits.ADCS = 0b011;} while(0)
#define ADC_ConvClk32()   do{ADCON2bits.ADCS = 0b010;} while(0)
#define ADC_ConvClk8()    do{ADCON2bits.ADCS = 0b001;} while(0)
#define ADC_ConvClk2()    do{ADCON2bits.ADCS = 0b000;} while(0)

//Inicialización del ADC
void INIT_ADC(unsigned char NumberOfPorts, unsigned char ON_OFF, unsigned char Resolution);

//Activación de puertos análogos
void ACTIVE_AN(unsigned char Port);

//Resolución de bits: 8 o 10
void RESOLUTION(unsigned char Bits);

//Proceso para convertir de análogo a digital
void ADC_PROCESS(void);

//Conversión análogo a digital
void CONVERT_A_D(void);

//Configuración de voltaje de referencia: 1 = On = Se usa Vref; 0 = Off = No se usa Vref
void VOLTAGE_REF(unsigned char ON_OFF);

//Selección de puerto a leer
void READPORT (unsigned char PortToRead);

#endif