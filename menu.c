/* 
 * File:   menu.c
 * Author: Tuong Vi
 *
 * Created on 19 novembre 2018, 14:12
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "myglcd.h"
#include "main.h"

#define MENU_INIT_X 12
#define MENU_Y_TOP 10
#define MENU_Y_BOTTOM 50
#define MENU_JUMP 32
/*
 * 
 */

void menu_actions(int action)
{
    //action = 0 : miam
    // 1 = calins
    // 2 = dormir
    // 3 = mini jeu!
    
   //on appelle nos jeux et nos animations
    glcd_SetCursor(0,6);				
	glcd_WriteString("ACTION", f8X8, 1);	
}


//pour afficher le curseur
void menu_cursor(int action, int write)
{
  //write = 0 : effacer --- write = 1 : ecrire
   // action 1 = 1ere icone, etc..
    
    if (action == -1) //initialisation
    {
        displayObject (cursor, MENU_INIT_X, MENU_Y_TOP, CURSOR_X, CURSOR_Y, write);
    } 
    else
    {
        displayObject (cursor, MENU_INIT_X+ MENU_JUMP*action, MENU_Y_TOP, CURSOR_X, CURSOR_Y, write);
    }
    
    
}