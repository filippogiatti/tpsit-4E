/*Scrivere un programma in linguaggio C che usa il comando 
della shell cat per mostrare a video un file di testo
presente in argv[1]

esempio:
$ ./a.out costituzione.txt*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc < 2)
    {
        printf("Numero argomenti sbagliato");
        return 1;
    }
    execl("/usr/bin/cat", "cat", argv[1], NULL);

    printf("Exec ha terminato con errori");
    return -1;
}



