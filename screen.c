/*
 * File:   screen.c
 * Author: Tuong Vi
 *
 * Created on 23 octobre 2018, 17:25
 */

#include <pic18f4550.h>
#include "screen.h"
#include "glcd.h"

void screen_credits()
{
    
	glcd_FillScreen(0); //efface l'ecran
    //Jeu fait par ...
    
    
	unsigned char string_jeu[3] = { 'H', 'o', '\0' };
	unsigned char string_test[3] = { 'H', 'i', '\0' };
	
	//GLCD ecran d'acceuil pendant 2s

	glcd_SetCursor(54,0);				//place le curseur
	glcd_WriteString(string_jeu,f8X8,1);	//ecrit 
	glcd_SetCursor(35,1);			
	glcd_WriteString(string_test,f8X8,1);	
    
    __delay_ms(100);
}