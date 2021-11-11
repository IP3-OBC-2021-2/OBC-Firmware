/* 
 * File:   anlg.h
 * Author: franc
 *
 * Created on 9 de noviembre de 2021, 09:24 AM
 */

#ifndef ANLG_H
#define	ANLG_H

#ifdef	__cplusplus
extern "C" {
#endif

unsigned leer_analogico(uint8_t canal, uint8_t Vref);
void config_analog(uint8_t AD_selec);

#ifdef	__cplusplus
}
#endif

#endif	/* ANLG_H */

