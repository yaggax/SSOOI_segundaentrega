#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>

#define NUM_PROCESOS 22 // Número total de procesos en el árbol
int i=-1;
typedef struct {
    pid_t pid;
    pid_t ppid;
    pid_t sig;
} struct_pid;

struct_pid pid[NUM_PROCESOS];
int crearArbol();


void manejador_SIGTERM(int sig) {
    int i;    
    printf("Proceso %d recibió SIGTERM\n", pid[i].pid);
    for(i=0;i<=NUM_PROCESOS;i++){
        if(kill(pid[i].pid,SIGTERM)==-1) perror("Enviandolo al siguiente hijo");
    }
    
    exit(0); // Finalizar el proceso
}





int main() {
    sigset_t conj_vacio, conj_SIGTERM;
  sigfillset(&conj_vacio);
    
    if(sigprocmask( SIG_BLOCK, &conj_vacio, NULL) == -1){
        perror("Error config mascara");
        exit(-1);
        
    } 
   struct sigaction sa;
    sa.sa_handler = manejador_SIGTERM;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    
    char *filename="fichero.txt";
    int fd = open(filename, O_CREAT | O_RDWR);
    if(fd==-1){
        printf("Error en la creacion/apertura del fichero");
    }

    
    crearArbol();
    sigaction(SIGTERM,&sa,NULL);

    
    printf("Enviando SIGTERM desde la raíz (37)...\n");
    kill(pid[i].ppid,SIGTERM);

    return 0;
}


int crearArbol(){
    sigset_t conj_vacio, conj_SIGTERM;
  sigfillset(&conj_vacio);
    
    if(sigprocmask( SIG_BLOCK, &conj_vacio, NULL) == -1){
        perror("Error config mascara");
        exit(-1);
        
    } 
  pid_t pids[NUM_PROCESOS];
  int i = 0;
  pids[i] = fork();
  switch (pids[i]) {
    case -1: perror("Error en el primer fork"); exit(1);
    case 0: i++;
            pid[i].pid = getpid();
            pid[i].ppid = getppid();
            pid[i].sig = pid[i+1].pid;
            //configurar_manejador();   
            printf("Soy el numero 38, mi PID es: %d\n", getpid());                                                             //NUMERO38
            pids[i] = fork();
            switch (pids[i]) {
                
                case -1: perror("Error en el segundo fork"); exit(1);
                case 0: 
                        i++;
                        pid[i].pid = getpid();
                        pid[i].ppid = getppid();
                        pid[i].sig = pid[i+1].pid;
                        //configurar_manejador();
                        printf("Soy el numero 39, mi PID es: %d\n", getpid());                                                             //NUMERO39
                        pids[i] = fork();
                        
                        switch (pids[i]) {
                            
                            case -1: perror("Error en el tercer fork"); exit(1);
                            case 0: 
                                    //configurar_manejador(); 
                                    i++;  
                                    pid[i].pid = getpid();
                                    pid[i].ppid = getppid();
                                    pid[i].sig = pid[i+1].pid;
                                    printf("Soy el numero 40, mi PID es: %d\n", getpid());                                                             //NUMERO40
                                    pids[i] = fork();
                                    
                                    switch (pids[i]) {
                                        
                                        case -1: perror("Error en el quinto fork"); exit(1);
                                        case 0: 
                                                //configurar_manejador();
                                                i++;
                                                pid[i].pid = getpid();
                                                pid[i].ppid = getppid();
                                                pid[i].sig = pid[i+1].pid;
                                                printf("Soy el numero 42, mi PID es: %d\n", getpid());                                                              //NUMERO 42
                                                pids[i] = fork();
                                                
                                                switch (pids[i]) {
                                                    
                                                    case -1: perror("Error en el séptimo fork"); exit(1);
                                                    case 0:
                                                            //configurar_manejador();
                                                            i++;
                                                            pid[i].pid = getpid();
                                                            pid[i].ppid = getppid();
                                                            pid[i].sig = pid[i+1].pid;
                                                            printf("Soy el numero 46, mi PID es: %d\n", getpid());                                                          //NUMERO 46
                                                            pids[i] = fork();
                                                            
                                                            switch (pids[i]) {
                                                                
                                                                case -1: perror("Error en el octavésimo fork"); exit(1);
                                                                case 0:
                                                                        //configurar_manejador();
                                                                        i++;
                                                                        pid[i].pid = getpid();
                                                                        pid[i].ppid = getppid();
                                                                        pid[i].sig = pid[i+1].pid;
                                                                        printf("Soy el numero 50, mi PID es: %d\n", getpid());                                                          //NUMERO 50
                                                                        pids[i] = fork();
                                                                        
                                                                        switch (pids[i]) {
                                                                            
                                                                            case -1: perror("Error en el noveno fork"); exit(1);
                                                                            case 0:
                                                                                //configurar_manejador();
                                                                                i++;
                                                                                pid[i].pid = getpid();
                                                                                pid[i].ppid = getppid();
                                                                                pid[i].sig = pid[i+1].pid;
                                                                                printf("Soy el numero 54, mi PID es: %d\n", getpid());                                                          //NUMERO 54
                                                                                pids[i] = fork();
                                                                                
                                                                                switch (pids[i]) {
                                                                                    
                                                                                    case -1: perror("Error en el décimo fork"); exit(1);
                                                                                    case 0:

                                                                                        //configurar_manejador();
                                                                                        i++;
                                                                                        pid[i].pid = getpid();
                                                                                        pid[i].ppid = getppid();
                                                                                        pid[i].sig = pid[i+1].pid;
                                                                                        printf("Soy el numero 56, mi PID es: %d\n", getpid());                                                          //NUMERO 56
                                                                                        pids[i] = fork();
                                                                                        
                                                                                        switch (pids[i]) {
                                                                                            
                                                                                            case -1: perror("Error en el undécimo fork"); exit(1);
                                                                                            case 0: 
                                                                                                    //configurar_manejador();
                                                                                                    i++;
                                                                                                    pid[i].pid = getpid();
                                                                                                    pid[i].ppid = getppid();
                                                                                                    pid[i].sig = pid[i+1].pid;
                                                                                                    printf("Soy el numero 57, mi PID es: %d\n", getpid());                                                          //NUMERO 57
                                                                                                    pids[i] = fork();
                                                                                                    
                                                                                                    switch (pids[i]) {
                                                                                                        
                                                                                                        case -1: perror("Error en el dodiciésimo fork"); exit(1);
                                                                                                        case 0:
                                                                                                                //configurar_manejador();
                                                                                                                i++;   
                                                                                                                pid[i].pid = getpid();
                                                                                                                pid[i].ppid = getppid();
                                                                                                                pid[i].sig = pid[i+1].pid;
                                                                                                                sigemptyset(&conj_vacio);
                                                                                                                sigaddset(&conj_vacio, SIGTERM);
                                                                                                                sigsuspend(&conj_vacio);                                                                                           
                                                                                                                printf("Soy el numero 58, mi PID es: %d\n", getpid());                                                          //NUMERO 58
                                                                                                                
                                                                                                                
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
                                                            //configurar_manejador();
                                                            i++;
                                                            pid[i].pid = getpid();
                                                            pid[i].ppid = getppid();
                                                            pid[i].sig = pid[i+1].pid;
                                                            printf("Soy el numero 43, mi PID es: %d\n", getpid());                                                  //NUMERO 43
                                                            pids[i] = fork();
                                                            switch(pids[i]){ 
                                                                
                                                                case -1:
                                                                    perror("Error en el decimo septimo fork");
                                                                    exit(1);
                                                                case 0:
                                                                    //configurar_manejador();
                                                                    i++;
                                                                    pid[i].pid = getpid();
                                                                    pid[i].ppid = getppid();
                                                                    pid[i].sig = pid[i+1].pid;
                                                                    printf("Soy el numero 47, mi PID es %d\n",getpid());                                                  //NUMERO 47
                                                                    pids[i] = fork();
                                                                    switch(pids[i]){
                                                                        
                                                                        case -1:
                                                                            perror("Error en el decimo octavo fork");
                                                                            exit(1);
                                                                        case 0:
                                                                                //configurar_manejador();
                                                                            i++;
                                                                            pid[i].pid = getpid();
                                                                            pid[i].ppid = getppid();
                                                                            pid[i].sig = pid[i+1].pid;
                                                                            printf("Soy el numero 51, mi PID es %d\n",getpid());     
                                                                            
                                                                            sigemptyset(&conj_vacio);
                                                                            sigaddset(&conj_vacio, SIGTERM);
                                                                            sigsuspend(&conj_vacio);//NUMERO 51
                                                                            
                                                                        

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
                                                //configurar_manejador();
                                                i++;
                                                pid[i].pid = getpid();
                                                pid[i].ppid = getppid();
                                                pid[i].sig = pid[i+1].pid;
                                                printf("Soy el numero 41, mi PID es: %d\n", getpid());                                                  //NUMERO 41
                                                pids[i] = fork();
                                                switch(pids[i]){
                                                    
                                                    case -1: perror("Error en el decimo noveno fork"); exit(1);
                                                    case 0: 
                                                            //configurar_manejador();
                                                            i++;
                                                            pid[i].pid = getpid();
                                                            pid[i].ppid = getppid();
                                                            pid[i].sig = pid[i+1].pid;
                                                            printf("Soy el numero 44, mi PID es %d\n",getpid());                                                  //NUMERO 44
                                                            pids[i] = fork();
                                                            switch(pids[i]){    
                                                                case -1: perror("Error en el veintiuno fork"); exit(1);
                                                                case 0: 
                                                                        //configurar_manejador();
                                                                        i++;
                                                                        pid[i].pid = getpid();
                                                                        pid[i].ppid = getppid();
                                                                        pid[i].sig = pid[i+1].pid;
                                                                        printf("Soy el numero 48, mi PID es %d\n",getpid());                                                  //NUMERO 48
                                                                        pids[i] = fork();
                                                                        switch(pids[i]){
                                                                            
                                                                            case -1: perror("Error en el fork veintidos"); exit(1);
                                                                            case 0: 
                                                                                //configurar_manejador();
                                                                                i++;
                                                                                pid[i].pid = getpid();
                                                                                pid[i].ppid = getppid();
                                                                                pid[i].sig = pid[i+1].pid;
                                                                                printf("Soy el numero 52, mi PID es %d\n",getpid());                                                  //NUMERO 52
                                                                                pids[i] = fork();
                                                                                switch(pids[i]){
                                                                                    
                                                                                    case -1: perror("Error en el fork veintitres"); exit(1); 
                                                                                    case 0: 
                                                                                        //configurar_manejador();
                                                                                        i++;
                                                                                        pid[i].pid = getpid();
                                                                                        pid[i].ppid = getppid();
                                                                                        pid[i].sig = pid[i+1].pid;
                                                                                        printf("Soy el numero 55, mi PID es %d\n",getpid());                                                  //NUMERO 55
                                                                                        
                                                                                        sigemptyset(&conj_vacio);
                                                                                        sigaddset(&conj_vacio, SIGTERM);
                                                                                        sigsuspend(&conj_vacio);
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

                                                                    //configurar_manejador();
                                                                    i++;
                                                                    pid[i].pid = getpid();
                                                                    pid[i].ppid = getppid();
                                                                    pid[i].sig = pid[i+1].pid;
                                                                    printf("Soy el numero 45, mi PID es %d\n",getpid());                                                  //NUMERO 45
                                                                    pids[i] = fork();
                                                                    switch(pids[i]){
                                                                        
                                                                        case -1: perror("Error en el fork veintitres"); exit(1);
                                                                        case 0:
                                                                            //configurar_manejador();
                                                                            i++;
                                                                            pid[i].pid = getpid();
                                                                            pid[i].ppid = getppid();
                                                                            pid[i].sig = pid[i+1].pid;
                                                                            printf("Soy el numero 49, mi PID es %d\n",getpid());
                                                                            pids[i] = fork();
                                                                            switch(pids[i]){
                                                                                
                                                                                case -1: perror("Error en el fork veintitres"); exit(1);
                                                                                case 0:
                                                                                    //configurar_manejador();
                                                                                    i++;
                                                                                    pid[i].pid = getpid();
                                                                                    pid[i].ppid = getppid();
                                                                                    pid[i].sig = 0;

                                                                                    printf("Soy el numero 53, mi PID es %d\n",getpid());
                                                                                    sigsuspend(&conj_SIGTERM);
                                                                                    
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
        pid[i].pid = getpid();
        pid[i].ppid = getppid();
        pid[i].sig = pid[i+1].pid;        printf("Soy el numero 37, mi PID es: %d\n\n", getpid()); 
        wait(NULL);
        
        
          
        //RAIZ 37
  }
    
  return 0;   
}

