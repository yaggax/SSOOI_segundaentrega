#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // Necesario para usar wait()
#include <sys/types.h>

typedef struct {
    pid_t padre;  
    pid_t hijo;   
    pid_t sig;    
} pid_struct;



void manejadora(int sig, pid_t *pids) {
    printf("Proceso %d recibió SIGTERM. Terminando hijos...\n", getpid());
    exit(0);
}


void matar_proceso(pid_t pid) {
    printf("Enviando SIGTERM al proceso %d\n", pid);
    kill(pid, SIGTERM);  // Enviar señal SIGTERM al proceso indicado
}

int main() {

    struct sigaction ss;
    ss.sa_handler = manejadora;
    sigemptyset(&ss.sa_mask);
    ss.sa_flags = 0;
    sigaction(SIGTERM, &ss, NULL);

    pid_struct pids[22];
    pid_t pid;
    //pid_t pids[17];
    int i = 0;
    pid = fork();
    switch (pid = fork()) {
        case -1: perror("Error en el primer fork"); exit(1);
        case 0: 
                pids[i].hijo = getpid();
                i++;
                printf("Soy el numero 38, mi PID es: %d\n", getpid());                                                             //NUMERO38
                pid = fork();
                switch (pid = fork()) {
                    
                    case -1: perror("Error en el segundo fork"); exit(1);
                    case 0:                 
                            pids[i].hijo = getpid();
                            i++;
                            printf("Soy el numero 39, mi PID es: %d\n", getpid());                                                             //NUMERO39
                            
                            
                            switch (pid = fork()) {
                                
                                case -1: perror("Error en el tercer fork"); exit(1);
                                case 0: 
                                        pids[i].hijo = getpid();
                                        i++;    
                                        printf("Soy el numero 40, mi PID es: %d\n", getpid());                                                             //NUMERO40
                                        
                                        
                                        switch (pid = fork()) {
                                            
                                            case -1: perror("Error en el quinto fork"); exit(1);
                                            case 0:
                                                    pids[i].hijo = getpid();
                                                    i++;
                                                    printf("Soy el numero 42, mi PID es: %d\n", getpid());                                                              //NUMERO 42
                                                    
                                                    
                                                    switch (pid = fork()) {
                                                        
                                                        case -1: perror("Error en el séptimo fork"); exit(1);
                                                        case 0:
                                                                pids[i].hijo = getpid();
                                                                i++;
                                                                printf("Soy el numero 46, mi PID es: %d\n", getpid());                                                          //NUMERO 46
                                                                
                                                                
                                                                switch (pid = fork()) {
                                                                    
                                                                    case -1: perror("Error en el octavésimo fork"); exit(1);
                                                                    case 0:
                                                                            pids[i].hijo = getpid();
                                                                            i++;
                                                                            printf("Soy el numero 50, mi PID es: %d\n", getpid());                                                          //NUMERO 50
                                                                            
                                                                            
                                                                            switch (pid = fork()) {
                                                                                
                                                                                case -1: perror("Error en el noveno fork"); exit(1);
                                                                                case 0:
                                                                                    pids[i].hijo = getpid();
                                                                                    i++;
                                                                                    printf("Soy el numero 54, mi PID es: %d\n", getpid());                                                          //NUMERO 54
                                                                                    
                                                                                    
                                                                                    switch (pid = fork()) {
                                                                                        
                                                                                        case -1: perror("Error en el décimo fork"); exit(1);
                                                                                        case 0:
                                                                                            pids[i].hijo = getpid();
                                                                                            i++;
                                                                                            printf("Soy el numero 56, mi PID es: %d\n", getpid());                                                          //NUMERO 56
                                                                                            
                                                                                            
                                                                                            switch (pid = fork()) {
                                                                                                
                                                                                                case -1: perror("Error en el undécimo fork"); exit(1);
                                                                                                case 0:
                                                                                                        pids[i].hijo = getpid();
                                                                                                        i++;
                                                                                                        printf("Soy el numero 57, mi PID es: %d\n", getpid());                                                          //NUMERO 57
                                                                                                        
                                                                                                        
                                                                                                        switch (pid = fork()) {
                                                                                                            
                                                                                                            case -1: perror("Error en el dodiciésimo fork"); exit(1);
                                                                                                            case 0:
                                                                                                                    pids[i].hijo = getpid();
                                                                                                                    i++;
                                                                                                                    printf("Soy el numero 58, mi PID es: %d\n", getpid());                                                          //NUMERO 58
                                                                                                                    pause();
                                                                                                                    exit(0);
                                                                                                            default: 
                                                                                                                wait(NULL);
                                                                                                                matar_proceso(pids[i].hijo);
                                                                                                                //printf("Soy el padre numero 57, mi PID es: %d\n\n", getpid());
                                                                                                        }
                                                                                                          
                                                                                                        exit(0);
                                                                                                default: 
                                                                                                    wait(NULL);
                                                                                                    matar_proceso(pids[i].hijo);
                                                                                                    //printf("Soy el padre numero 56, mi PID es: %d\n\n", getpid());
                                                                                            }
                                                                                              
                                                                                            exit(0);
                                                                                        default: 
                                                                                            wait(NULL);
                                                                                            matar_proceso(pids[i].hijo);
                                                                                            //printf("Soy el padre numero 54, mi PID es: %d\n\n", getpid());
                                                                                    }
                                                                                      
                                                                                    exit(0);
                                                                                default: 
                                                                                    wait(NULL);
                                                                                    matar_proceso(pids[i].hijo);
                                                                                    //printf("Soy el padre numero 50, mi PID es: %d\n\n", getpid());
                                                                            }
                                                                              
                                                                            exit(0);
                                                                    default: 
                                                                        wait(NULL);
                                                                        matar_proceso(pids[i].hijo);
                                                                        //printf("Soy el padre numero 46, mi PID es: %d\n\n", getpid());
                                                                }
                                                                  
                                                                exit(0);
                                                        default: 
                                                            wait(NULL);
                                                            matar_proceso(pids[i].hijo);
                                                            //printf("Soy el padre numero 42, mi PID es: %d\n\n", getpid());
                                                    }
                                                      
                                                    exit(0);
                                            default: 
                                                    i++;
                                                    //printf("Soy el padre numero 40, mi PID es: %d\n\n", getpid());
                                                    
                                                    switch (pid = fork()) {
                                                       
                                                        case -1: perror("Error en el sexto fork"); exit(1);
                                                        case 0: 
                                                                pids[i].hijo = getpid();
                                                                i++;
                                                                printf("Soy el numero 43, mi PID es: %d\n", getpid());                                                  //NUMERO 43
                                                                
                                                                switch(pid = fork()){ 
                                                                    
                                                                    case -1:
                                                                        perror("Error en el decimo septimo fork");
                                                                        exit(1);
                                                                    case 0:
                                                                        pids[i].hijo = getpid();
                                                                        i++;
                                                                        printf("Soy el numero 47, mi PID es %d\n",getpid());                                                  //NUMERO 47
                                                                        
                                                                        switch(pid = fork()){
                                                                            
                                                                            case -1:
                                                                                perror("Error en el decimo octavo fork");
                                                                                exit(1);
                                                                            case 0:
                                                                                pids[i].hijo = getpid();
                                                                                i++;
                                                                                printf("Soy el numero 51, mi PID es %d\n",getpid());                                                  //NUMERO 51
                                                                                pause();
                                                                                exit(0);
                                                                            default:
                                                                                wait(NULL);
                                                                                matar_proceso(pids[i].hijo);
                                                                                //printf("Soy el padre numero 47, mi PID es %d\n\n",getpid());
                                                                        }
                                                                          
                                                                        exit(0);
                                                                    default:
                                                                        wait(NULL);
                                                                        matar_proceso(pids[i].hijo);
                                                                        //printf("Soy el padre numero 43, mi pid es %d\n\n",getpid());

                                                                }
                                                                  
                                                                exit(0);
                                                        default: 
                                                            wait(NULL);
                                                            matar_proceso(pids[i].hijo); 
                                                            //printf("Soy el padre numero 40, mi PID es: %d\n\n", getpid());
                                                    }
                                                    wait(NULL);

                                            }
                                          
                                        exit(0);
                                default: 
                                    i++;
                                    //printf("Soy el padre numero 39, mi PID es: %d\n", getpid());
                                        

                                        switch (pid = fork()) {
                                            
                                            case -1: perror("Error en el cuarto fork"); exit(1);
                                            case 0: 
                                                    pids[i].hijo = getpid();
                                                    i++;
                                                    printf("Soy el numero 41, mi PID es: %d\n", getpid());                                                  //NUMERO 41
                                                    
                                                    switch(pid = fork()){
                                                        
                                                        case -1: perror("Error en el decimo noveno fork"); exit(1);
                                                        case 0: 
                                                                pids[i].hijo = getpid();
                                                                i++;
                                                                printf("Soy el numero 44, mi PID es %d\n",getpid());                                                  //NUMERO 44
                                                                
                                                                switch(pid = fork()){
                                                                    
                                                                    case -1: perror("Error en el veintiuno fork"); exit(1);
                                                                    case 0: 
                                                                            pids[i].hijo = getpid();
                                                                            i++;
                                                                            printf("Soy el numero 48, mi PID es %d\n",getpid());                                                  //NUMERO 48
                                                                            
                                                                            switch(pid = fork()){
                                                                                
                                                                                case -1: perror("Error en el fork veintidos"); exit(1);
                                                                                case 0: 
                                                                                    pids[i].hijo = getpid();    
                                                                                    i++;
                                                                                    printf("Soy el numero 52, mi PID es %d\n",getpid());                                                  //NUMERO 52
                                                                                    
                                                                                    switch(pid = fork()){
                                                                                        
                                                                                        case -1: perror("Error en el fork veintitres"); exit(1); 
                                                                                        case 0: 
                                                                                            pids[i].hijo = getpid();
                                                                                            i++;
                                                                                            printf("Soy el numero 55, mi PID es %d\n",getpid());                                                  //NUMERO 55
                                                                                            pause();
                                                                                            exit(0);
                                                                                        default: 
                                                                                            wait(NULL);
                                                                                            //printf("Soy el padre numero 52, mi PID es %d\n\n",getpid());
                                                                                    }
                                                                                      
                                                                                    exit(0);
                                                                                default:
                                                                                    wait(NULL);
                                                                                    matar_proceso(pids[i].hijo);
                                                                                    //printf("Soy el padre numero 48, mi PID es %d\n\n",getpid());
                                                                            }
                                                                              
                                                                            exit(0);
                                                                    default:
                                                                            wait(NULL);
                                                                            matar_proceso(pids[i].hijo);
                                                                            //printf("Soy el padre numero 44, mi PID es %d\n\n",getpid());
                                                                }
                                                                  
                                                                exit(0);
                                                        default: 
                                                            //printf("Soy el padre numero 41, mi PID es %d\n\n",getpid());
                                                            
                                                            switch(pid = fork()){
                                                                
                                                                case -1: perror("Error en el veinteavo fork"); exit(1);
                                                                case 0: 
                                                                        pids[i].hijo = getpid();
                                                                        i++;
                                                                        printf("Soy el numero 45, mi PID es %d\n",getpid());                                                  //NUMERO 45
                                                                        
                                                                        switch(pid = fork()){
                                                                            
                                                                            case -1: perror("Error en el fork veintitres"); exit(1);
                                                                            case 0:
                                                                                pids[i].hijo = getpid();
                                                                                i++;
                                                                                printf("Soy el numero 49, mi PID es %d\n",getpid());
                                                                                
                                                                                switch(pid = fork()){
                                                                                    
                                                                                    case -1: perror("Error en el fork veintitres"); exit(1);
                                                                                    case 0:
                                                                                        pids[i].hijo = getpid();
                                                                                        i++;
                                                                                        printf("Soy el numero 53, mi PID es %d\n",getpid());
                                                                                        pause();
                                                                                        exit(0);
                                                                                    default:
                                                                                        wait(NULL);
                                                                                        matar_proceso(pids[i].hijo);
                                                                                        //printf("Soy el padre numero 49, mi PID es %d\n\n",getpid());
                                                                                }
                                                                                  
                                                                                exit(0);
                                                                            default:
                                                                                wait(NULL);
                                                                                matar_proceso(pids[i].hijo);
                                                                                //printf("Soy el padre numero 45, mi PID es %d\n\n",getpid());
                                                                        }
                                                                          
                                                                        exit(0);
                                                                default:
                                                                        wait(NULL);
                                                                        matar_proceso(pids[i].hijo);
                                                                        //printf("Soy el padre numero 41, mi PID es %d\n\n",getpid());
                                                            }
                                                    }
                                                      
                                                    exit(0);
                                            default: 
                                            wait(NULL);
                                            matar_proceso(pids[i].hijo);
                                            //printf("Soy el padre numero 39, mi PID es: %d\n\n", getpid());
                                        }
                                       
                                        wait(NULL);
                                        matar_proceso(pids[i].hijo);
                                         
                            }
                              
                            exit(0);
                    default: 
                    wait(NULL);
                    matar_proceso(pids[i].hijo);
                    printf("\n"); 
                }
                  
                exit(0); 
        default: 
            wait(NULL);
            matar_proceso(pids[i].hijo);
            printf("Soy el numero 37, mi PID es: %d\n\n", getpid()); 
            //RAIZ 37
    }
    pause();
    printf("Proceso raíz enviando SIGTERM a todos los hijos\n");
    // Enviar SIGTERM a todos los hijos vivos
    for ( i = 0; i < 22; i++) {
        if (pids[i].hijo > 0) {
            printf("Enviando SIGTERM al hijo %d desde el proceso %d\n", pids[i].hijo, getpid());
            matar_proceso(pids[i].hijo);
            kill(pids[i].hijo, SIGTERM);
            waitpid(pids[i].hijo, NULL, 0);  // Esperar a que termine
        }
    }  // Enviar SIGTERM a todos los procesos en el grupo
    while (wait(NULL) > 0);  // Esperar a todos los hijos
    printf("Proceso raíz terminado\n");
    return 0;
}

