/*Dato N un numero intero positivo, calcolare e visualizzare la somma dei
primi N numeri dispari.*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n; int i = 0;
    double somma;
    do
    {
        printf("Inserisci un numero intero positivo: ");
        scanf("%d", &n);
    } while (n < 0);
    /*do{
        somma= somma + i;
        i=i+2;
    }while(i<n);*/
    for(i=0; i<n; i++){
        if(i%2==1){
            somma=somma+i;
        }
    }
    printf("La somma e': %lf", somma);

    return 0;
}