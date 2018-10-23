/* 
 * File:   main.c
 * Author: Tuong Vi
 *
 * Created on 22 octobre 2018, 14:44
 */

#include "main.h" 

void game_play(struct Microgochi *m)
{
    while (m->vivant==1) //tant que le microgochi est vivant
    {
        //si on appuie sur 
        
    }
}

int main(int argc, char** argv) {
    
    
    // ** init easypic -----------
    TRISA=0b00000111;
    PORTA=0b00000111;
    
    TRISD = 0xff;			//PORTD input
	PORTD = 0x00; 				//Reset PORTD
    
    glcd_Init(GLCD_ON);// ** init ecran
    struct Microgochi mGogo;    //creation structure Microgochi
   
    screen_credits(); //pour afficher les credits cf screen.c : A FAIRE !!!!!!!!!!!!!!!!!
    
    while (1) //boucle de jeu
    {
        initMicrogochi(&mGogo); //on reinitialise les parametres du microgochi
        
        //un truc qui dit que notre microgochi vient de naitre
        
        //affichage de notre notre lapin de base et avec le menu
        
        game_play(&mGogo);
        
        //un truc qui dit que notre microgochi meurt
    }

    return (EXIT_SUCCESS);
}
