/*
 * File:   microgochi.c
 * Author: Tuong Vi
 *
 * Created on 22 octobre 2018, 17:44
 */
#include "microgochi.h"


void initMicrogochi(struct Microgochi *m)
{
    m->age=0;
    m->satiete=100;
    m->energie=100;
    m->proprete=100;
  
    
    m->vivant=1; //1 pour vivant, 0 pour mort

}