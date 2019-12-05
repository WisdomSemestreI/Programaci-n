#include <xc.h>
#include "ADC.h"

void INIT_ADC(unsigned char NumberOfPorts, unsigned char ON_OFF, unsigned char Resolution) {

    ADC_DisADC();

    ACTIVE_AN(NumberOfPorts);

    VOLTAGE_REF(ON_OFF);

    RESOLUTION(Resolution);

    Tosc = (100000000 / __XTAL_FREQ);

    if ((Tosc * 2) >= MinTAD) {
        TAD = Tosc * 2;
        ADC_ConvClk2();
        if ((2 * TAD) >= MinTAQC) {
            ADC_TACQ_2TAD();
            return;
        }
        if ((4 * TAD) >= MinTAQC) {
            ADC_TACQ_4TAD();
            return;
        }
        if ((6 * TAD) >= MinTAQC) {
            ADC_TACQ_6TAD();
            return;
        }
        if ((8 * TAD) >= MinTAQC) {
            ADC_TACQ_8TAD();
            return;
        }
        if ((12 * TAD) >= MinTAQC) {
            ADC_TACQ_12TAD();
            return;
        }
        if ((16 * TAD) >= MinTAQC) {
            ADC_TACQ_16TAD();
            return;
        }
        if ((20 * TAD) >= MinTAQC) {
            ADC_TACQ_20TAD();
            return;
        }
    }
    if ((Tosc * 4) >= MinTAD) {
        TAD = Tosc * 4;
        ADC_ConvClk4();
        if ((2 * TAD) >= MinTAQC) {
            ADC_TACQ_2TAD();
            return;
        }
        if ((4 * TAD) >= MinTAQC) {
            ADC_TACQ_4TAD();
            return;
        }
        if ((6 * TAD) >= MinTAQC) {
            ADC_TACQ_6TAD();
            return;
        }
        if ((8 * TAD) >= MinTAQC) {
            ADC_TACQ_8TAD();
            return;
        }
        if ((12 * TAD) >= MinTAQC) {
            ADC_TACQ_12TAD();
            return;
        }
        if ((16 * TAD) >= MinTAQC) {
            ADC_TACQ_16TAD();
            return;
        }
        if ((20 * TAD) >= MinTAQC) {
            ADC_TACQ_20TAD();
            return;
        }
    }
    if ((Tosc * 8) >= MinTAD) {
        TAD = Tosc * 8;
        ADC_ConvClk8();
        if ((2 * TAD) >= MinTAQC) {
            ADC_TACQ_2TAD();
            return;
        }
        if ((4 * TAD) >= MinTAQC) {
            ADC_TACQ_4TAD();
            return;
        }
        if ((6 * TAD) >= MinTAQC) {
            ADC_TACQ_6TAD();
            return;
        }
        if ((8 * TAD) >= MinTAQC) {
            ADC_TACQ_8TAD();
            return;
        }
        if ((12 * TAD) >= MinTAQC) {
            ADC_TACQ_12TAD();
            return;
        }
        if ((16 * TAD) >= MinTAQC) {
            ADC_TACQ_16TAD();
            return;
        }
        if ((20 * TAD) >= MinTAQC) {
            ADC_TACQ_20TAD();
            return;
        }
    }
    if ((Tosc * 16) >= MinTAD) {
        TAD = Tosc * 16;
        ADC_ConvClk16();
        if ((2 * TAD) >= MinTAQC) {
            ADC_TACQ_2TAD();
            return;
        }
        if ((4 * TAD) >= MinTAQC) {
            ADC_TACQ_4TAD();
            return;
        }
        if ((6 * TAD) >= MinTAQC) {
            ADC_TACQ_6TAD();
            return;
        }
        if ((8 * TAD) >= MinTAQC) {
            ADC_TACQ_8TAD();
            return;
        }
        if ((12 * TAD) >= MinTAQC) {
            ADC_TACQ_12TAD();
            return;
        }
        if ((16 * TAD) >= MinTAQC) {
            ADC_TACQ_16TAD();
            return;
        }
        if ((20 * TAD) >= MinTAQC) {
            ADC_TACQ_20TAD();
            return;
        }
    }
    if ((Tosc * 32) >= MinTAD) {
        TAD = Tosc * 32;
        ADC_ConvClk32();
        if ((2 * TAD) >= MinTAQC) {
            ADC_TACQ_2TAD();
            return;
        }
        if ((4 * TAD) >= MinTAQC) {
            ADC_TACQ_4TAD();
            return;
        }
        if ((6 * TAD) >= MinTAQC) {
            ADC_TACQ_6TAD();
            return;
        }
        if ((8 * TAD) >= MinTAQC) {
            ADC_TACQ_8TAD();
            return;
        }
        if ((12 * TAD) >= MinTAQC) {
            ADC_TACQ_12TAD();
            return;
        }
        if ((16 * TAD) >= MinTAQC) {
            ADC_TACQ_16TAD();
            return;
        }
        if ((20 * TAD) >= MinTAQC) {
            ADC_TACQ_20TAD();
            return;
        }
        if ((Tosc * 64) >= MinTAD) {
            TAD = Tosc * 64;
            ADC_ConvClk64();
            if ((2 * TAD) >= MinTAQC) {
                ADC_TACQ_2TAD();
                return;
            }
            if ((4 * TAD) >= MinTAQC) {
                ADC_TACQ_4TAD();
                return;
            }
            if ((6 * TAD) >= MinTAQC) {
                ADC_TACQ_6TAD();
                return;
            }
            if ((8 * TAD) >= MinTAQC) {
                ADC_TACQ_8TAD();
                return;
            }
            if ((12 * TAD) >= MinTAQC) {
                ADC_TACQ_12TAD();
                return;
            }
            if ((16 * TAD) >= MinTAQC) {
                ADC_TACQ_16TAD();
                return;
            }
            if ((20 * TAD) >= MinTAQC) {
                ADC_TACQ_20TAD();
                return;
            }
        } else {
            ADC_ConvClkRC();
            ADC_TACQ_0TAD();
        }
    }
}

void VOLTAGE_REF(unsigned char ON_OFF) {
    if (ON_OFF == 0) {
        ADC_NoVref();
        return;
    }
    if (ON_OFF == 1) {
        ADC_VrefN();
        ADC_VrefP();
        return;
    }
    return;
}

void ACTIVE_AN(unsigned char Port) {
    if (Port == 1) {
        ADC_ActAN0();
    }
    if (Port == 2) {
        ADC_ActAN0to1();
    }
    if (Port == 3) {
        ADC_ActAN0to2();
    }
    if (Port == 4) {
        ADC_ActAN0to3();
    }
    if (Port == 5) {
        ADC_ActAN0to4();
    }
    if (Port == 6) {
        ADC_ActAN0to5();
    }
    if (Port == 7) {
        ADC_ActAN0to6();
    }
    if (Port == 8) {
        ADC_ActAN0to7();
    }
    if (Port == 9) {
        ADC_ActAN0to8();
    }
    if (Port == 10) {
        ADC_ActAN0to9();
    }
    if (Port == 11) {
        ADC_ActAN0to10();
    }
#ifdef PIC18F4550
    if (Port == 12) {
        ADC_ActAN0to11();
    }
    if (Port == 13) {
        ADC_ActAN0to12();
    }
#endif
    return;
}

void RESOLUTION(unsigned char Bits) {
    if (Bits == 8) {
        ADC_LeftJust();
    }
    if (Bits == 10) {
        ADC_RightJust();
    }
}

void ADC_PROCESS() {
    ADC_EnADC();
    CONVERT_A_D();
    return;
}

void CONVERT_A_D() {
    ADC_GoADC();
    while (ADCON0bits.GO_DONE == 1) {
    }
    LSB = ADRESL;
    MSB = ADRESH;
    return;
}

void READPORT(unsigned char PortToRead) {
    if (PortToRead == 0) {
        ADC_SelAN0();
    }
    if (PortToRead == 1) {
        ADC_SelAN1();
    }
    if (PortToRead == 2) {
        ADC_SelAN2();
    }
    if (PortToRead == 3) {
        ADC_SelAN3();
    }
    if (PortToRead == 4) {
        ADC_SelAN4();
    }
    if (PortToRead == 5) {
        ADC_SelAN5();
    }
    if (PortToRead == 6) {
        ADC_SelAN6();
    }
    if (PortToRead == 7) {
        ADC_SelAN7();
    }
    if (PortToRead == 8) {
        ADC_SelAN8();
    }
    if (PortToRead == 9) {
        ADC_SelAN9();
    }
    if (PortToRead == 10) {
        ADC_SelAN10();
    }
#ifdef PIC18F4550
    if (PortToRead == 11) {
        ADC_SelAN11();
    }
    if (PortToRead == 12) {
        ADC_SelAN12();
    }
#endif
}