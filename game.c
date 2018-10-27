/*
 * File:   game.c
 * Author: Tuong Vi
 *
 * Created on 23 octobre 2018, 17:24
 */
#include "main.h"
#include "game.h"


void game_play(Microgochi *m)
{
    while (m->vivant==1) //tant que le microgochi est vivant
    {
        //si on appuie sur 
        
        
        
        
        //quand il meurt
        m->vivant=0;
        
    }
}

  // ********** STATUT : jauges du Microgogo qui diminuent au fil du temps
        
        //toutes les 60s, il grandit d'un jour 
        //toutes les 30s, il perd 10 de satiete
        //toutes les 10s, il perd 10 d'energie
        
        
        // *********** MENU : avec boutons RA0, RA1, RA2 ************
            
        //s'il mange, il gagne 30 de satiete et perd 30 de proprete
        //il dort, il gagne 20 d'energie toutes les 5s
        //S'il dort trop, il perd de l'énergie
        //s'il n'a plus d'énergie il meurt
        //etc cf overleaf
      
        //une fois qu'on arrive a 100 jours, il meurt et on recommence la boucle