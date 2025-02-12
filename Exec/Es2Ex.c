/*Scrivere un programma in linguaggio C che usa il comando 
della shell cp per copiare un file da una posizione 
sorgente ad una posizione destinazione

esempio:
$ ./a.out costituzione.txt /tmp/costituzione.txt*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc < 3){
        printf("Numero argomenti sbagliato");
        return 1;
    }

    execl("/usr/bin/cp", "cp", argv[1], argv[2], NULL);
    printf("Exec ha terminato con errori");
    return -1;
}