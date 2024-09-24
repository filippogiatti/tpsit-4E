/*Progettare un algoritmo che risolva il seguente problema. Si richieda 
all’utente di inserire una serie di terne di dati numerici (A, B, C). 
Il programma deve terminare quando uno dei valori inseriti è minore di
zero. Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma.*/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int a, b, c;
    int max, min;
    int primaTerna = 1; 

    do {
        printf("Inserisci il valore di A:\n");
        scanf("%d", &a);
        printf("Inserisci il valore di B:\n");
        scanf("%d", &b);
        printf("Inserisci il valore di C:\n");
        scanf("%d", &c);

        if (a < 0 || b < 0 || c < 0) {
            break;
        }

        if (a < b && b < c) {
            if (primaTerna) {
                max = c;
                min = a;
                primaTerna = 0; 
            } else {
                if (c > max) {
                    max = c;
                }
                if (a < min) {
                    min = a;
                }
            }
        } else {
            printf("Terna#include <stdio.h>

#include <math.h>

int main(int argc, char * argv[]) {
  int a, b, c;
  int max, min;
  int primaTerna = 1;

  do {
    printf("Inserisci il valore di A:\n");
    scanf("%d", & a);
    printf("Inserisci il valore di B:\n");
    scanf("%d", & b);
    printf("Inserisci il valore di C:\n");
    scanf("%d", & c);

    if (a < 0 || b < 0 || c < 0) {
      break;
    }

    if (a < b && b < c) {
      if (primaTerna) {
        max = c;
        min = a;
        primaTerna = 0;
      } else {
        if (c > max) {
          max = c;
        }
        if (a < min) {
          min = a;
        }
      }
    } else {
      printf("Terna scartata: A = %d, B = %d, C = %d non e' in ordine crescente.\n", a, b, c);
    }

  } while (a >= 0 && b >= 0 && c >= 0);

  if (!primaTerna) {
    printf("Il valore massimo tra le terne valide e': %d\n", max);
    printf("Il valore minimo tra le terne valide e': %d\n", min);
  } else {
    printf("Nessuna terna valida inserita.\n");
  }

  return 0;
} scartata: A = %d, B = %d, C = %d non e' in ordine crescente.\n", a, b, c);
        }

    } while (a >= 0 && b >= 0 && c >= 0); 

    if (!primaTerna) {
        printf("Il valore massimo tra le terne valide e': %d\n", max);
        printf("Il valore minimo tra le terne valide e': %d\n", min);
    } else {
        printf("Nessuna terna valida inserita.\n");
    }

    return 0;
} 

