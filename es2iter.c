/*Dato N un numero intero positivo, generare e visualizzare in ordine crescente i primi N numeri
interi positivi.*/

#include <stdio.h>

int main(int argc, char * argv[]) {
  int numero;
  int numeroIniz = 0;

  do {
    printf("Inserisci un numero intero positivo:");
    scanf("%d", & numero);
  } while (numero < 0);

  do {
    printf("%d ", numeroIniz);
    numeroIniz++;
  } while (numeroIniz < numero);

  return 0;
}
