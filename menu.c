/* 
 * File:   menu.c
 * Author: Tuong Vi
 *
 * Created on 19 novembre 2018, 14:12
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "screen.h"
#include "microgochi.h"
#include "myglcd.h"
#include "main.h"

//pour afficher le curseur
void menu_cursor(int action, int write)
{
  //write = 0 : effacer --- write = 1 : ecrire
   // ATTENTION
    //action 0 = 1ere icone
    // action 7 = DERNIERE ICONE
    
    if (action == -1) //initialisation
    {
        displayObject (cursor, MENU_INIT_X, MENU_Y_TOP, CURSOR_X, CURSOR_Y, write);
    } 
    else if (action<4)
    {
        displayObject (cursor, MENU_INIT_X+ MENU_JUMP*action, MENU_Y_TOP, CURSOR_X, CURSOR_Y, write);
    }
    else
    {
        displayObject (cursor, MENU_INIT_X+ MENU_JUMP*(action-4), MENU_Y_BOTTOM, CURSOR_X, CURSOR_Y, write);
    }        
}

void menu_actions(int action)
{
    //action = 0 : miam
    // 1 = calins
    //etc. ALLEZ VOIR  menu.H pour les  #DEFINE
    if (action == ACTION_MANGER) //manger
    {
        micro_manger();
    }
    if (action == ACTION_STATS) //manger
    {
        screen_afficher_stats();
    }
    
   //on appelle nos jeux et nos animations
    glcd_SetCursor(0,6);				
	glcd_WriteString("ACTION", f8X8, 1);	
}