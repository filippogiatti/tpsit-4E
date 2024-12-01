#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;  

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Sono il processo figlio, il mio PID è %d e il PID del mio genitore è %d\n", getpid(), getppid());
        
        for (int i = 0; i < 10; i++) {
            printf("Figlio: %d\n", i);
        }
    } else {
        printf("Sono il processo padre, il mio PID è %d e il PID del mio figlio è %d\n", getpid(), pid);
        
        for (int i = 0; i < 20; i++) {
            printf("Padre: %d\n", i);
        }
    }

    return 0;
}
