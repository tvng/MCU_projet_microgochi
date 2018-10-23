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
    m->fatigue=100;
    m->proprete=100;
    m->amusement=100;

}