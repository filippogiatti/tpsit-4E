/*Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.

Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
1.	La media dell’incasso delle bevande 
2.	La media dell’incasso della ristorazione
3.	Deve indicare se sono state vendute più bevande o più ristorazioni*/

#include <stdio.h>

#include <string.h>

int main() {
  char tipo[20];
  float importo;
  float sommaBevande = 0, sommaRistorazione = 0;
  int contBevande = 0, contRistorazione = 0;
  float mediaBevande, mediaRistorazione;

  do {
    printf("Inserisci la tipologia della consumazione (bevande/ristorazione) o 'esci' per terminare:\n");
    scanf("%s", tipo);

    if (strcmp(tipo, "esci") == 0) {
      break;
    }

    printf("Inserisci l'importo della consumazione:\n");
    scanf("%f", & importo);

    if (strcmp(tipo, "bevande") == 0) {
      sommaBevande += importo;
      contBevande++;
    } else if (strcmp(tipo, "ristorazione") == 0) {
      sommaRistorazione += importo;
      contRistorazione++;
    } else {
      printf("Tipologia non valida! Inserisci 'bevande' o 'ristorazione'.\n");
    }

  } while (1);

  if (contBevande > 0) {
    mediaBevande = sommaBevande / contBevande;
  } else {
    mediaBevande = 0;
  }

  if (contRistorazione > 0) {
    mediaRistorazione = sommaRistorazione / contRistorazione;
  } else {
    mediaRistorazione = 0;
  }

  printf("La media dell'incasso delle bevande e': %.2f\n", mediaBevande);
  printf("La media dell'incasso della ristorazione e': %.2f\n", mediaRistorazione);

  if (contBevande > contRistorazione) {
    printf("Sono state vendute piu bevande.\n");
  } else if (contRistorazione > contBevande) {
    printf("Sono state vendute piu ristorazioni.\n");
  } else {
    printf("Sono state vendute lo stesso numero di bevande e ristorazioni.\n");
  }

  return 0;
}
