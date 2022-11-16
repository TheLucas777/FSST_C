#include <stdio.h>
#include "BildschirmRoutinen.h"

// Erstellt eine Horizontale linie
void HLinie(int iZeile, int iStartSpalte, int iEndeSpalte, char cZeichen)
{
    int i;
    GotoZS(iZeile, iStartSpalte);
    for (i = iStartSpalte; i <= iEndeSpalte; i++)
    {
        printf("%c", cZeichen);
    }
}



int main() {
    HLinie(3, 3, 70, '#');
    HLinie(20, 10, 70, '#');
    return 0;
}
