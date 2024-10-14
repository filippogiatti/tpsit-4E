/*Dato N un numero intero positivo, calcolare e visualizzare la somma dei
primi N numeri interi. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i = 0;
    double somma;
    do
    {
        printf("Inserisci un numero intero positivo: ");
        scanf("%d", &n);
    } while (n < 0);
    do{
        somma= somma + i;
        i++;
    }while(i<n);
    printf("La somma e': %lf", somma);

    return 0;
}