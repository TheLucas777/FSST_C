#include <stdio.h>
#include "BildschirmRoutinen.h"

// Erstellt eine Horizontale linie
void HLinie(int iZeile, int iStartSpalte, int iEndeSpalte, char cZeichen)
{
    int iLoop;
    GotoZS(iZeile, iStartSpalte); // setzt Cursor auf iZeile und iStartSpalte
    for (iLoop = iStartSpalte; iLoop <= iEndeSpalte; iLoop++)
    {
        printf("%c", cZeichen);  // Zeichen wird bei %c eingesetzt (Als char interpretiert)
    }
}


// Erstellt eine Vertikale linie
void VLinie(int iStartZeile, int iEndeZeile, int iSpalte, char cZeichen)
{
    int iLoop;
    for (iLoop = iStartZeile; iLoop <= iEndeZeile; iLoop++)
    {
        GotoZS(i, iSpalte); // setzt Cursor auf iZeile und iStartSpalte
        printf("%c", cZeichen); // Zeichen wird bei %c eingesetzt (Als char interpretiert)
    }
}


// Erstellt eine Rechteck
void Rechteck(int iStartZeile, int iStartSpalte, int iEndeZeile, int iEndeSpalte, char cZeichen)
{
    HLinie(iStartZeile, iStartSpalte, iEndeSpalte, cZeichen);
    HLinie(iEndeZeile, iStartSpalte, iEndeSpalte, cZeichen);
    VLinie(iStartZeile, iEndeZeile, iStartSpalte, cZeichen);
    VLinie(iStartZeile, iEndeZeile, iEndeSpalte, cZeichen);
}


int main()
{
    Rechteck(5, 5, 10, 20, '*');
    return 0;
}
