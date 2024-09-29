/*Dato N un numero intero positivo, generare e visualizzare il numero 
successivo.*/

#include <stdio.h>

int main(int argc, char * argv[]) {
  int numero;

  do {
    printf("Inserisci un numero intero positivo:");
    scanf("%d", & numero);
  } while (numero < 0);

  numero = numero + 1;
  printf("Il numero successivo e' %d", numero);

  return 0;
}
