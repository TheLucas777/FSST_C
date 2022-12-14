#include <stdio.h>

#include "BildschirmRoutinen.h"

void Anzeigen(int iZeile, int iSpalte, char cZeichen, int iDelay)
{
    //Gehe zu Z und S,zeichne cZeichen, warte iDelay, Lösche zeichen
    GotoZS(iZeile,iSpalte);

    printf("%c",cZeichen);

    Delay(iDelay);

    GotoZS(iZeile,iSpalte);
    printf(" ");

}


void FliegendesTeilchen(int iZeileOben, int iSpalteLinks, int iZeileUnten, int iSpalteRechts, char cZeichen, int iDelay)
{
    //Variablen Intitialisieren
    int iZeile;
    int iSpalte;
    int iNeueSpalte;
    int iRichtungSpalte;

    //Variablen füllen
    iZeile = (iZeileOben+iZeileUnten)/2;
    iSpalte = (iSpalteLinks+iSpalteRechts)/2;
    iRichtungSpalte = 1;


    for(;;)
    {
        iNeueSpalte = iSpalte+iRichtungSpalte;

        if((iSpalteLinks < iNeueSpalte) && (iNeueSpalte < iSpalteRechts))
        {
            //im erlaubten Bereich

            //Neue Spalte übernehmen
            iSpalte = iNeueSpalte;
        }
        else
        {
            //nicht im erlaubten Bereich

            //Richtung ändern
            iRichtungSpalte =- iRichtungSpalte;
        }

        Anzeigen(iZeile,iSpalte,cZeichen,iDelay);
    }
}

int main()
{
    FliegendesTeilchen(3,3,20,60,'*',50);
    return 0;
}
