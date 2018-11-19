/*
 * File:   screen.c
 * Author: Tuong Vi
 *
 * Created on 23 octobre 2018, 17:25
 */

//#include <pic18f4550.h>
#include <xc.h>

//includes KS0108 graphique glcd
#include "glcd.h"


// includes fichier
#include "main.h"
#include "microgochi.h" 
#include "game.h"
#include "screen.h"


const unsigned char ou[8]=
{0x0F, 0x0C, 0xFF, 0x0C, 0x0F, 0x00, 0xFF, 0x1E};

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
    glcd_SetCursor(55,3);		
	glcd_WriteString("RSKI",f8X8,1);	
    glcd_SetCursor(0,4);		
	glcd_WriteString("PAGES",f8X8,1);	
    glcd_SetCursor(0,5);		
	glcd_WriteString("TAO",f8X8,1);	

    
    __delay_ms(1000);
    glcd_FillScreen(0);
        glcd_SetCursor(0,0);		
	//glcd_icon8X8(&ou,1);	
    glcd_Image();
    
    __delay_ms(1000);


}