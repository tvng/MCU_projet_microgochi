/*
 * File:   screen.c
 * Author: Tuong Vi
 *
 * Created on 23 octobre 2018, 17:25
 */

#include <pic18f4550.h>

//includes KS0108 graphique glcd
#include "glcd.h"


// includes fichier
#include "microgochi.h" 
#include "game.h"
#include "screen.h"


void screen_credits()
{
    glcd_FillScreen(0); //efface l'ecran
    //Jeu fait par ...
    
	
	//GLCD ecran d'acceuil pendant 2s

	glcd_SetCursor(0,0);				//place le curseur
	glcd_WriteString("Projet", f8X8, 1);	//ecrit 
    glcd_SetCursor(0,1);				
	glcd_WriteString("Micro", f8X8, 1);	
    glcd_SetCursor(50,1);				
	glcd_WriteString("gochi",f8X8,1);	
    
	glcd_SetCursor(0,3);		
	glcd_WriteString("ARENDA",f8X8,1);	
    glcd_SetCursor(65,3);		
	glcd_WriteString("RSKI",f8X8,1);	
    glcd_SetCursor(0,4);		
	glcd_WriteString("PAGES",f8X8,1);	
    glcd_SetCursor(0,5);		
	glcd_WriteString("TAO",f8X8,1);	
    
    _delay(1000);
}