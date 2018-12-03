#include "screen.h"
#include "glcd.h"
#include "myglcd.h"
#include "minijeu.h"
#include "main.h"
#include "microgochi.h"
#include "itoa.h"


int taille = 2;
int direction = 0;
int tamago_largeur = 13;
int tamago_hauteur = 8;
int colli = 0;
int score = 3;
char buffer[3];

struct champi //maillon
{
    char pos_x;
    char pos_y;
    char champ_h;
    char champ_l;

};

struct tamagotchi //maillon
{
    char pos_x;
    char pos_y;

};


struct champi tab[2];

struct champi creer_champi(char x, char y) {
    struct champi new_champi;
    new_champi.pos_x = x;
    new_champi.pos_y = y;
    new_champi.champ_h = 9;
    new_champi.champ_l = 10;
    return new_champi;
}

void remplir_tableau() {
    char x = 100;
    int i = 0;
    for (i = 0; i < taille; i++) {
        tab[i] = creer_champi(x, 40);
        x = x + 60;
    }
}

void afficher_sequence() {
    int i = 0;
    for (i = 0; i < taille; i++) {
        //dessiner_arbre (tab[i].pos_x , tab[i].pos_y);
        displayObject(champi, tab[i].pos_x, tab[i].pos_y, 9, 14, 1);

    }
}

void effacer_sequence() {
    int i = 0;
    for (i = 0; i < taille; i++) {

        //effacer_arbre (tab[i].pos_x , tab[i].pos_y);
        displayObject(champi, tab[i].pos_x, tab[i].pos_y, 9, 14, 0);
    }
}

void bouger_sequence() {
    effacer_sequence();
    int i = 0;
    for (i = 0; i < taille; i++) {
        tab[i].pos_x -= 3;
        if (tab[i].pos_x <= 4) {
            tab[i].pos_x = 110;
        }
    }

    afficher_sequence();
}

void saut_tamago() {
    /*mGogo.pos_x +=10;
    mGogo.pos_y -=10;
    displayObject (tamago,  mGogo.pos_x ,  mGogo.pos_y, 9, 14, 1);*/
    int i = 0;
    int a = 0;
    score = score + 1;
    glcd_SetCursor(100, 0); // affichage du score
    itoa(score, buffer);
    glcd_WriteString(buffer, f8X8, 1);
    memset(&buffer, 0, sizeof (buffer));
    while (i != 5) {
        bouger_sequence();
        displayObject(tamago, mGogo.pos_x, mGogo.pos_y, 9, 14, 0);
        mGogo.pos_y -= 4;
        displayObject(tamago, mGogo.pos_x, mGogo.pos_y, 9, 14, 1);

        i++;
    }

    while (i != 10) {
        bouger_sequence();
        displayObject(tamago, mGogo.pos_x, mGogo.pos_y, 9, 14, 0);
        mGogo.pos_y += 4;
        displayObject(tamago, mGogo.pos_x, mGogo.pos_y, 9, 14, 1);
        bouger_sequence();
        i++;
    }



}

void collision() {

    //char score ='0';
    int i = 0;
    for (i = 0; i < taille; i++) {


        /*if (((tab[i].pos_x < mGogo.pos_x+ tamago_largeur)&&(tab[i].pos_x > mGogo.pos_x))&&
           ((tab[i].pos_y <= mGogo.pos_y+ tamago_hauteur )&&(tab[i].pos_y >= mGogo.pos_y)))
          colli=1;
      
       if (((tab[i].pos_x + 13 <= mGogo.pos_x+ tamago_largeur)&&(tab[i].pos_x+ 13 >= mGogo.pos_x))&&
           ((tab[i].pos_y <= mGogo.pos_y+ tamago_hauteur )&&(tab[i].pos_y >= mGogo.pos_y)))
          colli=1;*/

        /*  if ((mGogo.pos_y + tamago_hauteur >= tab[i].pos_y )&&(mGogo.pos_y + tamago_hauteur <= tab[i].pos_y + tab[i].champ_h ))
          {
              if ((mGogo.pos_x >= tab[i].pos_x )&&(mGogo.pos_x <= tab[i].pos_x + tab[i].champ_l  )) colli=1;
            
              else if ((mGogo.pos_x + tamago_largeur >= tab[i].pos_x )&&(mGogo.pos_x + tamago_largeur <= tab[i].pos_x + tab[i].champ_l  )) colli=1;
          }*/

        //pas tout de suite


        /*if (((mGogo.pos_x >= tab[i].pos_x )&&(mGogo.pos_x <= tab[i].pos_x + tab[i].champ_l  ))&&
          ((mGogo.pos_y + tamago_hauteur >= tab[i].pos_y )&&(mGogo.pos_y + tamago_hauteur <= tab[i].pos_y + tab[i].champ_h )))
         colli=1;*/




        if (((mGogo.pos_x + tamago_largeur >= tab[i].pos_x)&&(mGogo.pos_x + tamago_largeur <= tab[i].pos_x + tab[i].champ_l))&&
                ((mGogo.pos_y + tamago_hauteur >= tab[i].pos_y)&&(mGogo.pos_y + tamago_hauteur <= tab[i].pos_y + tab[i].champ_h))) {
            colli = 1;
            score = score - 1;
            itoa(score, buffer);
            glcd_SetCursor(100, 0);
            glcd_WriteString(buffer, f8X8, 1);
            memset(&buffer, 0, sizeof (buffer));
            mGogo.pos_x = 0;
            mGogo.pos_y = 0;
            displayObject(tamago, 30, 40, 9, 14, 0);
            glcd_SetCursor(100, 0); // affichage du score


        }




        /*if (((mGogo.pos_x >= tab[i].pos_x )&&(mGogo.pos_x <= tab[i].pos_x + tab[i].champ_l  ))&&
            ((mGogo.pos_y + 8 >= tab[i].pos_y )))
           colli=1;*/

    }

    if (colli == 1) {
        int i = 0;
        mGogo.pos_x = 30;
        mGogo.pos_y = 0;
        while (i != 4) {
            bouger_sequence();
            bouger_sequence();
            bouger_sequence();
            displayObject(tamago, mGogo.pos_x, mGogo.pos_y, 9, 14, 0);
            mGogo.pos_y += 10;
            displayObject(tamago, mGogo.pos_x, mGogo.pos_y, 9, 14, 1);
            i++;
        }
        colli = 0;
    }




}

void lancer_minijeu() {
    //
    PIE1bits.TMR1IE = 0;
    glcd_FillScreen(0);
    remplir_tableau(); // initialisation des champis
    mGogo.pos_x = 30; // init positions du tamogotchi
    mGogo.pos_y = 40;
    displayObject(tamago, mGogo.pos_x, mGogo.pos_y, 9, 14, 1);

    do {
        bouger_sequence(); // bouger les champi
        collision(); // check si collision champi tamagotchi

        if (BUTTON_MID == 1) {
            saut_tamago();

        }

        itoa(score, buffer);
        glcd_SetCursor(100, 0);
        glcd_WriteString(buffer, f8X8, 1);



    } while (score <= 5 && score > 0);

    if (score == 0) {
        do {

            glcd_SetCursor(0, 0);
            glcd_WriteString("FAIL", f8X8, 1);
            glcd_SetCursor(0, 4);
            glcd_WriteString("exit  ", f8X8, 1);
            glcd_SetCursor(0, 6);
            glcd_WriteString("RC0 ", f8X8, 1);
            if (BUTTON_LEFT == 1) {
                score = 3;
                PIE1bits.TMR1IE = 1;
                break;
            }

        } while (1);
    }

    if (score == 6) {
        do {

            glcd_SetCursor(0, 0);
            glcd_WriteString("WIN", f8X8, 1);
            glcd_SetCursor(0, 4);
            glcd_WriteString("exit  ", f8X8, 1);
            glcd_SetCursor(0, 6);
            glcd_WriteString("RC0 ", f8X8, 1);
            if (BUTTON_LEFT == 1) {
                score = 3;
                PIE1bits.TMR1IE = 1;
                break;
            }

        } while (1);
    }

}
