/* 
 * File:   menu.h
 * Author: Tuong Vi
 *
 * Created on 19 novembre 2018, 14:12
 */

#ifndef MENU_H
#define	MENU_H

#define MENU_INIT_X 12
#define MENU_Y_TOP 10
#define MENU_Y_BOTTOM 50
#define MENU_JUMP 32

#define NB_ACTIVITE_MAX 3 //3+0

void menu_cursor(int action, int write);
void menu_actions(int action);

#endif	/* MENU_H */

