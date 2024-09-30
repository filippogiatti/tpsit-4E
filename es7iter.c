/*Dato N un numero intero positivo maggiore di 1, generare e visualizzare
il numero precedente.*/

#include <stdio.h>

int main(int argc, char * argv[]) {
  int N;
  int i;

  do {
    printf("Inserisci un numero intero positivo maggiore di 1: ");
    scanf("%d", &N);
  } while (N < 2);

    N = N-1;
    printf("Il numero precedente e': %d ", N);

  return 0;
}
