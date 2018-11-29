/* 
 * File:   minijeu.h
 * Author: X250
 *
 * Created on 26 novembre 2018, 11:16
 */

#ifndef MINIJEU_H
#define	MINIJEU_H

#ifdef	__cplusplus
extern "C" {
#endif

extern char pos_x, pos_y ;

void lancer_minijeu();
struct champi creer_champi(char x, char y);
void afficher_sequence ();
void bouger_sequence ();
void effacer_sequence ();
void remplir_tableau();
void dessiner_arbre(char a, char b);


#ifdef	__cplusplus
}
#endif

#endif	/* MINIJEU_H */


