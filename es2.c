#include <stdio.h>

int main(){
    int n1, n2, prodotto, sommaProdotti = 0;

    do {
        printf("Inserisci il primo numero (n1):\n");
        scanf("%d", &n1);
        printf("Inserisci il secondo numero (n2):\n");
        scanf("%d", &n2);

        prodotto = n1 * n2;
        printf("Il prodotto è: %d\n", prodotto);

        sommaProdotti = sommaProdotti + prodotto;

    } while (n1 != 0 && n2 != 0); 

    printf("La somma di tutti i prodotti è: %d\n", sommaProdotti);

    return 0;
}
