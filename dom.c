#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // Necesario para usar wait()

typedef struct {
    int pid;
    int estado;
} Ficha;

int main() {
    int pid, pid2, pid3,pid4;
    Ficha ficha;

    pid = fork();  
    switch (pid) {
        case -1: perror("Error en el primer fork"); exit(1);
        case 0: 
                printf("Soy el numero 38, mi PID es: %d\n", getpid());
                pid2 = fork();
                switch (pid2) {
                    case -1: perror("Error en el segundo fork"); exit(1);
                    case 0: 
                            printf("Soy el numero 39, mi PID es: %d\n", getpid());
                            pid3 = fork();
                            switch (pid3) {
                                case -1: perror("Error en el tercer fork"); exit(1);
                                case 0: 
                                        printf("Soy el numero 40, mi PID es: %d\n", getpid());
                                        exit(0);
                                default: 
                                    printf("Soy el padre numero 39, mi PID es: %d\n", getpid());
                                        pid4=fork();
                                        switch (pid4) {
                                            case -1: perror("Error en el cuarto fork"); exit(1);
                                            case 0: 
                                                    printf("Soy el numero 41, mi PID es: %d\n", getpid());
                                                    exit(0);
                                            default: printf("Soy el padre numero 39, mi PID es: %d\n", getpid());
                                                    exit(0);
                                        }
                                        exit(0);
                                         
                            }
                            exit(0);
                    default: printf("\n");
                }
                exit(0); 
        default: printf("Soy el numero 37, mi PID es: %d\n", getpid());
    }
    return 0;
}