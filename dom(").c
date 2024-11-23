#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // Para usar wait()

int main() {
    int pid37, pid39, pid40, pid41, pid42, pid43, pid44, pid45, pid48, pid49, pid52, pid53;

    pid37 = fork();  
    switch (pid37) {
        case -1: 
            perror("Error en el primer fork"); 
            exit(1);
        case 0: // Proceso hijo 38
            printf("Soy el número 38, mi PID es: %d\n", getpid());
            
            pid39 = fork();
            switch (pid39) {
                case -1: 
                    perror("Error en el segundo fork"); 
                    exit(1);
                case 0: // Proceso hijo 39
                    printf("Soy el número 39, mi PID es: %d\n", getpid());

                    pid40 = fork();
                    switch (pid40) {
                        case -1: 
                            perror("Error en el tercer fork"); 
                            exit(1);
                        case 0: // Proceso hijo 40
                            printf("Soy el número 40, mi PID es: %d\n", getpid());
                            exit(0);
                        default: // Continuamos con el padre 39
                            pid41 = fork();
                            switch (pid41) {
                                case -1: 
                                    perror("Error en el cuarto fork"); 
                                    exit(1);
                                case 0: // Proceso hijo 41
                                    printf("Soy el número 41, mi PID es: %d\n", getpid());

                                    pid42 = fork();
                                    switch (pid42) {
                                        case -1: 
                                            perror("Error en el quinto fork"); 
                                            exit(1);
                                        case 0: // Proceso hijo 42
                                            printf("Soy el número 42, mi PID es: %d\n", getpid());
                                            exit(0);
                                        default:
                                            pid43 = fork();
                                            switch (pid43) {
                                                case -1: 
                                                    perror("Error en el sexto fork"); 
                                                    exit(1);
                                                case 0: // Proceso hijo 43
                                                    printf("Soy el número 43, mi PID es: %d\n", getpid());
                                                    exit(0);
                                                default: // Continuamos con el padre 41
                                                    pid44 = fork();
                                                    switch (pid44) {
                                                        case -1: 
                                                            perror("Error en el séptimo fork"); 
                                                            exit(1);
                                                        case 0: // Proceso hijo 44
                                                            printf("Soy el número 44, mi PID es: %d\n", getpid());

                                                            pid48 = fork();
                                                            switch (pid48) {
                                                                case -1: 
                                                                    perror("Error en el octavo fork"); 
                                                                    exit(1);
                                                                case 0: // Proceso hijo 48
                                                                    printf("Soy el número 48, mi PID es: %d\n", getpid());

                                                                    pid52 = fork();
                                                                    switch (pid52) {
                                                                        case -1: 
                                                                            perror("Error en el noveno fork"); 
                                                                            exit(1);
                                                                        case 0: // Proceso hijo 52
                                                                            printf("Soy el número 52, mi PID es: %d\n", getpid());
                                                                            exit(0);
                                                                        default:
                                                                            exit(0);
                                                                    }
                                                                default:
                                                                    exit(0);
                                                            }
                                                        default: 
                                                            pid45 = fork();
                                                            switch (pid45) {
                                                                case -1: 
                                                                    perror("Error en el décimo fork"); 
                                                                    exit(1);
                                                                case 0: // Proceso hijo 45
                                                                    printf("Soy el número 45, mi PID es: %d\n", getpid());

                                                                    pid49 = fork();
                                                                    switch (pid49) {
                                                                        case -1: 
                                                                            perror("Error en el undécimo fork"); 
                                                                            exit(1);
                                                                        case 0: // Proceso hijo 49
                                                                            printf("Soy el número 49, mi PID es: %d\n", getpid());

                                                                            pid53 = fork();
                                                                            switch (pid53) {
                                                                                case -1: 
                                                                                    perror("Error en el duodécimo fork"); 
                                                                                    exit(1);
                                                                                case 0: // Proceso hijo 53
                                                                                    printf("Soy el número 53, mi PID es: %d\n", getpid());
                                                                                    exit(0);
                                                                                default:
                                                                                    exit(0);
                                                                            }
                                                                        default:
                                                                            exit(0);
                                                                    }
                                                                default:
                                                                    exit(0);
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                default:
                    wait(NULL); // Esperamos a los hijos
                    exit(0);
            }
        default: 
            printf("Soy el número 37, mi PID es: %d\n", getpid());
            wait(NULL); // Esperamos al hijo 38
    }
    return 0;
}
