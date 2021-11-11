/*
 * File:   main.c
 * Author: Franco Bolaños
 *
 * Created on 10 de octubre de 2021, 12:49 PM
 */

//PRIMERO HACER CONFIGURACION SPI Y LUEGO PWM
//ASEGURARSE QUE TRISB<0> SEA DIGITAL

#include <xc.h>
#include <stdint.h>
#include <htc.h>
#include "config.h"
#include "mppt.h"

void IMP_10BITS(signed short valor){
    LATD= valor & 0xFF;
    LATB|= (valor>>6) & 0b00001100;
}

void main(void) {
    double P_anterior=0;
    uint8_t pwm_anterior=0;
    uint8_t VrefV=20;
    uint8_t VrefI=5;
    short res_ADC=1023;
    TRISD=0;
    TRISB=0;
    
    config_mppt();
    init_mppt(10);
    while(1){
        mppt(&P_anterior,&pwm_anterior,VrefV,VrefI,res_ADC);
        IMP_10BITS((short) P_anterior);
    }
    
    return;
}