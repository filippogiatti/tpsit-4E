/*Si vuole realizzare un software concorrente in linguaggio C che legga un file di testo da argv[1] e conteggi il numero di parole presenti nel file.
Una volta effettuato il conteggio il programma principale deve mostrarlo a video.

Note operative:
P0 genera P1 il quale legge il contenuto del file usando il comando cat. 
P2 legge da pipe il flusso di caratteri e capisce quando finisce una parola e ne inizia un'altra, in modo da poter aggiornare il contatore. 
P2 invia a P0 il totale 
P0 stampa a video il totale.

Esempio:
$ ./a.out file.txt
Nel file sono presenti 10 parole*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int p1p2[2], p2p0[2], pid;
    char cnt[100];

    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
       
        close(p1p2[0]);      
        dup2(p1p2[1], 1);   
        close(p1p2[1]);     

        execl("/bin/cat", "cat", argv[1], NULL);
        exit(1);  
    }

    close(p1p2[1]); 

    pipe(p2p0);
    pid = fork();
    if (pid == 0)
    {
        
        close(p2p0[0]);      
        dup2(p1p2[0], 0);    
        close(p1p2[0]);      

        dup2(p2p0[1], 1);    
        close(p2p0[1]);     

        execl("/usr/bin/wc", "wc", "-w", NULL);
        exit(1);  
    }

    close(p1p2[0]); 
    close(p2p0[1]); 

   
    read(p2p0[0], cnt, sizeof(cnt) - 1);
    cnt[sizeof(cnt) - 1] = '\0'; 

    close(p2p0[0]);

    
    wait(NULL);
    wait(NULL);

    printf("Il file ha %d parole\n", atoi(cnt));

    return 0;
}
