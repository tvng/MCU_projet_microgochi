/*
 * File:   game.c
 * Author: Tuong Vi
 *
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
#include "itoa.h"

char buffer[3];
int cpt=0;
//int cpt_anim=0;

//fonction de jeu
void game_play()
{
    
    //initialisation des variables
    glcd_FillScreen(0); 
    // ETAPE 1: on affiche notre menu de base
    glcd_SetCursor(0,0);	
    glcd_Image();
   
    menu_cursor (-1, 1); //0 pour initialiser
    
    animation();
    int action=0; //pour le menu
    int write=0;
    int button_pressed=0;
    
    int cpt_dodo;
    
   // ETAPE 2: gni
    while (mGogo.vivant==1) //tant que le microgochi est vivant
    {
        
        //anim();
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
                   action=NB_ACTIVITE_MAX;
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
                   action= 0;
               }
                menu_cursor (action, GLCD_WRITE);      
           }
             //si on appuie sur le bouton valider, on lance l'action
            else if (BUTTON_MID == 1)
           {
                button_pressed=2;
           } 
        }
         
        if (BUTTON_LEFT == 0 && BUTTON_MID ==0 && BUTTON_RIGHT == 0 && button_pressed!=0)
        {
            if (button_pressed==2)
            {     
                menu_actions(action);
                glcd_SetCursor(0,0);	
                glcd_Image();
                menu_cursor (action, GLCD_WRITE);  
            }
            button_pressed=0;
        } 
        
        
        
        if(mGogo.dodo==1){//le booleen est remis a 0 apres 10 cpt
            animationDodo();
            cpt_dodo++;
                if (cpt_dodo==30)
                {cpt_dodo=0; ///reset
                    mGogo.dodo=0;
                    displayObject (Z1, 88, 20, 6, 6, 0);
                    displayObject (Z2, 95, 18, 4, 4, 0);
                }
        }
        else if(mGogo.satiete < 50){
            animationPasContent();
        } else if(mGogo.dodo!=1){
                animation();
        }
           
        
        if(mGogo.caca <=50){
            animationCaca();
        }else{
            displayObject (champi, 30, 37, 9, 14, 0);
            displayObject (mouche, 32, 32, 4, 6, 0);
        }
        
        
    
    } //les conditions de mort sont dans les interrupt dans le main
    
    glcd_FillScreen(0); 
   
    glcd_SetCursor(0,0);
    
    glcd_WriteString("RIP", f8X8, 1);	//ecrit 

    animationDead();
    
}


void game_stats()
{
    glcd_FillScreen(0); //efface l'ecran
    glcd_SetCursor(0,0);				//place le curseur
	glcd_WriteString("Stats:", f8X8, 1);	//ecrit 

    glcd_SetCursor(50,0);		
	glcd_WriteString("RC2=exit",f8X8,1);

    int sortie_enable=0;
    
    do 
    {
        glcd_SetCursor(0,2);
        glcd_WriteString("Faim:",f8X8,1);
        glcd_SetCursor(50,2);
        itoa(mGogo.satiete, buffer);
        glcd_WriteString(buffer,f8X8,1);
        memset(&buffer, 0, sizeof(buffer));
        
        glcd_SetCursor(0,3);
        glcd_WriteString("Energie:",f8X8,1);
        glcd_SetCursor(65,3);
        itoa(mGogo.energie, buffer);
        glcd_WriteString(buffer,f8X8,1);
        memset(&buffer, 0, sizeof(buffer));
        
        glcd_SetCursor(0,4);
        glcd_WriteString("Amour:",f8X8,1);
        glcd_SetCursor(55,4);
        itoa(mGogo.bonheur, buffer);
        glcd_WriteString(buffer,f8X8,1);
        memset(&buffer, 0, sizeof(buffer));
        
        glcd_SetCursor(0,5);
        glcd_WriteString("Propre:",f8X8,1);
        glcd_SetCursor(60,5);
        itoa(mGogo.caca, buffer);
        glcd_WriteString(buffer,f8X8,1);
        memset(&buffer, 0, sizeof(buffer));
        
        glcd_SetCursor(0,6);
        glcd_WriteString("Age:",f8X8,1);
        glcd_SetCursor(30,6);
        itoa(mGogo.age, buffer);
        glcd_WriteString(buffer,f8X8,1);
        memset(&buffer, 0, sizeof(buffer));
        
        
        if (BUTTON_MID==1)
        {
            sortie_enable=1;
        }
        
        
    }while(sortie_enable != 1 && BUTTON_MID!=1); //une fois qu'on a appuyé sur RC2 et qu'on a relaché
     
    glcd_FillScreen(0); //efface l'ecran
}
/*
void anim()
{
    displayObject (gochi_corps, 52, 23, 24, 34, 1);
    displayObject (gochi_oreilles1, 52, 23, 7, 34, 1);
    displayObject (gochi_yeux1, 52, 33, 3, 34, 1);
    
    if (PIR1bits.TMR1IF==1) // Ici le bit TMR0IF (bit2) du registre INTCON est testé
    { 

        cpt_anim++;
    	PIE1bits.TMR1IE = 1; 
        PIR1bits.TMR1IF = 0; //on baisse le flag
    
    }

        if (cpt_anim==1)
        {
            displayObject (gochi_oreilles1, 52, 23, 7, 34, 0);
            displayObject (gochi_oreilles2, 52, 23, 7, 34, 1);   
        }
    
        if (cpt_anim==2)
        {
            displayObject (gochi_oreilles2, 52, 23, 7, 34, 0);  
        }
          
}*/

void animation()
{
    /*displayObject (gochiDodo, 75, 35, 2, 8, 0);
    displayObject (Z1, 88, 20, 6, 6, 0);
    displayObject (Z2, 95, 18, 4, 4, 0);
    
    displayObject (gochiPasContent, 75, 33, 4, 8, 0);*/
    
    
    displayObject (gochi_corps, 52, 23, 24, 34, 1);
    displayObject (gochi_oreilles1, 52, 23, 7, 34, 1);
    displayObject (gochi_yeux1, 52, 33, 3, 34, 1);
    //displayObject (gochi_oreilles1, 52, 23, 7, 34, 0);
    //displayObject (gochi_oreilles2, 52, 23, 7, 34, 1);
    //displayObject (gochi_oreilles2, 52, 23, 7, 34, 0);
/*
    //running loop for 5 times produces 0.5 s delay
    //for(int i=0;i<=5;i++){//DELAY????
        T3CONbits.TMR3ON=1;//run timer
        while(!PIR2bits.TMR3IF);//wait for flag to overflow
        T3CONbits.TMR3ON=0;//switch off timer
        PIR2bits.TMR3IF=0;//clear interrupt
    //}
    displayObject (gochi_oreilles1, 52, 23, 7, 34, 0);
    displayObject (gochi_oreilles2, 52, 23, 7, 34, 1);

    //for(int i=0;i<=5;i++){
        T3CONbits.TMR3ON=1;//run timer
        while(!PIR2bits.TMR3IF);//wait for flag to overflow
        T3CONbits.TMR3ON=0;//switch off timer
        PIR2bits.TMR3IF=0;//clear interrupt
    //}
    displayObject (gochi_oreilles2, 52, 23, 7, 34, 0);*/
}

void animationDodo(){
    displayObject (gochi_corps, 52, 23, 24, 34, 1);
    displayObject (gochi_oreilles1, 52, 23, 7, 34, 1);
    //displayObject (gochi_yeux1, 52, 33, 3, 34, 1);
    displayObject (gochiDodo, 75, 35, 2, 8, 1);
    //displayObject (gochiDodo, 75, 35, 2, 8, 0);
    displayObject (Z1, 88, 20, 6, 6, 1);
    displayObject (Z2, 95, 18, 4, 4, 1);
    
       /* T3CONbits.TMR3ON=1;//run timer
        while(!PIR2bits.TMR3IF);//wait for flag to overflow
        T3CONbits.TMR3ON=0;//switch off timer
        PIR2bits.TMR3IF=0;//clear interrupt
        
    displayObject (Z1, 88, 20, 6, 6, 0);
    displayObject (Z2, 95, 18, 4, 4, 1);

        T3CONbits.TMR3ON=1;//run timer
        while(!PIR2bits.TMR3IF);//wait for flag to overflow
        T3CONbits.TMR3ON=0;//switch off timer
        PIR2bits.TMR3IF=0;//clear interrupt

    displayObject (Z2, 95, 18, 4, 4, 0);*/
}

void animationCaca(){
    displayObject (champi, 30, 37, 9, 14, 1);
    displayObject (mouche, 32, 32, 4, 6, 1);
/*
        T3CONbits.TMR3ON=1;//run timer
        while(!PIR2bits.TMR3IF);//wait for flag to overflow
        T3CONbits.TMR3ON=0;//switch off timer
        PIR2bits.TMR3IF=0;//clear interrupt
        
    displayObject (mouche, 32, 32, 4, 6, 0);
    displayObject (mouche, 31, 33, 4, 6, 1);

        T3CONbits.TMR3ON=1;//run timer
        while(!PIR2bits.TMR3IF);//wait for flag to overflow
        T3CONbits.TMR3ON=0;//switch off timer
        PIR2bits.TMR3IF=0;//clear interrupt

    displayObject (mouche, 31, 33, 4, 6, 0);*/
}

void animationDead(){
    displayObject (gochi_corps, 52, 23, 24, 34, 1);
    displayObject (gochi_oreilles1, 52, 23, 7, 34, 1);
    //displayObject (gochi_yeux1, 52, 33, 3, 34, 0);
    displayObject (gochiMort, 75, 33, 3, 8, 1);
    /*
        T3CONbits.TMR3ON=1;//run timer
        while(!PIR2bits.TMR3IF);//wait for flag to overflow
        T3CONbits.TMR3ON=0;//switch off timer
        PIR2bits.TMR3IF=0;//clear interrupt*/
}

void animationPasContent(){
    displayObject (gochi_corps, 52, 23, 24, 34, 1);
    displayObject (gochi_oreilles1, 52, 23, 7, 34, 1);
    //displayObject (gochi_yeux1, 52, 33, 3, 34, 0);
    displayObject (gochiPasContent, 75, 33, 4, 8, 1);
/*
        T3CONbits.TMR3ON=1;//run timer
        while(!PIR2bits.TMR3IF);//wait for flag to overflow
        T3CONbits.TMR3ON=0;//switch off timer
        PIR2bits.TMR3IF=0;//clear interrupt
    
    displayObject (gochi_oreilles1, 52, 23, 7, 34, 0);
    displayObject (gochi_oreilles2, 52, 23, 7, 34, 1);

        T3CONbits.TMR3ON=1;//run timer
        while(!PIR2bits.TMR3IF);//wait for flag to overflow
        T3CONbits.TMR3ON=0;//switch off timer
        PIR2bits.TMR3IF=0;//clear interrupt

    displayObject (gochi_oreilles2, 52, 23, 7, 34, 0);*/
}

