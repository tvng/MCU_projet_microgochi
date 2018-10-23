# 1 "microgochi.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "microgochi.c" 2






# 1 "./microgochi.h" 1
# 11 "./microgochi.h"
struct Microgochi{

  unsigned char age;
  unsigned char satiete;
  unsigned char fatigue;
  unsigned char proprete;
  unsigned char amusement;
};

void initMicrogochi(struct Microgochi *m);
# 7 "microgochi.c" 2



void initMicrogochi(struct Microgochi *m)
{
    m->age=0;
    m->satiete=100;
    m->fatigue=100;
    m->proprete=100;
    m->amusement=100;

}
