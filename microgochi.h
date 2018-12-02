/* 
 * File:   microgochi.h
 * Author: Tuong Vi
 *
 * Created on 22 octobre 2018, 17:45
 */


//notre structure
struct Microgochi{
    
  unsigned char age;
  unsigned char satiete;
  unsigned char energie;
  
  unsigned char bonheur;
  
  unsigned char vivant; //boolean
  
  unsigned char dodo;//boolean
  unsigned char caca;//proprete
  
  unsigned char pos_x;
  unsigned char pos_y;
  
};

extern struct Microgochi mGogo;    //creation structure Microgochi

void microgochi_init(void);
void micro_manger(void);
void micro_dormir(void);
void micro_calin(void);
void micro_laver(void);
