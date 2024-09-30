/*Dati due numeri interi e positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine decrescente i numeri compresi tra N1 e N2. */

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
  
    do{
        N2=N2-1;
        printf("%d ", N2);
        
    }while(N2>N1+1);

  return 0;
}
