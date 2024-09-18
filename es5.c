/*Progettare un algoritmo che effettui le seguenti operazioni:

• continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
• prima di terminare, visualizzi il valore dei valori conteggiati*/

#include <stdio.h>

int main() {
    int a, b, c;
    int pari = 0, dispari = 0, nulla = 0;
    int differenza;

    do {
        printf("Inserisci il valore di A:\n");
        scanf("%d", &a);
        printf("Inserisci il valore di B:\n");
        scanf("%d", &b);
        printf("Inserisci il valore di C:\n");
        scanf("%d", &c);

        differenza = a - b;

        if (differenza == 0) {
            nulla++;
        } else if (differenza % 2 == 0) {
            pari++;
        } else {
            dispari++;
        }

    } while (a + b >= c); 

    printf("Differenze pari: %d\n", pari);
    printf("Differenze dispari: %d\n", dispari);
    printf("Differenze nulle: %d\n", nulla);

    return 0;
}

