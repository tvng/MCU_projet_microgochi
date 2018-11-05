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
    
    
	unsigned char str_nom1[] = "Projet";
    unsigned char str_nom2[] = "Microg"; 
    unsigned char str_nom3[] = "ochi"; //je dois couper en 2 sinon ça bug
	unsigned char str_a[] ="ARENDA";
    unsigned char str_a2[] ="RSKI";
    unsigned char str_p[] ="PAGES";
    unsigned char str_t[] ="TAO";
	
	//GLCD ecran d'acceuil pendant 2s

	glcd_SetCursor(0,0);				//place le curseur
	glcd_WriteString(str_nom1,f8X8,1);	//ecrit 
    glcd_SetCursor(0,1);				
	glcd_WriteString(str_nom2,f8X8,1);	
    glcd_SetCursor(50,1);				
	glcd_WriteString(str_nom3,f8X8,1);	
    
	glcd_SetCursor(0,3);		
	glcd_WriteString(str_a,f8X8,1);	
    glcd_SetCursor(49,3);		
	glcd_WriteString(str_a2,f8X8,1);	
    glcd_SetCursor(0,4);		
	glcd_WriteString(str_p,f8X8,1);	
    glcd_SetCursor(0,5);		
	glcd_WriteString(str_t,f8X8,1);	
    
    __delay_ms(600);
}