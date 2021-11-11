#include <xc.h>
#include "pwm.h"

void config_pwm(void)
{   
    //Periodo de PWM=(PR2+1)*4*Tosc*Prescaler
    //(1/4.9kHz) = (PR2+1)*4*(1/20MHz)*16
    //PR2+1=63.77
    //PR2=64
    PR2=64;
    TRISCbits.RC1=0;
    
    //PWM Duty Cycle = (CCPRXL:CCPXCON<5:4>) * TOSC * (TMR2 Prescale Value)
    //CCPRXL = Periodo de PWM / Tosc * Prescaler
    //CCPRXL = 1/4.9kHz / (1/20MHz) * 16
    //CCPRXL = 255.1
    //CCPRXL = 255 (100%)
    CCPR1L = 0;
    CCP1CONbits.DC1B = 0;      
    /* Fije el pin  del CCP1 correspondiente como salida */
    TRISCbits.RC2 = 0;
    /************* Configurar TIMER 2 **************/
    /* Definir el prescaler del TMR2 : 16 */
    T2CONbits.T2CKPS = 3;
    /************* Configurar CCP1 en modo PWM *************/
    /*Modo PWM: Activo en Alto*/
    CCP1CONbits.CCP1M = 0b1100;
    /*Activar el timer 2 : ON */
    T2CONbits.TMR2ON = 1;
}

void PWM_escribir(uint8_t valor_pwm){
    unsigned char aux_pwm = (valor_pwm & 0b11);
    valor_pwm = (valor_pwm & 0b1111111100);
    valor_pwm = (valor_pwm>>2);
    CCPR1L=valor_pwm;
    CCP1CONbits.DC1B=aux_pwm;
}


