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


void FliegendesTeilchen (int iZeileOben,int iSpalteLinks,int iZeileUnten,int iSpalteRechts,char cZeichen,int iDelay)
{
    int iZeile;
    int iSpalte;
    int iNeueZeile;
    int iNeueSpalte;
    int iRichtungZeile;
    int iRichtungSpalte;

    iZeile=(iZeileOben+iZeileUnten)/2;
    iSpalte=(iSpalteLinks+iSpalteRechts)/2;
    iRichtungSpalte=1;
    iRichtungZeile=1;

    for(;;)
    {
        iNeueZeile=iZeile+iRichtungZeile;
        iNeueSpalte=iSpalte+iRichtungSpalte;

        if (  (iZeileOben<iNeueZeile) && (iNeueZeile<iZeileUnten))
        {
            // im erlaubten Bereich
            iZeile=iNeueZeile;
        }
        else
        {
            // nicht im erlaubten Bereich
            iRichtungZeile=-iRichtungZeile;
        }

        if (  (iSpalteLinks<iNeueSpalte) && (iNeueSpalte<iSpalteRechts))
        {
            // im erlaubten Bereich
            iSpalte=iNeueSpalte;
        }
        else
        {
            // nicht im erlaubten Bereich
            iRichtungSpalte=-iRichtungSpalte;
        }

        Anzeigen(iZeile,iSpalte,cZeichen,iDelay);
    }
}

int main()
{
    FliegendesTeilchen(3,3,20,60,'*',50);
    return 0;
}
