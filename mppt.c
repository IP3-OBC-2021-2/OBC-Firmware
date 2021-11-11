
#include <xc.h>
#include "mppt.h"
#include "anlg.h"
#include "pwm.h"

void config_mppt(void){
    TRISA|=0b00001111;
    uint8_t pwm_val=0;
    config_analog(12);
    config_pwm();
    PWM_escribir(pwm_val);
}

void init_mppt(uint8_t valor0_pwm){
    PWM_escribir(valor0_pwm);
}

void mppt(double* P_anterior, uint8_t* pwm_anterior, uint8_t VrefV, uint8_t VrefI, short res_ADC){
        unsigned Vbits=leer_analogico(0,1);
        unsigned Ibits=leer_analogico(1,0);
        
        double V=Vbits*VrefV/res_ADC;                        //V
        double I=((Ibits*VrefI-2.5*res_ADC))/res_ADC/0.185;  //A
        
        double P=V*I;
        
        if (P>*P_anterior){
            if (*pwm_anterior<255){
            *pwm_anterior+=1;
            }
        } else if (P<*P_anterior){
            if (*pwm_anterior>0){
            *pwm_anterior-=1;
            }
        }
        
        *P_anterior=P;
        PWM_escribir(*pwm_anterior);
}