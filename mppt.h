/* 
 * File:   mppt.h
 * Author: franc
 *
 * Created on 10 de noviembre de 2021, 05:49 PM
 */

#ifndef MPPT_H
#define	MPPT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "anlg.h"
#include "pwm.h"
    
void config_mppt(void);
void init_mppt(uint8_t valor0_pwm);
void mppt(double* P_anterior, uint8_t* pwm_anterior, uint8_t VrefV, uint8_t VrefI, short res_ADC);


#ifdef	__cplusplus
}
#endif

#endif	/* MPPT_H */

