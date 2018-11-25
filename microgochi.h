/* 
 * File:   microgochi.h
 * Author: Tuong Vi
 *
 * Created on 22 octobre 2018, 17:45
 */


typedef struct Microgochi Microgochi; //pour enlever le struc et ecrire que Microgochi a chaque fois


//notre structure
struct Microgochi{
    
  unsigned char age;
  unsigned char satiete;
  unsigned char energie;
  
  unsigned char proprete;
  
  unsigned char vivant; //boolean
  
};

Microgochi * microgochi_init(Microgochi *m);