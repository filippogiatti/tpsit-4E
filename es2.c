/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
◦ calcoli il prodotto dei due numeri e ne stampi il valore
◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma*/

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