/*Dato N un numero intero positivo, generare e visualizzare in ordine crescente i numeri dispari
minori o uguali a N.*/

#include <stdio.h>

int main(int argc, char * argv[]) {
  int N;
  int i; 

  do {
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &N);
  } while (N < 0);

  for (i = 0; i <= N; i++) {
    if (i % 2 != 0) { 
      printf("%d ", i);
    }
  }

  return 0;
}

