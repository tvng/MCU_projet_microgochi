#include "screen.h"
#include "glcd.h"
#include "myglcd.h"
#include "minijeu.h"
#include "main.h"


int taille=1;
int direction =0;


struct champi //maillon
{
    char pos_x;
    char pos_y;
   
};
struct tamagotchi //maillon
{
    char pos_x;
    char pos_y;
   
};


struct champi tab[2];

struct champi creer_champi(char x, char y)
{
    struct champi new_champi;
    new_champi.pos_x = x;
    new_champi.pos_y = y;
    return new_champi;
}

void remplir_tableau()
{
    char x = 110;
    int i=0;
    for (i=0;i< taille ;i++)
    {
        tab[i]= creer_champi(x,40);
        x= x+16;
    }
}
void afficher_sequence ()
{
    int i=0;
    for (i=0;i<taille;i++)
    {
        //dessiner_arbre (tab[i].pos_x , tab[i].pos_y);
        displayObject (champi, tab[i].pos_x, tab[i].pos_y, 9, 14, 1);
      
    }
}

void effacer_sequence ()
{
    int i=0;
    for (i=0;i<taille;i++)
    {
      
        //effacer_arbre (tab[i].pos_x , tab[i].pos_y);
      displayObject (champi, tab[i].pos_x, tab[i].pos_y, 9, 14, 0);
    }
}

void bouger_sequence ()
{
    effacer_sequence();
    int i=0;
    for (i=0;i<taille;i++)
    {
      	tab[i].pos_x -=2;
        if(tab[i].pos_x== 0 ) tab[i].pos_x= 110;
   }

    afficher_sequence();
}

void saut_tamago ()
{
    
}




void lancer_minijeu()
{
    //tamagotchi tamagot;
    glcd_FillScreen(0); 
    remplir_tableau();
    
    
    displayObject (tamago, 10 ,40, 9, 14, 1);
    
    //afficher_sequence();
    
    while (1){
        
     bouger_sequence(); 
     
    /* if ( BUTTON_MID == 1 )
     {
         
     }*/
        
    }
}
