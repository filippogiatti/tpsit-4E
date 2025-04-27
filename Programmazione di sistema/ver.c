#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

int parolaValida(char carattere)
{
    if (carattere == ' ' || carattere == '\n' || carattere == '\t')
    {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero di argomenti errato. Inserisci come primo argomento il nome di un file.\n");
        exit(1);
    }

    int p1p2[2], p2p0[2], pid;
    char str_parole[10];

    pipe(p1p2);  // Crea pipe tra P1 e P2

    pid = fork();
    if (pid == 0)
    {
        // Processo P1: legge il file con 'cat' e invia a P2
        close(p1p2[0]);  // Chiude il lato di lettura della pipe
        close(1);         // Chiude il flusso di output standard
        dup(p1p2[1]);     // Duplica la pipe per scrivere
        close(p1p2[1]);   // Chiude la pipe originale

        execl("/bin/cat", "cat", argv[1], NULL);  // Esegue il comando 'cat' sul file
        exit(1);  // Se execl fallisce
    }

    // Processo P0: aspetta che P1 finisca e poi crea P2
    close(p1p2[1]);  // Chiude il lato di scrittura della pipe
    pipe(p2p0);  // Crea la pipe tra P2 e P0
    pid = fork();
    if (pid == 0)
    {
        // Processo P2: legge dalla pipe e conta le parole
        close(p2p0[0]);  // Chiude il lato di lettura della pipe
        int parole = 0;
        char carattere;
        int inParola = 0;

        while (read(p1p2[0], &carattere, sizeof(carattere)) > 0)
        {
            if (parolaValida(carattere))
            {
                if (inParola)
                {
                    inParola = 0;  // Fine della parola
                    parole++;  // Incrementa il conteggio delle parole
                }
            }
            else
            {
                inParola = 1;  // Inizio di una nuova parola
            }
        }

        // Se l'ultima parola non è seguita da uno spazio, incrementa il conteggio
        if (inParola)
        {
            parole++;
        }

        close(p1p2[0]);  // Chiude il lato di lettura della pipe
        sprintf(str_parole, "%d", parole);  // Converte il numero in stringa

        write(p2p0[1], str_parole, strlen(str_parole));  // Scrive il conteggio nella pipe
        close(p2p0[1]);  // Chiude il lato di scrittura della pipe
        exit(0);  // Termina P2
    }

    // Processo P0: aspetta che P2 finisca e stampa il risultato
    read(p2p0[0], str_parole, sizeof(str_parole));  // Legge il risultato da P2
    printf("Il file %s contiene %s parole.\n", argv[1], str_parole);  // Stampa il numero di parole

    // P0 aspetta che P1 e P2 finiscano
    wait(&pid);
    wait(&pid);

    // Chiude tutte le pipe
    close(p1p2[0]);
    close(p2p0[0]);
    close(p2p0[1]);

    return 0;
}
