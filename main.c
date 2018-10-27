


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

#include "main.h" 


int main(int argc, char** argv) {
    
    
    // ** init easypic -----------
    TRISA=0b00000111;
    PORTA=0b00000111;
    
    TRISD = 0xff;			//PORTD input
	PORTD = 0x00; 				//Reset PORTD
    
    glcd_Init(GLCD_ON);// ** initialisation ecran
    
    Microgochi *mGogo=NULL;    //creation structure Microgochi
    int bool_jeu=1; //boolean pour l'etat du jeu
    
    while (bool_jeu==1) //boucle de jeu
    {
        
        screen_credits(); //pour afficher les credits cf screen.c : A FAIRE !!!!!!!!!!!!!!!!
        microgochi_init(mGogo); //on reinitialise les parametres du microgochi
        
        //un truc qui dit que notre microgochi vient de naitre
        
        //affichage de notre notre lapin de base et avec le menu      
        game_play(mGogo);
        
        
        //si notre microgochi est mort on quitte la bouche ou alors
        //il faudra revenir sur l'écran d'accueil
        if (mGogo->vivant==0)
        {
            
            //soit on recommence
            
            //soit on quitte
            bool_jeu=0;
            
        }
        
        //un truc qui dit que notre microgochi meurt
    }

    return (EXIT_SUCCESS);
}
