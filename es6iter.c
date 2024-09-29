/*Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri compresi maggiori uguali di -N e minori uguali di N.*/

#include <stdio.h>

int main(int argc, char * argv[]) {
  int N;
  int i;

  do {
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &N);
  } while (N < 0);

  for (i = -N; i <= N; i++) {
    printf("%d ", i);
  }

  return 0;
}

