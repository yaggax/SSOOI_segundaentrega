#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // Necesario para usar wait()
#include <sys/types.h>

int  crear_arbol(pid_t *pids);
void configurar_manejador();
void matar_proceso(pid_t pid);
void manejadora(int sig,pid_t *pids);

int main() {
    pid_t pids[17];
    struct sigaction ss;
    configurar_manejador();
    crear_arbol(pids);
    pause();
    signal(SIGTERM, manejadora);
    return 0;
}

void manejadora(int sig, pid_t *pids) {
    printf("Manejador recibido señal %d\n", sig);
    int i;
    for(i = 0; i < 22; i++) {
        printf("Matando proceso %d\n", pids[i]);
        kill(pids[i], SIGTERM);
    }
    exit(0);
}

void matar_proceso(pid_t pid) {
    printf("Enviando SIGTERM al proceso %d\n", pid);
    kill(pid, SIGTERM);  // Enviar señal SIGTERM al proceso indicado
}

void configurar_manejador() {
    struct sigaction sa;
    sa.sa_handler = manejadora;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error al configurar SIGTERM");
        exit(1);
    }
}



int crear_arbol(pid_t *pids){
    struct sigaction sa;
    configurar_manejador();
    
    int i = 0;
    pids[i] = fork();
    switch (pids[i]) {
        case -1: perror("Error en el primer fork"); exit(1);
        case 0: i++;
                configurar_manejador();
                printf("Soy el numero 38, mi PID es: %d\n", getpid());                                                             //NUMERO38
                pids[i] = fork();
                switch (pids[i]) {
                    
                    case -1: perror("Error en el segundo fork"); exit(1);
                    case 0: 
                            i++;
                            configurar_manejador();
                            printf("Soy el numero 39, mi PID es: %d\n", getpid());                                                             //NUMERO39
                            pids[i] = fork();
                            
                            switch (pids[i]) {
                                
                                case -1: perror("Error en el tercer fork"); exit(1);
                                case 0: 
                                        configurar_manejador(); 
                                        i++;    
                                        printf("Soy el numero 40, mi PID es: %d\n", getpid());                                                             //NUMERO40
                                        pids[i] = fork();
                                        
                                        switch (pids[i]) {
                                            
                                            case -1: perror("Error en el quinto fork"); exit(1);
                                            case 0: 
                                                    configurar_manejador();
                                                    i++;
                                                    printf("Soy el numero 42, mi PID es: %d\n", getpid());                                                              //NUMERO 42
                                                    pids[i] = fork();
                                                    
                                                    switch (pids[i]) {
                                                        
                                                        case -1: perror("Error en el séptimo fork"); exit(1);
                                                        case 0:
                                                                configurar_manejador();
                                                                i++;
                                                                printf("Soy el numero 46, mi PID es: %d\n", getpid());                                                          //NUMERO 46
                                                                pids[i] = fork();
                                                                
                                                                switch (pids[i]) {
                                                                    
                                                                    case -1: perror("Error en el octavésimo fork"); exit(1);
                                                                    case 0:
                                                                            configurar_manejador();
                                                                            i++;
                                                                            printf("Soy el numero 50, mi PID es: %d\n", getpid());                                                          //NUMERO 50
                                                                            pids[i] = fork();
                                                                            
                                                                            switch (pids[i]) {
                                                                                
                                                                                case -1: perror("Error en el noveno fork"); exit(1);
                                                                                case 0:
                                                                                    configurar_manejador();
                                                                                    i++;
                                                                                    printf("Soy el numero 54, mi PID es: %d\n", getpid());                                                          //NUMERO 54
                                                                                    pids[i] = fork();
                                                                                    
                                                                                    switch (pids[i]) {
                                                                                        
                                                                                        case -1: perror("Error en el décimo fork"); exit(1);
                                                                                        case 0:
                                                                                            configurar_manejador();
                                                                                            i++;
                                                                                            printf("Soy el numero 56, mi PID es: %d\n", getpid());                                                          //NUMERO 56
                                                                                            pids[i] = fork();
                                                                                            
                                                                                            switch (pids[i]) {
                                                                                                
                                                                                                case -1: perror("Error en el undécimo fork"); exit(1);
                                                                                                case 0: 
                                                                                                        configurar_manejador();
                                                                                                        i++;
                                                                                                        printf("Soy el numero 57, mi PID es: %d\n", getpid());                                                          //NUMERO 57
                                                                                                        pids[i] = fork();
                                                                                                        
                                                                                                        switch (pids[i]) {
                                                                                                            
                                                                                                            case -1: perror("Error en el dodiciésimo fork"); exit(1);
                                                                                                            case 0:
                                                                                                                    configurar_manejador();
                                                                                                                    i++;   
                                                                                                                    pids[i] = getpid();                                                                                                                 
                                                                                                                    printf("Soy el numero 58, mi PID es: %d\n", getpid());                                                          //NUMERO 58
                                                                                                                    sigaction(SIGTERM, &sa, NULL);
                                                                                                                    pause();
                                                                                                                    exit(0);
                                                                                                            default: 
                                                                                                                wait(NULL);
                                                                                                                
                                                                                                                //printf("Soy el padre numero 57, mi PID es: %d\n\n", getpid());
                                                                                                        }
                                                                                                          
                                                                                                        exit(0);
                                                                                                default: 
                                                                                                    wait(NULL);
                                                                                                    
                                                                                                    //printf("Soy el padre numero 56, mi PID es: %d\n\n", getpid());
                                                                                            }
                                                                                              
                                                                                            exit(0);
                                                                                        default: 
                                                                                            wait(NULL);
                                                                                            
                                                                                            //printf("Soy el padre numero 54, mi PID es: %d\n\n", getpid());
                                                                                    }
                                                                                      
                                                                                    exit(0);
                                                                                default: 
                                                                                    wait(NULL);
                                                                                    
                                                                                    //printf("Soy el padre numero 50, mi PID es: %d\n\n", getpid());
                                                                            }
                                                                              
                                                                            exit(0);
                                                                    default: 
                                                                        wait(NULL);
                                                                        
                                                                        //printf("Soy el padre numero 46, mi PID es: %d\n\n", getpid());
                                                                }
                                                                  
                                                                exit(0);
                                                        default: 
                                                            wait(NULL);
                                                            
                                                            //printf("Soy el padre numero 42, mi PID es: %d\n\n", getpid());
                                                    }
                                                      
                                                    exit(0);
                                            default: 
                                                    i++;
                                                    //printf("Soy el padre numero 40, mi PID es: %d\n\n", getpid());
                                                    pids[i] = fork();
                                                    switch (pids[i]) {
                                                       
                                                        case -1: perror("Error en el sexto fork"); exit(1);
                                                        case 0: 
                                                                configurar_manejador();
                                                                i++;
                                                                printf("Soy el numero 43, mi PID es: %d\n", getpid());                                                  //NUMERO 43
                                                                pids[i] = fork();
                                                                switch(pids[i]){ 
                                                                    
                                                                    case -1:
                                                                        perror("Error en el decimo septimo fork");
                                                                        exit(1);
                                                                    case 0:
                                                                        configurar_manejador();
                                                                        i++;
                                                                        printf("Soy el numero 47, mi PID es %d\n",getpid());                                                  //NUMERO 47
                                                                        pids[i] = fork();
                                                                        switch(pids[i]){
                                                                            
                                                                            case -1:
                                                                                perror("Error en el decimo octavo fork");
                                                                                exit(1);
                                                                            case 0:
                                                                                    configurar_manejador();
                                                                                i++;
                                                                                pids[i] = getpid();
                                                                                printf("Soy el numero 51, mi PID es %d\n",getpid());                                                  //NUMERO 51
                                                                                sigaction(SIGTERM, &sa, NULL);
                                                                                pause();
                                                                                exit(0);
                                                                            default:
                                                                                wait(NULL);
                                                                                
                                                                                //printf("Soy el padre numero 47, mi PID es %d\n\n",getpid());
                                                                        }
                                                                          
                                                                        exit(0);
                                                                    default:
                                                                        wait(NULL);
                                                                        
                                                                        //printf("Soy el padre numero 43, mi pid es %d\n\n",getpid());

                                                                }
                                                                  
                                                                exit(0);
                                                        default: 
                                                            wait(NULL);
                                                             
                                                            //printf("Soy el padre numero 40, mi PID es: %d\n\n", getpid());
                                                    }
                                                    wait(NULL);

                                            }
                                          
                                        exit(0);
                                default: 
                                    i++;
                                    //printf("Soy el padre numero 39, mi PID es: %d\n", getpid());
                                        pids[i] = fork();

                                        switch (pids[i]) {     
                                            case -1: perror("Error en el cuarto fork"); exit(1);
                                            case 0: 
                                                    configurar_manejador();
                                                    i++;
                                                    printf("Soy el numero 41, mi PID es: %d\n", getpid());                                                  //NUMERO 41
                                                    pids[i] = fork();
                                                    switch(pids[i]){
                                                        
                                                        case -1: perror("Error en el decimo noveno fork"); exit(1);
                                                        case 0: 
                                                                configurar_manejador();
                                                                i++;
                                                                printf("Soy el numero 44, mi PID es %d\n",getpid());                                                  //NUMERO 44
                                                                pids[i] = fork();
                                                                switch(pids[i]){    
                                                                    case -1: perror("Error en el veintiuno fork"); exit(1);
                                                                    case 0: 
                                                                            configurar_manejador();
                                                                            i++;
                                                                            printf("Soy el numero 48, mi PID es %d\n",getpid());                                                  //NUMERO 48
                                                                            pids[i] = fork();
                                                                            switch(pids[i]){
                                                                                
                                                                                case -1: perror("Error en el fork veintidos"); exit(1);
                                                                                case 0: 
                                                                                    configurar_manejador();
                                                                                    i++;
                                                                                    printf("Soy el numero 52, mi PID es %d\n",getpid());                                                  //NUMERO 52
                                                                                    pids[i] = fork();
                                                                                    switch(pids[i]){
                                                                                        
                                                                                        case -1: perror("Error en el fork veintitres"); exit(1); 
                                                                                        case 0: 
                                                                                            configurar_manejador();
                                                                                            i++;
                                                                                            pids[i] = getpid();
                                                                                            printf("Soy el numero 55, mi PID es %d\n",getpid());                                                  //NUMERO 55
                                                                                            sigaction(SIGTERM, &sa, NULL);
                                                                                            pause();
                                                                                            exit(0);
                                                                                        default: 
                                                                                            wait(NULL);
                                                                                            //printf("Soy el padre numero 52, mi PID es %d\n\n",getpid());
                                                                                    }
                                                                                      
                                                                                    exit(0);
                                                                                default:
                                                                                    wait(NULL);
                                                                                    
                                                                                    //printf("Soy el padre numero 48, mi PID es %d\n\n",getpid());
                                                                            }
                                                                              
                                                                            exit(0);
                                                                    default:
                                                                            wait(NULL);
                                                                            
                                                                            //printf("Soy el padre numero 44, mi PID es %d\n\n",getpid());
                                                                }
                                                                  
                                                                exit(0);
                                                        default: 
                                                            //printf("Soy el padre numero 41, mi PID es %d\n\n",getpid());
                                                            pids[i] = fork();
                                                            switch(pids[i]){
                                                                
                                                                case -1: perror("Error en el veinteavo fork"); exit(1);
                                                                case 0: 
                                                                        configurar_manejador();
                                                                        i++;
                                                                        printf("Soy el numero 45, mi PID es %d\n",getpid());                                                  //NUMERO 45
                                                                        pids[i] = fork();
                                                                        switch(pids[i]){
                                                                            
                                                                            case -1: perror("Error en el fork veintitres"); exit(1);
                                                                            case 0:
                                                                                configurar_manejador();
                                                                                i++;
                                                                                printf("Soy el numero 49, mi PID es %d\n",getpid());
                                                                                pids[i] = fork();
                                                                                switch(pids[i]){
                                                                                    
                                                                                    case -1: perror("Error en el fork veintitres"); exit(1);
                                                                                    case 0:
                                                                                        configurar_manejador();
                                                                                        i++;
                                                                                        pids[i] = getpid();
                                                                                        printf("Soy el numero 53, mi PID es %d\n",getpid());
                                                                                        sigaction(SIGTERM, &sa, NULL);
                                                                                        pause();
                                                                                        exit(0);
                                                                                    default:
                                                                                        wait(NULL);
                                                                                        
                                                                                        //printf("Soy el padre numero 49, mi PID es %d\n\n",getpid());
                                                                                }
                                                                                  
                                                                                exit(0);
                                                                            default:
                                                                                wait(NULL);
                                                                                
                                                                                //printf("Soy el padre numero 45, mi PID es %d\n\n",getpid());
                                                                        }
                                                                          
                                                                        exit(0);
                                                                default:
                                                                        wait(NULL);
                                                                        
                                                                        //printf("Soy el padre numero 41, mi PID es %d\n\n",getpid());
                                                            }
                                                    }
                                                      
                                                    exit(0);
                                            default: 
                                            wait(NULL);
                                            
                                            //printf("Soy el padre numero 39, mi PID es: %d\n\n", getpid());
                                        }
                                       
                                        wait(NULL);
                                        
                                         
                            }
                              
                            exit(0);
                    default: 
                    wait(NULL);
                }
                  
                exit(0); 
        default: 
            wait(NULL);
            
            printf("Soy el numero 37, mi PID es: %d\n\n", getpid()); 
            //RAIZ 37
    }
    
    return 0;   
}

