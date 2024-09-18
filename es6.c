/*Progettare un algoritmo che effettui le seguenti operazioni:
• legga da tastiera una coppia di valori interi A e B con A<B;
• continui a leggere da tastiera una serie di valori interi, terminando 
quando il valore letto è al di fuori dell’intervallo [A, B];
• conteggi la media dei valori letti;
• prima di terminare, stampi il valore calcolato.*/

#include <stdio.h>

int main() {
    int a, b, valore;
    int somma = 0, cont = 0;
    float media;

    do {
        printf("Inserisci il valore di A (A < B):\n");
        scanf("%d", &a);
        printf("Inserisci il valore di B (A < B):\n");
        scanf("%d", &b);
        if (a >= b) {
            printf("Errore: A deve essere minore di B. Riprova.\n");
        }
    } while (a >= b);

    do {
        printf("Inserisci un valore nell'intervallo [%d, %d]:\n", a, b);
        scanf("%d", &valore);

        if (valore >= a && valore <= b) {
            somma += valore;
            cont++;
        }

    } while (valore >= a && valore <= b); 

    if (cont > 0) {
        media = (float)somma / cont;
        printf("La media dei valori letti e': %.2f\n", media);
    } else {
        printf("Nessun valore valido e' stato inserito.\n");
    }

    return 0;
}

