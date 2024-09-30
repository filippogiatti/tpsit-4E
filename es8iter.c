/*Dato N un numero intero positivo, generare e visualizzare in ordine
decrescente i primi N numeri interi positivi.*/

#include <stdio.h>

int main(int argc, char * argv[]) {
  int N;
  int i;

  do {
    printf("Inserisci un numero intero positivo maggiore di 1: ");
    scanf("%d", &N);
  } while (N < 0);

    do{
        N=N-1;
        printf("%d", N);
    }while(N>0);

  return 0;
}
