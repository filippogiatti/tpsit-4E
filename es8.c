/*Progettare un algoritmo che risolve il seguente problema. Si desidera 
calcolare la somma delle radici quadrate di N valori numerici inseriti 
dall’utente, con N inserito in input. 
L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
con un messaggio di errore quando viene inserito un numero che non
permette di effettuare il calcolo (nel dominio dei numeri reali).*/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	int numeroNumeri;
	double somma=0;
	int numero;
	int i;
	
	do{
		printf("quanti numeri vuoi inserire?\n");
		scanf("%d", &numeroNumeri);
	}while(numeroNumeri < 1);
	
	for(i=0; i<numeroNumeri; i++){
		printf("Inserisci un numero: \n");
		scanf("%d", &numero);

        if (numero >= 0)
        {

            somma = somma + sqrt(numero);
        }
        else
        {

            printf("Hai inserito un numero negativo\n");
        }

	}
	printf("La somma e'': %f", somma);
	
	return 0;
}
