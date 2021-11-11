/* 
 * File:   pwm.h
 * Author: franc
 *
 * Created on 9 de noviembre de 2021, 10:21 AM
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

void config_pwm(void);
void PWM_escribir(uint8_t adc_valor);


#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

