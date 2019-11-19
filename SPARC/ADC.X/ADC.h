#ifndef ADC
#define ADC

//Variables para guardar los bits de los registros ADRESL y ADRESH
unsigned char LSB;
unsigned char MSB;

//Selección de puerto análogo
#define SelAN0()      do{ ADCON0bits.CHS = 0b000000;} while(0)   
#define SelAN1()      do{ ADCON0bits.CHS = 0b000001;} while(0)
#define SelAN2()      do{ ADCON0bits.CHS = 0b000010;} while(0)
#define SelAN3()      do{ ADCON0bits.CHS = 0b000011;} while(0)
#define SelAN4()      do{ ADCON0bits.CHS = 0b000100;} while(0)
#define SelAN5()      do{ ADCON0bits.CHS = 0b000101;} while(0)
#define SelAN6()      do{ ADCON0bits.CHS = 0b000110;} while(0)
#define SelAN7()      do{ ADCON0bits.CHS = 0b000111;} while(0)
#define SelAN8()      do{ ADCON0bits.CHS = 0b001000;} while(0)
#define SelAN9()      do{ ADCON0bits.CHS = 0b001001;} while(0)
#define SelAN10()     do{ ADCON0bits.CHS = 0b001010;} while(0)

//Activación de la conversión
#define GoADC()       do{ADCON0bits.GO = 1;} while(0)

//Habilitar o Deshabilitar módulo convertidor
#define EnADC()       do{ADCON0bits.ADON = 1;}while(0)
#define DisADC()      do{ADCON0bits.ADON = 0;}while(0)

//Bits para utilizar Voltage de Referencia
#define VrefP()       do{ADCON1bits.VCFG0 = 1;}while(0)
#define VredN()       do{ADCON1bits.VCFG1 = 1;}while(0)
#define NoVref()      do{ADCON1bits.VCFG = 0;}while(0)

//Configuración de los puertos analógos
#define ActAN0()      do{ADCON1bits.PCFG = 0xE;} while(0)
#define ActAN0to1()   do{ADCON1bits.PCFG = 0xD;} while(0)
#define ActAN0to2()   do{ADCON1bits.PCFG = 0xC;} while(0)
#define ActAN0to3()   do{ADCON1bits.PCFG = 0xB;} while(0)
#define ActAN0to4()   do{ADCON1bits.PCFG = 0xA;} while(0)
#define ActAN0to5()   do{ADCON1bits.PCFG = 0x9;} while(0)
#define ActAN0to6()   do{ADCON1bits.PCFG = 0x8;} while(0)
#define ActAN0to7()   do{ADCON1bits.PCFG = 0x7;} while(0)
#define ActAN0to8()   do{ADCON1bits.PCFG = 0x6;} while(0)
#define ActAN0to9()   do{ADCON1bits.PCFG = 0x5;} while(0)
#define ActAN0to10()  do{ADCON1bits.PCFG = 0x4;} while(0)

//Selección de justificación
#define RightJust()   do{ADCON2bits.ADFM = 1;}while(0)
#define LeftJust()    do{ADCON2bits.ADFM = 0;}while(0)

//Selección del tiempo de adquisición
#define TACQ_20TAD()  do{ADCON2bits.ACQT = 0b111;} while(0)
#define TACQ_16TAD()  do{ADCON2bits.ACQT = 0b110;} while(0)
#define TACQ_12TAD()  do{ADCON2bits.ACQT = 0b101;} while(0)
#define TACQ_8TAD()   do{ADCON2bits.ACQT = 0b100;} while(0)
#define TACQ_6TAD()   do{ADCON2bits.ACQT = 0b011;} while(0)
#define TACQ_4TAD()   do{ADCON2bits.ACQT = 0b010;} while(0)
#define TACQ_2TAD()   do{ADCON2bits.ACQT = 0b001;} while(0)
#define TACQ_0TAD()   do{ADCON2bits.ACQT = 0b000;} while(0)

//Selección del tiempo de conversión
#define ConvClkRC()   do{ADCON2bits.ADCS = 0b111;} while(0)
#define ConvClk64()   do{ADCON2bits.ADCS = 0b110;} while(0)
#define ConvClk16()   do{ADCON2bits.ADCS = 0b101;} while(0)
#define ConvClk4()    do{ADCON2bits.ADCS = 0b100;} while(0)
#define ConvClkrc()   do{ADCON2bits.ADCS = 0b011;} while(0)
#define ConvClk32()   do{ADCON2bits.ADCS = 0b010;} while(0)
#define ConvClk8()    do{ADCON2bits.ADCS = 0b001;} while(0)
#define ConvClk2()    do{ADCON2bits.ADCS = 0b000;} while(0)

void CONVERT_A_D(void);




#endif