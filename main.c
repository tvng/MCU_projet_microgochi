


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

//lib pic
//#include <pic18f4550.h>
#include <xc.h>

#include "main.h"    // !!!!!!!!!!!!!!!!!!!!!!!!!! ICI on declare des variables globales
#include "glcd.h"
#include "microgochi.h" 
#include "game.h"
#include "screen.h"

int main(int argc, char** argv) {
    
    ADCON1 = 0x0F; //on desactive les entrees analogiques
    
    // ** init easypic -----------    
    TRISD = 0xff;			//PORTD input
	PORTD = 0x00; 				//Reset PORTD

	TRISC = 0b00000111;				//PORTB output
	PORTC =0b00000000;					//Reset PORTB
    
    ///__**_____________
    //timer
    
    
    // ******
    
    
    int bool_jeu=1; //boolean pour l'etat du jeu

    glcd_Init(GLCD_ON); //init glcd
   
    while (bool_jeu==1) //boucle de jeu
    {
       
        //on reinitialise les parametres du microgochi
        mGogo=microgochi_init(mGogo); 
     
        //on affiche les credits (cf screen.c)
        screen_credits();
        
         __delay_ms(2000);

        //un truc qui dit que notre microgochi vient de naitre
        
        //on lance notre jeu     
        game_play();
        
        //si on arrive juste là, notre microgochi est mort
        
        //si notre microgochi est mort on quitte la bouche ou alors
        //il faudra revenir sur l'écran d'accueil, à voir
        if (mGogo->vivant==0)
        {
            //soit on recommence
            
            //soit on quitte
            bool_jeu=0;
            
        }
        
    }

    return (EXIT_SUCCESS);
}
