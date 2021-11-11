#include <xc.h>
#include "anlg.h"

void config_analog(uint8_t AD_selec){
    ADCON1bits.PCFG=AD_selec; //A/D Port Configuration Control bits: P.268
    ADCON1bits.VCFG=0;      //Vref en AN2 y/o AN3
    ADCON0bits.ADON=1;      //Habilitar conversor AD
    ADCON0bits.CHS=0;       //Canal de lectura AN0 seleccionado
            
    ADCON2bits.ACQT=3;      //A/D Acquisition Time Select bits: 12 TAD
    ADCON2bits.ADCS=5;      //A/D Conversion Clock Select bits; FOSC/16
    ADCON2bits.ADFM=1;      //A/D Result Format Select bit:  Right justified
}

unsigned leer_analogico(uint8_t canal, uint8_t Vref){
    unsigned valor=0;
    ADCON1bits.VCFG=Vref;    //Vref en AN2 y/o AN3 
    ADCON0bits.CHS=canal;   //Selección del canal
    ADCON0bits.GO_DONE=1;   //Proceso de conversión
    
    while(ADCON0bits.GO_DONE==1) //Espera a que termine el proceso
    valor=ADRESH;           //Se almacenna el MSB
    valor=(valor<<8);       //Se mueve el MSB 8 bits a la izquierda
    valor=valor | ADRESL;   //Se almacena el LSB
    
    return valor;
}