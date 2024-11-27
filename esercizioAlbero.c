#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pid1, pid2;
    printf("Sono il processo P1");
    pid1 = fork();

    if(pid1==0){
        printf("Sono nel processo P2");

        int pid1_figlio=fork();
        pid2 = fork();
        if(pid1_figlio==0){
            printf("Sono nel processo P4");

        }
    }else{
        pid2=fork;

        if(pid2==0){
            printf("Sono nel processo P3";);
        }else{
            int pid2_figlio1=fork();
            if(pid2_figlio1==0){
                printf("Sono nel processo P5");
            }
        }else{
            int pid2_figlio2=fork();
            if(pid2_figlio2==0){
                printf("sono nel processo P6");
            }
        }
    }else{
        printf("Sono il processo padre");
    }
    
    return 0;
}