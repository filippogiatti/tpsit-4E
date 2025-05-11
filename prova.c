/*Scrivi un programma in C che:
Legga un file di testo contenente una serie di numeri interi (uno per riga).

Calcoli e visualizzi:

La somma di tutti i numeri letti.

Il numero di numeri letti.

Scriva la somma totale e il numero di numeri letti in un altro file.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char buff[81];
    FILE *fsource;
    FILE *fdest;
    int numNumeri=0;
    int somma=0;
    int num;

    fsource = fopen(argv[1], "r");
    if (fsource == NULL) {
    	printf("Errore nell'apertura del file.\n");
    	return -1;
	}
    fdest = fopen(argv[2], "w");
    if (fdest == NULL) {
        printf("Errore nell'apertura del file di output\n");
        return -1;    
    }
    while(fgets(buff, sizeof(buff), fsource) != NULL){
        num = atoi(buff);  // Converte la stringa in intero
        somma += num;      // Somma il numero letto
        numNumeri++; 
    }

    fprintf(fdest, "Somma: %d\n", somma);
    fprintf(fdest, "Numero di numeri letti: %d\n", numNumeri);

    fclose(fsource);
    fclose(fdest);

    return 0;
}

