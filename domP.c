#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct {
    int pid;
    int estado;
} Ficha;

int main() {
    int pid, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9, pid10, pid11, pid12, pid13, pid14, pid15, pid16, pid17, pid18, pid19, pid20;

    pid = fork();
    switch (pid) {
        case -1:
            perror("Error al crear el proceso 38");
            exit(1);

        case 0: // Proceso 38
            printf("Soy el número 38, mi PID es: %d\n", getpid());

            pid2 = fork();
            switch (pid2) {
                case -1:
                    perror("Error al crear el proceso 39");
                    exit(1);

                case 0: // Proceso 39
                    printf("Soy el número 39, mi PID es: %d\n", getpid());

                    pid3 = fork();
                    switch (pid3) {
                        case -1:
                            perror("Error al crear el proceso 40");
                            exit(1);

                        case 0: // Proceso 40
                            printf("Soy el número 40, mi PID es: %d\n", getpid());

                            pid5 = fork();
                            switch (pid5) {
                                case -1:
                                    perror("Error al crear el proceso 42");
                                    exit(1);

                                case 0: // Proceso 42
                                    printf("Soy el número 42, mi PID es: %d\n", getpid());

                                    pid7 = fork();
                                    switch (pid7) {
                                        case -1:
                                            perror("Error al crear el proceso 46");
                                            exit(1);

                                        case 0: // Proceso 46
                                            printf("Soy el número 46, mi PID es: %d\n", getpid());
                                            pause();
                                            exit(0);

                                        default:
                                            wait(NULL);
                                            pause(); // Espera indefinida para 42
                                            exit(0);
                                    }

                                default:
                                    pid6 = fork();
                                    switch (pid6) {
                                        case -1:
                                            perror("Error al crear el proceso 43");
                                            exit(1);

                                        case 0: // Proceso 43
                                            printf("Soy el número 43, mi PID es: %d\n", getpid());

                                            pid13 = fork();
                                            switch (pid13) {
                                                case -1:
                                                    perror("Error al crear el proceso 47");
                                                    exit(1);

                                                case 0: // Proceso 47
                                                    printf("Soy el número 47, mi PID es: %d\n", getpid());
                                                    pause();
                                                    exit(0);

                                                default:
                                                    wait(NULL);
                                                    pause(); // Espera indefinida para 43
                                                    exit(0);
                                            }

                                        default:
                                            wait(NULL);
                                            pause(); // Espera indefinida para 40
                                            exit(0);
                                    }
                            }

                        default:
                            pid4 = fork();
                            switch (pid4) {
                                case -1:
                                    perror("Error al crear el proceso 41");
                                    exit(1);

                                case 0: // Proceso 41
                                    printf("Soy el número 41, mi PID es: %d\n", getpid());

                                    pid15 = fork();
                                    switch (pid15) {
                                        case -1:
                                            perror("Error al crear el proceso 44");
                                            exit(1);

                                        case 0: // Proceso 44
                                            printf("Soy el número 44, mi PID es: %d\n", getpid());

                                            pid16 = fork();
                                            switch (pid16) {
                                                case -1:
                                                    perror("Error al crear el proceso 48");
                                                    exit(1);

                                                case 0: // Proceso 48
                                                    printf("Soy el número 48, mi PID es: %d\n", getpid());
                                                    pause();
                                                    exit(0);

                                                default:
                                                    wait(NULL);
                                                    pause(); // Espera indefinida para 44
                                                    exit(0);
                                            }

                                        default:
                                            pid19 = fork();
                                            switch (pid19) {
                                                case -1:
                                                    perror("Error al crear el proceso 45");
                                                    exit(1);

                                                case 0: // Proceso 45
                                                    printf("Soy el número 45, mi PID es: %d\n", getpid());

                                                    pid20 = fork();
                                                    switch (pid20) {
                                                        case -1:
                                                            perror("Error al crear el proceso 49");
                                                            exit(1);

                                                        case 0: // Proceso 49
                                                            printf("Soy el número 49, mi PID es: %d\n", getpid());
                                                            pause();
                                                            exit(0);

                                                        default:
                                                            wait(NULL);
                                                            pause(); // Espera indefinida para 45
                                                            exit(0);
                                                    }

                                                default:
                                                    wait(NULL);
                                                    pause(); // Espera indefinida para 41
                                                    exit(0);
                                            }
                                    }

                                default:
                                    wait(NULL);
                                    pause(); // Espera indefinida para 39
                                    exit(0);
                            }
                    }

                default:
                    wait(NULL);
                    pause(); // Espera indefinida para 38
                    exit(0);
            }

        default:
            printf("Soy el número 37, mi PID es: %d\n", getpid());
            wait(NULL); // Esperar a 38
            pause(); // Espera indefinida para 37
    }

    return 0;
}
