#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // Necesario para usar wait()
#include <sys/types.h>

void configurar_manejador_SIGTERM();

void configurar_manejador_SIGTERM(void) {
    struct sigaction sa;
    sa.sa_handler = manejador_SIGTERM;  // Asignar el manejador
    sigemptyset(&sa.sa_mask);          // No bloquear señales
    sa.sa_flags = 0;                   // Sin flags adicionales
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error configurando SIGTERM");
        exit(1);
    }
}

int main() {
    
    pid_t pids[22];
    configurar_manejador_SIGTERM();

    pids[0] = fork(); 
    switch (pids[0]) {
        case -1: perror("Error en el primer fork"); exit(1);
        case 0: 
                printf("Soy el numero 38, mi PID es: %d\n", getpid());                                                             //NUMERO38
                configurar_manejador_SIGTERM();
                pids[1] = fork();                
                switch (pids[1]) {
                    case -1: perror("Error en el segundo fork"); exit(1);
                    case 0: 
                            printf("Soy el numero 39, mi PID es: %d\n", getpid());                                                             //NUMERO39
                            pids[2] = fork();                            
                            switch (pids[2]) {
                                case -1: perror("Error en el tercer fork"); exit(1);
                                case 0: 
                                        printf("Soy el numero 40, mi PID es: %d\n", getpid());                                                             //NUMERO40
                                        pids[3] = fork();                                
                                        switch (pids[3]) {
                                            case -1: perror("Error en el quinto fork"); exit(1);
                                            case 0: 
                                                    printf("Soy el numero 42, mi PID es: %d\n", getpid());                                                              //NUMERO 42
                                                    pids[4] = fork();                                
                                                    switch (pids[4]) {
                                                        case -1: perror("Error en el séptimo fork"); exit(1);
                                                        case 0:
                                                                printf("Soy el numero 46, mi PID es: %d\n", getpid());                                                          //NUMERO 46
                                                                pids[5] = fork();                                
                                                                switch (pids[5]) {
                                                                    case -1: perror("Error en el octavésimo fork"); exit(1);
                                                                    case 0:
                                                                            printf("Soy el numero 50, mi PID es: %d\n", getpid());                                                          //NUMERO 50
                                                                            pids[6] = fork();                                
                                                                            switch (pids[6]) {  
                                                                                case -1: perror("Error en el noveno fork"); exit(1);
                                                                                case 0:
                                                                                    printf("Soy el numero 54, mi PID es: %d\n", getpid());                                                          //NUMERO 54
                                                                                    pids[7] = fork();                                
                                                                                    switch (pids[7]) {  
                                                                                        case -1: perror("Error en el décimo fork"); exit(1);
                                                                                        case 0:
                                                                                            printf("Soy el numero 56, mi PID es: %d\n", getpid());                                                          //NUMERO 56
                                                                                            pids[8] = fork();                                
                                                                                            switch (pids[8]) {
                                                                                                case -1: perror("Error en el undécimo fork"); exit(1);
                                                                                                case 0:
                                                                                                        printf("Soy el numero 57, mi PID es: %d\n", getpid());                                                          //NUMERO 57
                                                                                                        pids[9] = fork();                                
                                                                                                        switch (pids[9]) {
                                                                                                            case -1: perror("Error en el dodiciésimo fork"); exit(1);
                                                                                                            case 0:
                                                                                                                    printf("Soy el numero 58, mi PID es: %d\n", getpid());                                                          //NUMERO 58
                                                                                                                    pause();
                                                                                                                    exit(0);
                                                                                                            default: 
                                                                                                                wait(NULL);
                                                                                                            // numero 57, mi PID es: %d\n\n", getpid());
                                                                                                        }
                                                                                                        wait(NULL);
                                                                                                        exit(0);
                                                                                                default: 
                                                                                                    wait(NULL);
                                                                                                // numero 56, mi PID es: %d\n\n", getpid());
                                                                                            }
                                                                                            wait(NULL);
                                                                                            exit(0);
                                                                                        default: 
                                                                                            wait(NULL);
                                                                                        // numero 54, mi PID es: %d\n\n", getpid());
                                                                                    }

                                                                                    wait(NULL);
                                                                                    exit(0);
                                                                                default: // numero 50, mi PID es: %d\n\n", getpid());
                                                                                    wait(NULL);
                                                                            }
                                                                            wait(NULL);
                                                                            exit(0);
                                                                    default: // numero 46, mi PID es: %d\n\n", getpid());
                                                                        wait(NULL);
                                                                }
                                                                wait(NULL);
                                                                exit(0);
                                                        default: 
                                                            wait(NULL);
                                                        // numero 42, mi PID es: %d\n\n", getpid());
                                                    }
                                                    wait(NULL);
                                                    exit(0);
                                            default: // numero 40, mi PID es: %d\n\n", getpid());
                                                    pids[10] = fork();                                
                                                    switch (pids[10]) {
                                                        case -1: perror("Error en el sexto fork"); exit(1);
                                                        case 0: 
                                                                printf("Soy el numero 43, mi PID es: %d\n", getpid());                                                  //NUMERO 43
                                                                pids[11] = fork();                                
                                                                switch(pids[11]){
                                                                    case -1:
                                                                        perror("Error en el decimo septimo fork");
                                                                        exit(1);
                                                                    case 0:
                                                                        printf("Soy el numero 47, mi PID es %d\n",getpid());                                                  //NUMERO 47
                                                                        pids[12] = fork();                                
                                                                        switch(pids[12]){
                                                                            case -1:
                                                                                perror("Error en el decimo octavo fork");
                                                                                exit(1);
                                                                            case 0:
                                                                                printf("Soy el numero 51, mi PID es %d\n",getpid());                                                  //NUMERO 51
                                                                                pause();
                                                                                exit(0);
                                                                            default:
                                                                                wait(NULL);
                                                                                // numero 47, mi PID es %d\n\n",getpid());
                                                                        }
                                                                        wait(NULL);
                                                                        exit(0);
                                                                    default:
                                                                        wait(NULL);
                                                                        // numero 43, mi pid es %d\n\n",getpid());

                                                                }
                                                                wait(NULL);
                                                                exit(0);
                                                        default: 
                                                            wait(NULL);
                                                        // numero 40, mi PID es: %d\n\n", getpid());
                                                                exit(0);
                                                    }
                                                    wait(NULL);
                                                    exit(0);
                                        }
                                        wait(NULL);
                                        exit(0);
                                default: 
                                    // numero 39, mi PID es: %d\n", getpid());
                                        pids[13] = fork();                                
                                        switch (pids[13]) {
                                            case -1: perror("Error en el cuarto fork"); exit(1);
                                            case 0: 
                                                    printf("Soy el numero 41, mi PID es: %d\n", getpid());                                                  //NUMERO 41
                                                    pids[14] = fork();                                
                                                    switch(pids[14]){
                                                        case -1: perror("Error en el decimo noveno fork"); exit(1);
                                                        case 0: printf("Soy el numero 44, mi PID es %d\n",getpid());                                                  //NUMERO 44
                                                                pids[15] = fork();                                
                                                                switch(pids[15]){
                                                                    case -1: perror("Error en el veintiuno fork"); exit(1);
                                                                    case 0: printf("Soy el numero 48, mi PID es %d\n",getpid());                                                  //NUMERO 48
                                                                            pids[15] = fork();                                
                                                                            switch(pids[15]){
                                                                                case -1: perror("Error en el fork veintidos"); exit(1);
                                                                                case 0: 
                                                                                    printf("Soy el numero 52, mi PID es %d\n",getpid());                                                  //NUMERO 52
                                                                                    pids[16] = fork();                                
                                                                                    switch(pids[16]){
                                                                                        case -1: perror("Error en el fork veintitres"); exit(1); 
                                                                                        case 0: 
                                                                                            printf("Soy el numero 55, mi PID es %d\n",getpid());                                                  //NUMERO 55
                                                                                            pause();
                                                                                            exit(0);
                                                                                        default: 
                                                                                            // numero 52, mi PID es %d\n\n",getpid());
                                                                                            wait(NULL);
                                                                                    }
                                                                                    wait(NULL);
                                                                                    exit(0);
                                                                                default:
                                                                                    wait(NULL);
                                                                                    // numero 48, mi PID es %d\n\n",getpid());
                                                                            }
                                                                            wait(NULL);
                                                                            exit(0);
                                                                    default:
                                                                            wait(NULL);
                                                                            // numero 44, mi PID es %d\n\n",getpid());
                                                                }
                                                                wait(NULL);
                                                                exit(0);
                                                        default: 
                                                            // numero 41, mi PID es %d\n\n",getpid());
                                                            pids[17] = fork();
                                                            switch(pids[17]){
                                                                case -1: perror("Error en el veinteavo fork"); exit(1);
                                                                case 0: printf("Soy el numero 45, mi PID es %d\n",getpid());                                                  //NUMERO 45
                                                                        pids[18] = fork();
                                                                        switch(pids[18]){
                                                                            case -1: perror("Error en el fork veintitres"); exit(1);
                                                                            case 0:
                                                                                printf("Soy el numero 49, mi PID es %d\n",getpid());
                                                                                pids[19] = fork();                                
                                                                                switch(pids[19]){
                                                                                    case -1: perror("Error en el fork veintitres"); exit(1);
                                                                                    case 0:
                                                                                        printf("Soy el numero 53, mi PID es %d\n",getpid());
                                                                                        pause();
                                                                                        exit(0);
                                                                                    default:
                                                                                        wait(NULL);
                                                                                        // numero 49, mi PID es %d\n\n",getpid());
                                                                                }
                                                                                wait(NULL);
                                                                                exit(0);
                                                                            default:
                                                                                wait(NULL);
                                                                                // numero 45, mi PID es %d\n\n",getpid());
                                                                        }
                                                                        wait(NULL);
                                                                default:
                                                                        wait(NULL);
                                                                        // numero 41, mi PID es %d\n\n",getpid());
                                                            }
                                                    }
                                                    wait(NULL);
                                            default: 
                                            wait(NULL);
                                            // numero 39, mi PID es: %d\n\n", getpid());
                                        }
                                        wait(NULL);
                                         
                            }
                            wait(NULL);
                            exit(0);
                    default: 
                    wait(NULL);
                }
                wait(NULL);
                exit(0); 
        default: 
            wait(NULL);
            
            printf("Soy el numero 37, mi PID es: %d\n\n", getpid());                                                             //RAIZ 37
    }
    return 0;
}