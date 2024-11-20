#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // Necesario para usar wait()

typedef struct {
    int pid;
    int estado;
} Ficha;

int main() {
    int pid, pid2, pid3, pid4, pid5, pid6, pid7, pid8, pid9, pid10, pid11, pid12, pid13, pid14, pid15, pid16;
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
                                        pid5 = fork();
                                        switch (pid5)
                                        {
                                        case -1: perror("Error en el quinto fork"); exit(-1);
                                        case 0:
                                                printf("Soy el numero 42, mi PID es %d\n", getpid());
                                                pid6 = fork();
                                                switch (pid6)
                                                {
                                                case -1: perror("Error en el sexto fork"); exit(-1);
                                                case 0: 
                                                        printf("Soy el numero 46, mi PID es %d\n", getpid());
                                                        pid7 = fork();
                                                        switch (pid7)
                                                        {
                                                        case -1: perror("Error en el septimo fork"); exit(-1);
                                                        case 0:
                                                                printf("Soy el numero 50, mi PID es %d\n", getpid());
                                                                pid8 = fork();
                                                                switch (pid8)
                                                                {
                                                                case -1: perror("Error en el octavo fork"); exit(-1);
                                                                case 0:
                                                                        printf("Soy el numero 54, mi PID es %d\n", getpid());
                                                                        pid9 = fork();
                                                                        switch (pid9)
                                                                        {
                                                                        case -1: perror("Error noveno fork"); exit(-1);
                                                                        case 0:
                                                                                printf("Soy el numero 56, mi PID es %d\n", getpid());
                                                                                pid10 = fork();
                                                                                switch (pid10)
                                                                                {
                                                                                case -1: perror("Error noveno fork"); exit(-1);
                                                                                case 0:
                                                                                        printf("Soy el numero 56, mi PID es %d\n", getpid());
                                                                                        pid11 = fork();
                                                                                        switch (pid11)
                                                                                        {
                                                                                        case -1: perror("Error decimo fork"); exit(-1);
                                                                                        case 0:
                                                                                                printf("Soy el numero 57, mi PID es %d\n", getpid());
                                                                                                pid12 = fork();
                                                                                                switch (pid12)
                                                                                                {
                                                                                                case -1: perror("Error undecimo fork"); exit(-1);
                                                                                                case 0:
                                                                                                        printf("Soy el numero 58, mi PID es %d\n", getpid());
                                                                                                        exit(0);
                                                                                                default:
                                                                                                    printf("Soy el padre numero 57, mi PID es %d\n", getpid());
                                                                                                    break;
                                                                                                }         
                                                                                        default:
                                                                                            printf("Soy el padre numero 56, mi PID es %d\n", getpid());
                                                                                            break;
                                                                                        }         
                                                                                default:
                                                                                    printf("Soy el padre numero 54, mi PID es %d\n", getpid());
                                                                                    break;
                                                                                }                                                                       
                                                                        default:
                                                                            printf("Soy el padre numero 50, mi PID es %d\n", getpid());
                                                                            break;
                                                                        }
                                                                        
                                                                
                                                                default:
                                                                    printf("Soy el padre numero 50, mi PID es %d\n", getpid());
                                                                    break;
                                                                }
                                                        
                                                        default:
                                                            printf("Soy el padre numero 46, mi PID es %d\n", getpid());
                                                            break;
                                                        }
                                                
                                                default:
                                                    printf("Soy el padre numero 42, mi PID es %d\n", getpid());                                                   
                                                    break;
                                                }
                                        
                                        default:
                                            printf("Soy el padre numero 40, mi PID es %d\n", getpid());
                                            break;
                                        }
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