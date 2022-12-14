#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BildschirmRoutinen.h"

void Wanderer (float fWinkel,int iMitte, int iRadius, int cZeichen, int iDelay)     //Kreiswanderungsfunktion
{
    int iSpalte;
    int iZeile;
    while (1)
    {
        iSpalte = iMitte + iRadius * cos(fWinkel);  //iSpalte wird mithilfe des Cosinus vom Winkel bestimmt
        iZeile = iMitte + iRadius * sin(fWinkel);   //iZeile wird mithilfe des Sinus vom Winkel bestimmt
        GotoXY(iSpalte,iZeile);
        printf("%c",cZeichen);      //Das "%c" interpretiert den numerischen Wert von cZeichen als char und kann in somit printen
        Delay(iDelay);
        ClrScr();
        fWinkel ++;
    }

}

int main ()
{
    Wanderer (10,10,5,'+',50);
    return 0;
}
