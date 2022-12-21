#include <stdio.h>
#include "BildschirmRoutinen.h"


void FliegendesTeilchen(int iZeileOben, int iSpalteLinks, int iZeileUnten, int iSpalteRechts, char cZeichen, int iDelay)
{
    int iZeile;
    int iSpalte;
    int iNeueZeile;
    int iNeueSpalte;
    int iRichtung;

    iRichtung = 1;
    iZeile = (iZeileOben+iZeileUnten)/2;
    iSpalte = (iSpalteLinks+iSpalteRechts)/2;

    for(;;)
    {
        //Neue Pos
        switch (iRichtung)
        {
            case 0: iNeueZeile = iZeile - 1; iNeueSpalte = iSpalte; break;
            case 1: iNeueZeile = iZeile - 1; iNeueSpalte = iSpalte + 1; break;
            case 2: iNeueZeile = iZeile; iNeueSpalte = iSpalte + 1; break;
            case 3: iNeueZeile = iZeile + 1; iNeueSpalte = iSpalte + 1; break;
            case 4: iNeueZeile = iZeile + 1; iNeueSpalte = iSpalte; break;
            case 5: iNeueZeile = iZeile + 1; iNeueSpalte = iSpalte - 1; break;
            case 6: iNeueZeile = iZeile; iNeueSpalte = iSpalte - 1; break;
            case 7: iNeueZeile = iZeile - 1; iNeueSpalte = iSpalte - 1; break;
            default:break;
        }

        if((iZeileOben < iNeueZeile) && (iNeueZeile < iZeileUnten) &&
        (iSpalteLinks < iNeueSpalte) && (iNeueSpalte < iSpalteRechts))
        {
            // Wenn Pos passt  -> Übernehmen
            iZeile = iNeueZeile;
            iSpalte = iNeueSpalte;
        } else
        {
            // Pos passt nicht -> Richtung ändern
            iRichtung = Zufall(0,7);
        }

        //Anzeigen
        GotoZS(iZeile,iSpalte);
        printf("%c",cZeichen);
        Delay(iDelay);
        GotoZS(iZeile,iSpalte);
        printf(" ");
    }
}

int main()
{
    InitZufall();
    FliegendesTeilchen(3,3,20,60,'*',30);

    return 0;
}
