#include <stdio.h>
#include "BildschirmRoutinen.h"

// Erstellt eine Horizontale linie
void HLinie(int iZeile, int iStartSpalte, int iEndeSpalte, char cZeichen) {
    int i;
    GotoZS(iZeile, iStartSpalte);
    for (i = iStartSpalte; i <= iEndeSpalte; i++) {
        printf("%c", cZeichen);
    }
}

// Erstellt eine Vertikale linie
void VLinie(int iStartZeile, int iEndeZeile, int iSpalte, char cZeichen) {
    int i;
    for (i = iStartZeile; i <= iEndeZeile; i++) {
        GotoZS(i, iSpalte);
        printf("%c", cZeichen);
    }
}

// Erstellt eine Rechteck
void Rechteck(int iStartZeile, int iStartSpalte, int iEndeZeile, int iEndeSpalte, char cZeichen) {
    HLinie(iStartZeile, iStartSpalte, iEndeSpalte, cZeichen);
    HLinie(iEndeZeile, iStartSpalte, iEndeSpalte, cZeichen);
    VLinie(iStartZeile, iEndeZeile, iStartSpalte, cZeichen);
    VLinie(iStartZeile, iEndeZeile, iEndeSpalte, cZeichen);
}


int main() {
    Rechteck(5, 5, 10, 20, '*');
    return 0;
}
