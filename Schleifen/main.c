#include <stdio.h>

int main() {
    int iZähler;
    iZähler = 0;

    while (iZähler < 10) {
        printf("x");
        iZähler++;
    }


    printf("\n");
    iZähler = 0;

    do {
        printf("y");
        iZähler++;
    } while (iZähler < 10);
}