/*
 * File:   game.c
 * Author: Tuong Vi
 *
 * Created on 23 octobre 2018, 17:24
 */
#include <pic18f4550.h>

#include "microgochi.h"
#include "glcd.h"
#include "myglcd.h"
#include "game.h"
#include "menu.h"

#define NB_ACTIVITE_MAX 4

//fonction de jeu
void game_play(Microgochi *m)
{
    //initialisation des variables
    glcd_FillScreen(0); 
    
    
    // ETAPE 1: on affiche notre menu de base
    glcd_SetCursor(0,0);	
    glcd_Image();
   
    int action=1; //pour le menu
    menu_cursor (0, 1); //0 pour initialiser
    int write=0;
    int button_pressed=0;
    
   // ETAPE 2: gni
    while (m->vivant==1) //tant que le microgochi est vivant
    {
            //si on appuie sur le bouton de gauche
            if (PORTCbits.RC0 == 1)
            {
               button_pressed=1;
               
               menu_cursor (action, 0);
               action--; //on decremente le menu
               if (action <= 0) //blindage
               {action=1;
               }
                menu_cursor (action, 1);
               
               glcd_SetCursor(0,6);		
               glcd_WriteString("WEWE",f8X8,1);	
           }
            //ou si on appuie sur le bouton de droite
            else if (PORTCbits.RC2 == 1)
           {
               action++; //on incremente le menu
               
               if (action > NB_ACTIVITE_MAX) //blindage
               {
                   action= NB_ACTIVITE_MAX;
               }
               
               button_pressed=1;
               glcd_SetCursor(0,6);		
               glcd_WriteString("xxxxxxx",f8X8,1);	
           }
             //si on appuie sur le bouton valider
            else if (PORTCbits.RC1 == 1)
           {
                
                glcd_SetCursor(0,6);		
                glcd_WriteString("O",f8X8,1);	
           }
            
         
                
    
         
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