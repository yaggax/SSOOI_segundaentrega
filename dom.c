#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // Necesario para usar wait()
#include <sys/types.h>

typedef struct {
    int pid;
    int estado;
} Ficha;

int main() {
    int pid, pid2, pid3,pid4,pid5,pid6,pid7,pid8,pid9,pid10,pid11,pid12,pid13,pid14,pid15,pid16,pid17,pid18,pid19,pid20;
    Ficha ficha;

    pid = fork();  
    switch (pid) {
        case -1: perror("Error en el primer fork"); exit(1);
        case 0: 
                printf("Soy el numero 38, mi PID es: %d\n", getpid());                                                             //NUMERO38
                pid2 = fork();
                switch (pid2) {
                    case -1: perror("Error en el segundo fork"); exit(1);
                    case 0: 
                            printf("Soy el numero 39, mi PID es: %d\n", getpid());                                                             //NUMERO39
                            pid3 = fork();
                            switch (pid3) {
                                case -1: perror("Error en el tercer fork"); exit(1);
                                case 0: 
                                        printf("Soy el numero 40, mi PID es: %d\n", getpid());                                                             //NUMERO40
                                        pid5=fork();
                                        switch (pid5) {
                                            case -1: perror("Error en el quinto fork"); exit(1);
                                            case 0: 
                                                    printf("Soy el numero 42, mi PID es: %d\n", getpid());                                                              //NUMERO 42
                                                    pid7=fork();
                                                    switch (pid7) {
                                                        case -1: perror("Error en el séptimo fork"); exit(1);
                                                        case 0:
                                                                printf("Soy el numero 46, mi PID es: %d\n", getpid());                                                          //NUMERO 46
                                                                pid8=fork();
                                                                switch (pid8) {
                                                                    case -1: perror("Error en el octavésimo fork"); exit(1);
                                                                    case 0:
                                                                            printf("Soy el numero 50, mi PID es: %d\n", getpid());                                                          //NUMERO 50
                                                                            pid9=fork();
                                                                            switch (pid9) {
                                                                                case -1: perror("Error en el noveno fork"); exit(1);
                                                                                case 0:
                                                                                    printf("Soy el numero 54, mi PID es: %d\n", getpid());                                                          //NUMERO 54
                                                                                    pid10=fork();
                                                                                    switch (pid10) {
                                                                                        case -1: perror("Error en el décimo fork"); exit(1);
                                                                                        case 0:
                                                                                            printf("Soy el numero 56, mi PID es: %d\n", getpid());                                                          //NUMERO 56
                                                                                            pid11=fork();
                                                                                            switch (pid11) {
                                                                                                case -1: perror("Error en el undécimo fork"); exit(1);
                                                                                                case 0:
                                                                                                        printf("Soy el numero 57, mi PID es: %d\n", getpid());                                                          //NUMERO 57
                                                                                                        pid12=fork();
                                                                                                        switch (pid12) {
                                                                                                            case -1: perror("Error en el dodiciésimo fork"); exit(1);
                                                                                                            case 0:
                                                                                                                    printf("Soy el numero 58, mi PID es: %d\n", getpid());                                                          //NUMERO 58
                                                                                                                    pause();
                                                                                                                    exit(0);
                                                                                                            default: printf("Soy el padre numero 57, mi PID es: %d\n\n", getpid());
                                                                                                        }
                                                                                                        pause();
                                                                                                        exit(0);
                                                                                                default: printf("Soy el padre numero 56, mi PID es: %d\n\n", getpid());
                                                                                            }
                                                                                            pause();
                                                                                            exit(0);
                                                                                        default: printf("Soy el padre numero 54, mi PID es: %d\n\n", getpid());
                                                                                    }

                                                                                    pause();
                                                                                    exit(0);
                                                                                default: printf("Soy el padre numero 50, mi PID es: %d\n\n", getpid());
                                                                            }
                                                                            pause();
                                                                            exit(0);
                                                                    default: printf("Soy el padre numero 46, mi PID es: %d\n\n", getpid());
                                                                }
                                                                pause();
                                                                exit(0);
                                                        default: printf("Soy el padre numero 42, mi PID es: %d\n\n", getpid());
                                                    }
                                                    pause();
                                                    exit(0);
                                            default: printf("Soy el padre numero 40, mi PID es: %d\n\n", getpid());
                                                    pid6=fork();
                                                    switch (pid6) {
                                                        case -1: perror("Error en el sexto fork"); exit(1);
                                                        case 0: 
                                                                printf("Soy el numero 43, mi PID es: %d\n", getpid());                                                  //NUMERO 43
                                                                pid13=fork();
                                                                switch(pid13){
                                                                    case -1:
                                                                        perror("Error en el decimo septimo fork");
                                                                        exit(1);
                                                                    case 0:
                                                                        printf("Soy el numero 47, mi PID es %d\n",getpid());                                                  //NUMERO 47
                                                                        pid14=fork();
                                                                        switch(pid14){
                                                                            case -1:
                                                                                perror("Error en el decimo octavo fork");
                                                                                exit(1);
                                                                            case 0:
                                                                                printf("Soy el numero 51, mi PID es %d\n",getpid());                                                  //NUMERO 51
                                                                                pause();
                                                                                exit(0);
                                                                            default:
                                                                                printf("Soy el padre numero 47, mi PID es %d\n\n",getpid());
                                                                        }
                                                                        pause();
                                                                        exit(0);
                                                                    default:
                                                                        printf("Soy el padre numero 43, mi pid es %d\n\n",getpid());

                                                                }
                                                                pause();
                                                                exit(0);
                                                        default: printf("Soy el padre numero 40, mi PID es: %d\n\n", getpid());
                                                                exit(0);
                                                    }
                                                    pause();
                                                    exit(0);
                                        }
                                        pause();
                                        exit(0);
                                default: 
                                    printf("Soy el padre numero 39, mi PID es: %d\n", getpid());
                                        pid4=fork();
                                        switch (pid4) {
                                            case -1: perror("Error en el cuarto fork"); exit(1);
                                            case 0: 
                                                    printf("Soy el numero 41, mi PID es: %d\n", getpid());                                                  //NUMERO 41
                                                    pid15=fork();
                                                    switch(pid15){
                                                        case -1: perror("Error en el decimo noveno fork"); exit(1);
                                                        case 0: printf("Soy el numero 44, mi PID es %d\n",getpid());                                                  //NUMERO 44
                                                                pid16=fork();
                                                                switch(pid16){
                                                                    case -1: perror("Error en el veintiuno fork"); exit(1);
                                                                    case 0: printf("Soy el numero 48, mi PID es %d\n",getpid());                                                  //NUMERO 48
                                                                            pid17=fork();
                                                                            switch(pid17){
                                                                                case -1: perror("Error en el fork veintidos"); exit(1);
                                                                                case 0: 
                                                                                    printf("Soy el numero 52, mi PID es %d\n",getpid());                                                  //NUMERO 52
                                                                                    pid18=fork();
                                                                                    switch(pid18){
                                                                                        case -1: perror("Error en el fork veintitres"); exit(1); 
                                                                                        case 0: 
                                                                                            printf("Soy el numero 55, mi PID es %d\n",getpid());                                                  //NUMERO 55
                                                                                            pause();
                                                                                            exit(0);
                                                                                        default: 
                                                                                            printf("Soy el padre numero 52, mi PID es %d\n\n",getpid());
                                                                                    }
                                                                                    pause();
                                                                                    exit(0);
                                                                                default:
                                                                                    printf("Soy el padre numero 48, mi PID es %d\n\n",getpid());
                                                                            }
                                                                            pause();
                                                                            exit(0);
                                                                    default:
                                                                            printf("Soy el padre numero 44, mi PID es %d\n\n",getpid());
                                                                }
                                                                pause();
                                                                exit(0);
                                                        default: 
                                                            printf("Soy el padre numero 41, mi PID es %d\n\n",getpid());
                                                            pid16=fork();
                                                            switch(pid16){
                                                                case -1: perror("Error en el veinteavo fork"); exit(1);
                                                                case 0: printf("Soy el numero 45, mi PID es %d\n",getpid());                                                  //NUMERO 45
                                                                        pid19=fork();
                                                                        switch(pid19){
                                                                            case -1: perror("Error en el fork veintitres"); exit(1);
                                                                            case 0:
                                                                                printf("Soy el numero 49, mi PID es %d\n",getpid());
                                                                                pid20=fork();
                                                                                switch(pid20){
                                                                                    case -1: perror("Error en el fork veintitres"); exit(1);
                                                                                    case 0:
                                                                                        printf("Soy el numero 53, mi PID es %d\n",getpid());
                                                                                        pause();
                                                                                        exit(0);
                                                                                    default:
                                                                                        printf("Soy el padre numero 49, mi PID es %d\n\n",getpid());
                                                                                }
                                                                                pause();
                                                                                exit(0);
                                                                            default:
                                                                                printf("Soy el padre numero 45, mi PID es %d\n\n",getpid());
                                                                        }
                                                                        pause();
                                                                        exit(0);
                                                                default:
                                                                        printf("Soy el padre numero 41, mi PID es %d\n\n",getpid());
                                                            }
                                                    }
                                                    pause();
                                                    exit(0);
                                            default: printf("Soy el padre numero 39, mi PID es: %d\n\n", getpid());
                                                    exit(0);
                                        }
                                        pause();
                                        exit(0);
                                         
                            }
                            pause();
                            exit(0);
                    default: printf("\n"); 
                }
                pause();
                exit(0); 
        default: 
            
            printf("Soy el numero 37, mi PID es: %d\n\n", getpid());                                                             //RAIZ 37
    }
    return 0;
}