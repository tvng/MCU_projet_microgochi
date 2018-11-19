/*
 * File:   game.c
 * Author: Tuong Vi
 *
 * Created on 23 octobre 2018, 17:24
 */
#include <pic18f4550.h>

#include "microgochi.h"
#include "glcd.h"
#include "game.h"
#include "menu.h"

//fonction de jeu
void game_play(Microgochi *m)
{
    //initialisation des variables
    
    glcd_FillScreen(0); 
    
    //on affiche notre menu de base
    
    int action=-1; //pour le menu
    
    while (m->vivant==1) //tant que le microgochi est vivant
    {
        
        //on affiche notre microgochi et son animation

        //on prend l'emplacement du curseur en appelant menu()
        action=menu();
        
        //on declance l'action si on appuie sur BUTTON_MID
       //switch sur chaque action, on appelle une fonction correspondante
        
       
        //fin du switch
        
        
    }
}


//dans ces fonctions là, on blinde l'augmentation!
//Au niveau de la décrémentation !! si ca depasse en négatif ou en 0, le microgo meurt : m->vivant == 0;


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