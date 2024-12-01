#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 == -1) {
        perror("Fork 1 failed");
        exit(1);
    }

    if (pid1 == 0) {
        printf("Sono un processo figlio, il mio PID è %d, mio padre ha PID=%d, Ciao sono Qui\n", getpid(), getppid());
        exit(0);  
    } else {
        pid2 = fork();
        if (pid2 == -1) {
            perror("Fork 2 failed");
            exit(1);
        }

        if (pid2 == 0) {
            printf("Sono un processo figlio, il mio PID è %d, mio padre ha PID=%d, Ciao sono Quo\n", getpid(), getppid());
            exit(0);  
        } else {
            pid3 = fork();
            if (pid3 == -1) {
                perror("Fork 3 failed");
                exit(1);
            }

            if (pid3 == 0) {
                printf("Sono un processo figlio, il mio PID è %d, mio padre ha PID=%d, Ciao sono Qua\n", getpid(), getppid());
                exit(0);  
            } else {
                printf("Sono il processo padre, il mio PID=%d, mio figlio ha PID=%d\n", getpid(), pid1);
                printf("Sono il processo padre, il mio PID=%d, mio figlio ha PID=%d\n", getpid(), pid2);
                printf("Sono il processo padre, il mio PID=%d, mio figlio ha PID=%d\n", getpid(), pid3);
            }
        }
    }

    return 0;
}
