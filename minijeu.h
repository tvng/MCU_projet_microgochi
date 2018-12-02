/* 
 * File:   minijeu.h
 * Author: X250
 *
 * Created on 26 novembre 2018, 11:16
 */

#ifndef MINIJEU_H
#define	MINIJEU_H


extern char pos_x, pos_y ;

void lancer_minijeu(void);
struct champi creer_champi(char x, char y);
void afficher_sequence (void);
void bouger_sequence (void);
void effacer_sequence (void);
void remplir_tableau(void);
void dessiner_arbre(char a, char b);
void saut_tamago (void);
void collision (void);
void fin(void);



#endif	/* MINIJEU_H */


