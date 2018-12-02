


/* ************* ATTENTION ************ */

/*
- Il y a des #define a mettre dans le main.h pour definir nos sorties (RB0, RBtruc)
- screen : En rapport avec l'ecran glcd : affichage, credits
- glcd : librairie pour la glcd
- microgochi : structure et actions du microgochi/gestion de la jauge
- game : mecaniques de jeu. Utilise screen et microgochi.
 * Par exemple, on deplace nos curseurs dans game et ca affiche avec screen, ou alors on selectionne une action a faire et ca appelle microgochi
 * un peu comme le découpage "modele - controleur - vue", game ca va être le controleur

 */
     


#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDT = ON // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRT = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRTD = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CPD = OFF // Flash Program Memory Code Protection bit (Code protection off)
//#pragma config DEBUG = ON 

//lib pic
//#include <pic18f4550.h>
#include <xc.h>
//lib jsais pas quoi
#include <stdio.h>


#include "main.h"    // !!!!!!!!!!!!!!!!!!!!!!!!!! ICI on declare des variables globales
#include "glcd.h"
#include "microgochi.h" 
#include "game.h"
#include "screen.h"


#define _XTAL_FREQ 8000000



int main(int argc, char** argv) {

    ADCON1 = 0x0F; //on desactive les entrees analogiques

    // ** init easypic -----------    
    TRISD = 0xff; //PORTD input
    PORTD = 0x00; //Reset PORTD

    TRISC = 0b00000111; //PORTB output
    PORTC = 0b00000000; //Reset PORTB

    ///__**_____________
    
    //T0CON permet de configurer le fonctionnement du timer0
    //timer
    
    /* //CA FAIT BUGGER LE TRUC PUTAINNNNNNNNNNNNNNNNN
    T0CONbits.T0CS = 0; //on choisit l'entree du timer0, 0= quartz interne du PIC
    T0CONbits.PSA =1;
    T0CONbits.T0SE=0;
    T0CONbits.T0PS2=0; //2
    T0CONbits.T0PS1=0; //4
    T0CONbits.T0PS0=1; //256
    
    
    INTCONbits.TMR0IF = 0; //baisse le flag
  //  INTCONbits.PEIE = 1; //peripheral interrupt enable =
	INTCONbits.TMR0IE = 1; //enable interrupt on overflow
    INTCONbits.GIE = 1; //global interrupt Enable
    */
    
    
    T1CONbits.TMR1ON=1;
    T1CONbits.TMR1CS=0; //internal clock
    //T1CONbits.T1CKPS1=1;
    //T1CONbits.T1CKPS0=1;
    T1CONbits.T1CKPS1=0;
    T1CONbits.T1CKPS0=0;
    
    INTCONbits.PEIE = 1; //peripheral interrupt enable =
    PIE1bits.TMR1IE = 1; //enable interrupt on overflow
    PIR1bits.TMR1IF = 0; //baisse le flag
    
    INTCONbits.GIE = 1; //global interrupt Enable
    ////////CETTE LIGNE FAIT BEUGUER MON TIMER PR UNE RAISON QUE JIGNORE 
    //////ET QUD JE LENLEVE RIEN NE FCTIONNE
    /*
    //TIMER3 UTILISE PR ANIMATIONS
    T3CON=0b10010000;
    //TMR3H=0b00001011;//3035 en binaire, sur 16 bits ouBDB en hex
    //TMR3L=0b11011011;//est supposé compter ttes les 0.1s
    TMR3=0xBDB;
    PIR2bits.TMR3IF = 0;
	PIE2bits.TMR3IE = 1;*/
    
    // ******


    int bool_jeu = 1; //boolean pour l'etat du jeu

    glcd_Init(GLCD_ON); //init glcd

    while (bool_jeu == 1) //boucle de jeu
    {

        //on reinitialise les parametres du microgochi
        microgochi_init();

        //on affiche les credits (cf screen.c)
        screen_credits();

        __delay_ms(1000);

        //un truc qui dit que notre microgochi vient de naitre

        //on lance notre jeu     
        game_play();

        //si on arrive juste là, notre microgochi est mort&

        //si notre microgochi est mort on quitte la bouche ou alors
        //il faudra revenir sur l'écran d'accueil, à voir
        if (mGogo.vivant == 0) {
            //soit on recommence

            //soit on quitte
            bool_jeu = 0;

        }

    }

    return (EXIT_SUCCESS);
}

void __interrupt() mdr(void)
{
    
    if (PIR1bits.TMR1IF==1) // Ici le bit TMR0IF (bit2) du registre INTCON est testé
    { 

        cpt++;
        //cpt_anim++;
    	PIE1bits.TMR1IE = 1; 
        PIR1bits.TMR1IF = 0; //on baisse le flag
    
    }
        /*if(cpt==1){
            displayObject (gochi_corps, 52, 23, 24, 34, 1);
        }
        if(cpt==3){
            displayObject (gochi_corps, 52, 23, 24, 34, 0);
        }*/
    
        if (cpt==90)
        {
            mGogo.satiete -= 10;   
        }
         
         if (cpt==30)
        {
            mGogo.energie--;   
            
            mGogo.bonheur--;
        }
        
         if (cpt==300)
        {
            mGogo.age++; 
            cpt=0;
        }   
        
        
        
        
}
