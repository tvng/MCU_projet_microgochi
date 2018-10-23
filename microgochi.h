/* 
 * File:   microgochi.h
 * Author: Tuong Vi
 *
 * Created on 22 octobre 2018, 17:45
 */




struct Microgochi{
    
  unsigned char age;
  unsigned char satiete;
  unsigned char fatigue;
  unsigned char proprete;
  unsigned char amusement;
};

void initMicrogochi(struct Microgochi *m);
