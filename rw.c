#include <stdio.h>
#include <stdlib.h>

# define BUFFER_DIM 1024

int main(int argc, char* argv[]){
    FILE *origine, *destinazione;
    unsigned char buffer[BUFFER_DIM];
    int n;

    if(argc!=3)
    {
        printf("Errore nell'inserimento degli argomenti da linea di comando");
        exit(1);
    }
    origine=fopen(argv[1], "r");
    if(origine==NULL)
    {
        printf("Errore apertura file origine");
        exit(1);
    }
    else{
        destinazione=fopen(argv[2], "w");
        if(destinazione==NULL)
        {
            printf("Errore apertura file destinazione");
            exit(1);
        }
        else{
            while(!feof(origine))
            {
                n=fread(buffer,1,BUFFER_DIM,origine);
                if(n>0)
                fwrite(buffer,1,n,destinazione);
            }

        }
    }
    fclose(origine);
    fclose(destinazione);

    return 0;
}