/*
 * File:   game.c
 * Author: Tuong Vi
 *
 * Created on 23 octobre 2018, 17:24
 */
#include <pic18f4550.h>

#include "main.h"
#include "microgochi.h"
#include "glcd.h"
#include "myglcd.h"
#include "game.h"
#include "menu.h"


//fonction de jeu
void game_play()
{
    //initialisation des variables
    glcd_FillScreen(0); 
    // ETAPE 1: on affiche notre menu de base
    glcd_SetCursor(0,0);	
    glcd_Image();
   
    menu_cursor (-1, 1); //0 pour initialiser
    
    
    int action=0; //pour le menu
    int write=0;
    int button_pressed=0;
    
   // ETAPE 2: gni
    while (mGogo->vivant==1) //tant que le microgochi est vivant
    {
            //si on appuie sur le bouton de gauche
        
        if (button_pressed==0)
        {
            if (BUTTON_LEFT == 1)
            {
               button_pressed=1;//blindage pour pas que ça bouge 100 fois
               
               menu_cursor (action, GLCD_ERASE); //on efface le curseur menu precedent
               action--; //on decremente le menu
               if (action < 0) //blindage
               {
                   action=0;
               }
                menu_cursor (action, GLCD_WRITE); //on affiche le curseur bougé
               
           }
            //ou si on appuie sur le bouton de droite
            else if (BUTTON_RIGHT == 1)
           {
               button_pressed=1;
               menu_cursor (action, GLCD_ERASE);
                
               action++; //on incremente le menu
               
               if (action > NB_ACTIVITE_MAX) //blindage
               {
                   action= NB_ACTIVITE_MAX;
               }
                menu_cursor (action, GLCD_WRITE);      
           }
             //si on appuie sur le bouton valider, on lance l'action
            else if (BUTTON_MID == 1)
           {
                button_pressed=1;
                menu_actions(action);
           } 
        }
         
        if (BUTTON_LEFT == 0 && BUTTON_MID ==0 && BUTTON_RIGHT == 0)
        {
            button_pressed=0;
        }         
    }
}



