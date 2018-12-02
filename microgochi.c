/*
 * File:   microgochi.c
 * Author: Tuong Vi
 *
 * Created on 22 octobre 2018, 17:44
 */
#include <pic18f4550.h>
#include "microgochi.h"
#include "main.h"
#include "game.h"

struct Microgochi mGogo;    //creation structure Microgochi

void microgochi_init()
{
    mGogo.age=0;
    mGogo.satiete=80;
    mGogo.energie=80;
    mGogo.bonheur=80;
    mGogo.vivant=1; //1 pour vivant, 0 pour mort
    mGogo.pos_x= 60;
    mGogo.pos_y= 60;
    
    mGogo.dodo=0;
    mGogo.caca=100; //proprete

}

void micro_vieillir()
{
    mGogo.age++;
    if (mGogo.age>=100)
    {
        mGogo.vivant=0;
        //animationDead();
    }
}

void micro_manger ()
{
    mGogo.satiete += 20;
    mGogo.caca-=40;
}

void micro_calin ()
{
    mGogo.bonheur = mGogo.bonheur + 20;
}

void micro_laver()
{
    mGogo.caca=100;
}

void micro_dormir ()
{
    mGogo.energie += 20;
    mGogo.dodo=1;
}