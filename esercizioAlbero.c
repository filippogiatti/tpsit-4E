#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pid1, pid2;
    printf("Sono il processo P1\n");
    pid1 = fork();

    if(pid1 == 0) {
        printf("Sono nel processo P2\n");

        int pid1_figlio = fork();
        pid2 = fork();

        if(pid1_figlio == 0) {
            printf("Sono nel processo P4\n");
        }
    } else {
        pid2 = fork();

        if(pid2 == 0) {
            printf("Sono nel processo P3\n");
        } else {
            int pid2_figlio1 = fork();
            if(pid2_figlio1 == 0) {
                printf("Sono nel processo P5\n");
            } else {
                int pid2_figlio2 = fork();
                if(pid2_figlio2 == 0) {
                    printf("Sono nel processo P6\n");
                }
            }
        }
    }
    
    if (pid1 != 0 && pid2 != 0) {
        printf("Sono il processo padre\n");
    }
    
    return 0;
}
