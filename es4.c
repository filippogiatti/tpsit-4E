/*Progettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due. Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo.*/

#include <stdio.h>
#include <math.h> 

int main() {
    double n1, n2, rapporto, risultato;

    do {
        printf("Inserisci il primo numero (n1):\n");
        scanf("%f", &n1);  
        printf("Inserisci il secondo numero (n2):\n");
        scanf("%f", &n2);  

        if (n1 == 0 || n2 == 0) {
            printf("Il calcolo non e' possibile perche' uno dei due numeri e' 0.\n");
            break;
        }
        if (n1 < 0 && n2 < 0) {
            printf("Il calcolo non e' possibile perche' entrambi i numeri sono negativi.\n");
            break;
        }

        if (n1 > n2) {
            rapporto = n1 / n2;
        } else {
            rapporto = n2 / n1;
        }

        risultato = sqrt(rapporto);
        printf("La radice quadrata del rapporto tra il maggiore e il minore e': %f\n", risultato);

    } while (n1 != 0 && n2 != 0 && !(n1 < 0 && n2 < 0)); 

    return 0;
}

