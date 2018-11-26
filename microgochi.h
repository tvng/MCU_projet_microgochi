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
  
};

struct Microgochi * microgochi_init(struct Microgochi *m);
void micro_manger();
