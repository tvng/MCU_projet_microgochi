/* 
 * File:   main.c
 * Author: Tuong Vi
 *
 * Created on 22 octobre 2018, 14:44
 */

#include "main.h" 





int main(int argc, char** argv) {
    
    
    
    
    // ** init easypic -----------
    TRISB=0b00001111;
    PORTB=0b00001111;
    
    TRISD = 0xff;			//PORTD input
	PORTD = 0x00; 				//Reset PORTD
    
    
    // ** init ecran
    glcd_Init(GLCD_ON);
    
    // ** init perso -----------
    struct Microgochi mGogo;
    initMicrogochi(& mGogo);
    int vivant=0;
    //boolean pour dire 1 si vivant et 0 si mort


    //  *** GAME START!! ***
    //anim rapide d'un oeuf qui devient un lapin
    vivant=1;

    
    while (vivant==1) //boucle de jeu
    {
        // ********** STATUT : jauges du Microgogo qui diminuent au fil du temps
        
        //toutes les 60s, il grandit d'un jour 
        //toutes les 30s, il perd 10 de satiete
        //toutes les 10s, il perd 10 d'energie
        //toutes les 30s, il perd 5 de proprete
        //toutes les 40s, il perd 5 d'amusement
        
        
        // *********** MENU : avec boutons RB0, RB1, RB2 ************
            
        //s'il mange, il gagne 30 de satiete et perd 30 de proprete
        //il dort, il gagne 20 d'energie toutes les 5s
        //S'il dort trop, il perd de l'énergie
        //s'il n'a plus d'énergie il meurt
        //etc cf overleaf
      
        //une fois qu'on arrive a 100 jours, il meurt et on sort de la boucle
    }

    return (EXIT_SUCCESS);
}
