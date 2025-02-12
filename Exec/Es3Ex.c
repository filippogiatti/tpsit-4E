/*Scrivere un programma in linguaggio C che usa il comando 
della shell rm per eliminare tutti files presenti
nell'intervallo [argv[1], argv[argc-1]]

esempio:
$ ./a.out /tmp/1.txt /tmp/3.txt /tmp/2.txt*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Numero argomenti sbagliato");
        return 1;
    }
    int i=argc-1;
    do{
        
        execl("/usr/bin/rm", "rm", argv[1], argv[i], NULL);
        i--;

    }while(i==1);
    printf("Exec ha terminato con errori");
    return -1;

}