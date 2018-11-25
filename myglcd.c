/* 
 * REPRINT FROM CAMPUS !!
 *
 * Created on 25 novembre 2018, 22:24
 */#include "myglcd.h"

/*
 * REPRINT FROM CAMPUS !!
 */
void displayObject (char *tab, int x, int y, int height, int width, int write)
{
     // Display the menu.
    int i = 0;
    int j = 0;
    int nb = 0;

    for (i = y; i < y + height; i++)
    {
        for(j = x; j < x + width; j++){
            if((tab[nb] != 0) && (write == GLCD_WRITE)){
                glcd_PlotPixel(j, i, 1);
            }
            else if((tab[nb] != 0) && (write == GLCD_ERASE)){
                glcd_PlotPixel(j, i, 0);
            }
            nb++;
        }
    }
}

