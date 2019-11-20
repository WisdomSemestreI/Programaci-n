#ifndef ADC
#define ADC

//Variables para guardar los bits de los registros ADRESL y ADRESH
unsigned char LSB;
unsigned char MSB;

//Selecci�n de puerto an�logo
#define ADC_SelAN0()      (do{ ADCON0bits.CHS = 0b000000;} while(0))   
#define ADC_SelAN1()      (do{ ADCON0bits.CHS = 0b000001;} while(0))
#define ADC_SelAN2()      (do{ ADCON0bits.CHS = 0b000010;} while(0))
#define ADC_SelAN3()      (do{ ADCON0bits.CHS = 0b000011;} while(0))
#define ADC_SelAN4()      (do{ ADCON0bits.CHS = 0b000100;} while(0))
#define ADC_SelAN5()      (do{ ADCON0bits.CHS = 0b000101;} while(0))
#define ADC_SelAN6()      (do{ ADCON0bits.CHS = 0b000110;} while(0))
#define ADC_SelAN7()      (do{ ADCON0bits.CHS = 0b000111;} while(0))
#define ADC_SelAN8()      (do{ ADCON0bits.CHS = 0b001000;} while(0))
#define ADC_SelAN9()      (do{ ADCON0bits.CHS = 0b001001;} while(0))
#define ADC_SelAN10()     (do{ ADCON0bits.CHS = 0b001010;} while(0))

//Activaci�n de la conversi�n
#define ADC_GoADC()       (do{ADCON0bits.GO = 1;} while(0))

//Habilitar o Deshabilitar m�dulo convertidor
#define ADC_EnADC()       (do{ADCON0bits.ADON = 1;}while(0))
#define ADC_DisADC()      (do{ADCON0bits.ADON = 0;}while(0))

//Bits para utilizar Voltage de Referencia
#define ADC_VrefP()       (do{ADCON1bits.VCFG0 = 1;}while(0))
#define ADC_VredN()       (do{ADCON1bits.VCFG1 = 1;}while(0))
#define ADC_NoVref()      (do{ADCON1bits.VCFG = 0;}while(0))

//Configuraci�n de los puertos anal�gos
#define ADC_ActAN0()      (do{ADCON1bits.PCFG = 0xE;} while()0)
#define ADC_ActAN0to1()   (do{ADCON1bits.PCFG = 0xD;} while(0))
#define ADC_ActAN0to2()   (do{ADCON1bits.PCFG = 0xC;} while(0))
#define ADC_ActAN0to3()   (do{ADCON1bits.PCFG = 0xB;} while(0))
#define ADC_ActAN0to4()   (do{ADCON1bits.PCFG = 0xA;} while(0))
#define ADC_ActAN0to5()   (do{ADCON1bits.PCFG = 0x9;} while(0))
#define ADC_ActAN0to6()   (do{ADCON1bits.PCFG = 0x8;} while(0))
#define ADC_ActAN0to7()   (do{ADCON1bits.PCFG = 0x7;} while(0))
#define ADC_ActAN0to8()   (do{ADCON1bits.PCFG = 0x6;} while(0))
#define ADC_ActAN0to9()   (do{ADCON1bits.PCFG = 0x5;} while(0))
#define ADC_ActAN0to10()  (do{ADCON1bits.PCFG = 0x4;} while(0))

//Selecci�n de justificaci�n
#define ADC_RightJust()   (do{ADCON2bits.ADFM = 1;}while(0))
#define ADC_LeftJust()    (do{ADCON2bits.ADFM = 0;}while(0))

//Selecci�n del tiempo de adquisici�n
#define ADC_TACQ_20TAD()  (do{ADCON2bits.ACQT = 0b111;} while(0))
#define ADC_TACQ_16TAD()  (do{ADCON2bits.ACQT = 0b110;} while(0))
#define ADC_TACQ_12TAD()  (do{ADCON2bits.ACQT = 0b101;} while(0))
#define ADC_TACQ_8TAD()   (do{ADCON2bits.ACQT = 0b100;} while(0))
#define ADC_TACQ_6TAD()   (do{ADCON2bits.ACQT = 0b011;} while(0))
#define ADC_TACQ_4TAD()   (do{ADCON2bits.ACQT = 0b010;} while(0))
#define ADC_TACQ_2TAD()   (do{ADCON2bits.ACQT = 0b001;} while(0))
#define ADC_TACQ_0TAD()   (do{ADCON2bits.ACQT = 0b000;} while(0))

//Selecci�n del tiempo de conversi�n
#define ADC_ConvClkRC()   (do{ADCON2bits.ADCS = 0b111;} while(0))
#define ADC_ConvClk64()   (do{ADCON2bits.ADCS = 0b110;} while(0))
#define ADC_ConvClk16()   (do{ADCON2bits.ADCS = 0b101;} while(0))
#define ADC_ConvClk4()    (do{ADCON2bits.ADCS = 0b100;} while(0))
#define ADC_ConvClkrc()   (do{ADCON2bits.ADCS = 0b011;} while(0))
#define ADC_ConvClk32()   (do{ADCON2bits.ADCS = 0b010;} while(0))
#define ADC_ConvClk8()    (do{ADCON2bits.ADCS = 0b001;} while(0))
#define ADC_ConvClk2()    (do{ADCON2bits.ADCS = 0b000;} while(0))

void ADC_CONVERT_A_D(void);




#endif