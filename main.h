/* 
 * File:   main.h
 * Author: Tuong Vi
 *
 * Created on 23 octobre 2018, 16:48
 */

#ifndef MAIN_H
#define	MAIN_H

//lib jsais pas quoi
#include <stdio.h>


// DEFINE !!!!!!!! ----------------------- pour les port etc

#define BUTTON_LEFT PORTCbits.RC0
#define BUTTON_MID PORTCbits.RC1
#define BUTTON_RIGHT PORTCbits.RC2

struct Microgochi *mGogo=NULL;    //creation structure Microgochi
unsigned int cpt=0;


#define _XTAL_FREQ 8000000

#endif	/* MAIN_H */
