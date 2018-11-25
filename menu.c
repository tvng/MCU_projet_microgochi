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

#define MENU_INIT_X 10
#define MENU_Y_TOP 10
#define MENU_Y_BOTTOM 50
#define MENU_JUMP 15
/*
 * 
 */

int menu()
{
   int selection=0;
   
   //afficher menu de base
   
   //tant qu'on appuie pas sur 
   
   return selection;
}

//pour afficher les icones de base
void menu_base()
{
    
}

//pour afficher le curseur
void menu_cursor(int action, int write)
{
  //write = 0 : effacer --- write = 1 : ecrire
   // action 1 = 1ere icone, etc..
    
    if (action == 0) //initialisation
    {
        displayObject (cursor, MENU_INIT_X, MENU_Y_TOP, CURSOR_X, CURSOR_Y, write);
    }
    
}