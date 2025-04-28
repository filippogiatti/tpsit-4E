#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome_file[256];
    FILE *file_input, *file_pari, *file_dispari;
    int numero;

    // 1. Chiediamo il nome del file da cui leggere
    printf("Inserisci il nome del file da cui leggere i numeri: ");
    scanf("%s", nome_file);

    // 2. Apriamo il file di input
    file_input = fopen(nome_file, "r");
    if (file_input == NULL) {
        perror("Errore nell'aprire il file di input");
        return -1;
    }

    // 3. Apriamo i file di output per i numeri pari e dispari
    file_pari = fopen("pari.txt", "w");
    if (file_pari == NULL) {
        perror("Errore nell'aprire il file pari.txt");
        fclose(file_input); // Chiudiamo il file di input prima di uscire
        return -1;
    }

    file_dispari = fopen("dispari.txt", "w");
    if (file_dispari == NULL) {
        perror("Errore nell'aprire il file dispari.txt");
        fclose(file_input); // Chiudiamo il file di input
        fclose(file_pari);  // Chiudiamo il file pari.txt
        return -1;
    }

    // 4. Leggiamo i numeri dal file e li separiamo in pari e dispari
    while (fscanf(file_input, "%d", &numero) != EOF) {
        if (numero % 2 == 0) {
            fprintf(file_pari, "%d ", numero); // Scriviamo nei file pari.txt
        } else {
            fprintf(file_dispari, "%d ", numero); // Scriviamo nei file dispari.txt
        }
    }

    printf("Scrittura completata con successo!\n");

    // 5. Chiudiamo i file aperti
    fclose(file_input);
    fclose(file_pari);
    fclose(file_dispari);

    return 0;
}

