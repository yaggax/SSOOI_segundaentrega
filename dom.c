#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // Necesario para usar wait()
#include <sys/types.h>

void nonada(int sig){

}

int main() {
    //pid_t pid, pid2, pid3,pid4,pid5,pid6,pid7,pid8,pid9,pid10,pid11,pid12,pid13,pid14,pid15,pid16,pid17,pid18,pid19,pid20;
    pid_t pids[17];
    int i = 0;
    pids[i] = fork();
    switch (pids[i]) {
        
        case -1: perror("Error en el primer fork"); exit(1);
        case 0: i++;
                printf("Soy el numero 38, mi PID es: %d\n", getpid());                                                             //NUMERO38
                pids[i] = fork();
                switch (pids[i]) {
                    
                    case -1: perror("Error en el segundo fork"); exit(1);
                    case 0: i++;
                            printf("Soy el numero 39, mi PID es: %d\n", getpid());                                                             //NUMERO39
                            pids[i] = fork();
                            switch (pids[i]) {
                                
                                case -1: perror("Error en el tercer fork"); exit(1);
                                case 0: i++;
                                        printf("Soy el numero 40, mi PID es: %d\n", getpid());                                                             //NUMERO40
                                        pids[i] = fork();
                                        switch (pids[i]) {
                                            
                                            case -1: perror("Error en el quinto fork"); exit(1);
                                            case 0: i++;
                                                    printf("Soy el numero 42, mi PID es: %d\n", getpid());                                                              //NUMERO 42
                                                    pids[i] = fork();
                                                    switch (pids[i]) {
                                                        
                                                        case -1: perror("Error en el séptimo fork"); exit(1);
                                                        case 0:i++;
                                                                printf("Soy el numero 46, mi PID es: %d\n", getpid());                                                          //NUMERO 46
                                                                pids[i] = fork();
                                                                switch (pids[i]) {
                                                                    
                                                                    case -1: perror("Error en el octavésimo fork"); exit(1);
                                                                    case 0:i++;
                                                                            printf("Soy el numero 50, mi PID es: %d\n", getpid());                                                          //NUMERO 50
                                                                            pids[i] = fork();
                                                                            switch (pids[i]) {
                                                                                
                                                                                case -1: perror("Error en el noveno fork"); exit(1);
                                                                                case 0:i++;
                                                                                    printf("Soy el numero 54, mi PID es: %d\n", getpid());                                                          //NUMERO 54
                                                                                    pids[i] = fork();
                                                                                    switch (pids[i]) {
                                                                                        
                                                                                        case -1: perror("Error en el décimo fork"); exit(1);
                                                                                        case 0:i++;
                                                                                            printf("Soy el numero 56, mi PID es: %d\n", getpid());                                                          //NUMERO 56
                                                                                            pids[i] = fork();
                                                                                            switch (pids[i]) {
                                                                                                
                                                                                                case -1: perror("Error en el undécimo fork"); exit(1);
                                                                                                case 0:i++;
                                                                                                        printf("Soy el numero 57, mi PID es: %d\n", getpid());                                                          //NUMERO 57
                                                                                                        pids[i] = fork();
                                                                                                        switch (pids[i]) {
                                                                                                            
                                                                                                            case -1: perror("Error en el dodiciésimo fork"); exit(1);
                                                                                                            case 0:i++;
                                                                                                                    printf("Soy el numero 58, mi PID es: %d\n", getpid());                                                          //NUMERO 58
                                                                                                                      
                                                                                                                    exit(0);
                                                                                                            default: 
                                                                                                                pause();
                                                                                                                //printf("Soy el padre numero 57, mi PID es: %d\n\n", getpid());
                                                                                                        }
                                                                                                          
                                                                                                        exit(0);
                                                                                                default: 
                                                                                                    pause();
                                                                                                    //printf("Soy el padre numero 56, mi PID es: %d\n\n", getpid());
                                                                                            }
                                                                                              
                                                                                            exit(0);
                                                                                        default: 
                                                                                            pause();
                                                                                            //printf("Soy el padre numero 54, mi PID es: %d\n\n", getpid());
                                                                                    }
                                                                                      
                                                                                    exit(0);
                                                                                default: 
                                                                                    pause();
                                                                                    //printf("Soy el padre numero 50, mi PID es: %d\n\n", getpid());
                                                                            }
                                                                              
                                                                            exit(0);
                                                                    default: 
                                                                        pause();
                                                                        //printf("Soy el padre numero 46, mi PID es: %d\n\n", getpid());
                                                                }
                                                                  
                                                                exit(0);
                                                        default: 
                                                            pause();
                                                            //printf("Soy el padre numero 42, mi PID es: %d\n\n", getpid());
                                                    }
                                                      
                                                    exit(0);
                                            default: 
                                                    i++;
                                                    //printf("Soy el padre numero 40, mi PID es: %d\n\n", getpid());
                                                    pids[i] = fork();
                                                    switch (pids[i]) {
                                                       
                                                        case -1: perror("Error en el sexto fork"); exit(1);
                                                        case 0:  i++;
                                                                printf("Soy el numero 43, mi PID es: %d\n", getpid());                                                  //NUMERO 43
                                                                pids[i] = fork();
                                                                switch(pids[i]){ 
                                                                    
                                                                    case -1:
                                                                        perror("Error en el decimo septimo fork");
                                                                        exit(1);
                                                                    case 0:i++;
                                                                        printf("Soy el numero 47, mi PID es %d\n",getpid());                                                  //NUMERO 47
                                                                        pids[i] = fork();
                                                                        switch(pids[i]){
                                                                            
                                                                            case -1:
                                                                                perror("Error en el decimo octavo fork");
                                                                                exit(1);
                                                                            case 0:i++;
                                                                                printf("Soy el numero 51, mi PID es %d\n",getpid());                                                  //NUMERO 51
                                                                                pause();
                                                                                exit(0);
                                                                            default:
                                                                                pause();
                                                                                //printf("Soy el padre numero 47, mi PID es %d\n\n",getpid());
                                                                        }
                                                                          
                                                                        exit(0);
                                                                    default:
                                                                        pause();
                                                                        //printf("Soy el padre numero 43, mi pid es %d\n\n",getpid());

                                                                }
                                                                  
                                                                exit(0);
                                                        default: 
                                                            pause();
                                                            //printf("Soy el padre numero 40, mi PID es: %d\n\n", getpid());
                                                    }
                                                    pause();

                                            }
                                          
                                        exit(0);
                                default: 
                                    i++;
                                    //printf("Soy el padre numero 39, mi PID es: %d\n", getpid());
                                        pids[i] = fork();

                                        switch (pids[i]) {
                                            
                                            case -1: perror("Error en el cuarto fork"); exit(1);
                                            case 0: i++;
                                                    printf("Soy el numero 41, mi PID es: %d\n", getpid());                                                  //NUMERO 41
                                                    pids[i] = fork();
                                                    switch(pids[i]){
                                                        
                                                        case -1: perror("Error en el decimo noveno fork"); exit(1);
                                                        case 0: i++;
                                                                printf("Soy el numero 44, mi PID es %d\n",getpid());                                                  //NUMERO 44
                                                                pids[i] = fork();
                                                                switch(pids[i]){
                                                                    
                                                                    case -1: perror("Error en el veintiuno fork"); exit(1);
                                                                    case 0: i++;
                                                                            printf("Soy el numero 48, mi PID es %d\n",getpid());                                                  //NUMERO 48
                                                                            pids[i] = fork();
                                                                            switch(pids[i]){
                                                                                
                                                                                case -1: perror("Error en el fork veintidos"); exit(1);
                                                                                case 0: i++;
                                                                                    printf("Soy el numero 52, mi PID es %d\n",getpid());                                                  //NUMERO 52
                                                                                    pids[i] = fork();
                                                                                    switch(pids[i]){
                                                                                        
                                                                                        case -1: perror("Error en el fork veintitres"); exit(1); 
                                                                                        case 0: i++;
                                                                                            printf("Soy el numero 55, mi PID es %d\n",getpid());                                                  //NUMERO 55
                                                                                            pause();
                                                                                            exit(0);
                                                                                        default: 
                                                                                            pause();
                                                                                            //printf("Soy el padre numero 52, mi PID es %d\n\n",getpid());
                                                                                    }
                                                                                      
                                                                                    exit(0);
                                                                                default:
                                                                                    pause();
                                                                                    //printf("Soy el padre numero 48, mi PID es %d\n\n",getpid());
                                                                            }
                                                                              
                                                                            exit(0);
                                                                    default:
                                                                            pause();
                                                                            //printf("Soy el padre numero 44, mi PID es %d\n\n",getpid());
                                                                }
                                                                  
                                                                exit(0);
                                                        default: 
                                                            //printf("Soy el padre numero 41, mi PID es %d\n\n",getpid());
                                                            pids[i] = fork();
                                                            switch(pids[i]){
                                                                
                                                                case -1: perror("Error en el veinteavo fork"); exit(1);
                                                                case 0: i++;
                                                                        printf("Soy el numero 45, mi PID es %d\n",getpid());                                                  //NUMERO 45
                                                                        pids[i] = fork();
                                                                        switch(pids[i]){
                                                                            
                                                                            case -1: perror("Error en el fork veintitres"); exit(1);
                                                                            case 0:i++;
                                                                                printf("Soy el numero 49, mi PID es %d\n",getpid());
                                                                                pids[i] = fork();
                                                                                switch(pids[i]){
                                                                                    
                                                                                    case -1: perror("Error en el fork veintitres"); exit(1);
                                                                                    case 0:i++;
                                                                                        printf("Soy el numero 53, mi PID es %d\n",getpid());
                                                                                        pause();
                                                                                        exit(0);
                                                                                    default:
                                                                                        pause();
                                                                                        //printf("Soy el padre numero 49, mi PID es %d\n\n",getpid());
                                                                                }
                                                                                  
                                                                                exit(0);
                                                                            default:
                                                                                pause();
                                                                                //printf("Soy el padre numero 45, mi PID es %d\n\n",getpid());
                                                                        }
                                                                          
                                                                        exit(0);
                                                                default:
                                                                        pause();
                                                                        //printf("Soy el padre numero 41, mi PID es %d\n\n",getpid());
                                                            }
                                                    }
                                                      
                                                    exit(0);
                                            default: 
                                            pause();
                                            //printf("Soy el padre numero 39, mi PID es: %d\n\n", getpid());
                                        }
                                        pause();
                                         
                            }
                              
                            exit(0);
                    default: 
                    pause();
                    printf("\n"); 
                }
                  
                exit(0); 
        default: 
            pause();
            printf("Soy el numero 37, mi PID es: %d\n\n", getpid());                                                             //RAIZ 37
    }
    return 0;
}