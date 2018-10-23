/* 
 * File:   microgochi.h
 * Author: Tuong Vi
 *
 * Created on 22 octobre 2018, 17:45
 */




struct Microgochi{
    
  unsigned char age;
  unsigned char satiete;
  unsigned char energie;
  
  unsigned char proprete;
  
  unsigned char vivant; //boolean
  
};

void initMicrogochi(struct Microgochi *m);
