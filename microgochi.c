/*
 * File:   microgochi.c
 * Author: Tuong Vi
 *
 * Created on 22 octobre 2018, 17:44
 */
#include <pic18f4550.h>
#include "microgochi.h"



void microgochi_init(Microgochi *m)
{
    m->age=0;
    m->satiete=100;
    m->energie=100;
    m->proprete=100;
    m->vivant=1; //1 pour vivant, 0 pour mort

}