/*Dati due numeri interi positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine crescente i numeri interi compresi
nell'intervallo chiuso [N1,N2]. */

#include <stdio.h>

int main(int argc, char * argv[]) {
  int N1, N2;
  int i;

  do {
    printf("Inserisci due numeri interi positivi (N2 > N1):\n");
    printf("N1: ");
    scanf("%d", &N1);
    printf("N2: ");
    scanf("%d", &N2);
  } while (N1 < 0 || N2 < 0 || N2 <= N1); 
  
  for (i = N1; i <= N2; i++) {
    printf("%d ", i);
  }

  return 0;
}

