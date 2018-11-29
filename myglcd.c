/* 
 * displayObject : REPRINT FROM CAMPUS !!
 * (catégorie "Open Source")
 * de M. CHEVRIER, FONTAINE, ESCLANGON, DENECE
 * 
 * .c pour gerer le fonctionnement de l'affichage
 * 
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

