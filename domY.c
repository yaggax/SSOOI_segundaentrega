#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define NUM_PROCESOS 22 // Número total de procesos en el árbol

typedef struct {
    pid_t pid;
    pid_t ppid;
    pid_t sig;
} struct_pid;

struct_pid pid[NUM_PROCESOS];
void propagar_SIGTERM(pid_t padre);
void manejador_SIGTERM(int sig) {
    printf("Proceso %d recibió SIGTERM\n", getpid());
    propagar_SIGTERM(getpid()); // Propagar la señal a los descendientes
    exit(0); // Finalizar el proceso
}

// Función recursiva para propagar SIGTERM
void propagar_SIGTERM(pid_t padre) {
    int i;
    for ( i = 0; i < NUM_PROCESOS; i++) {
        if (pid[i].ppid == padre) { // Si es hijo del proceso actual
            kill(pid[i].pid, SIGTERM); // Enviar SIGTERM al hijo
            propagar_SIGTERM(pid[i].pid); // Recursión para los descendientes
        }
    }
}

// Función para crear un nuevo proceso


int crearArbol(){
  
  pid_t pids[NUM_PROCESOS];
  int i = 0;
  pids[i] = fork();
  switch (pids[i]) {
    case -1: perror("Error en el primer fork"); exit(1);
    case 0: i++;
            pid[i].pid = getpid();
            pid[i].ppid = getppid();
            //configurar_manejador();   
            printf("Soy el numero 38, mi PID es: %d\n", getpid());                                                             //NUMERO38
            pids[i] = fork();
            switch (pids[i]) {
                
                case -1: perror("Error en el segundo fork"); exit(1);
                case 0: 
                        i++;
                        pid[i].pid = getpid();
                        pid[i].ppid = getppid();
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
                                    printf("Soy el numero 40, mi PID es: %d\n", getpid());                                                             //NUMERO40
                                    pids[i] = fork();
                                    
                                    switch (pids[i]) {
                                        
                                        case -1: perror("Error en el quinto fork"); exit(1);
                                        case 0: 
                                                //configurar_manejador();
                                                i++;
                                                pid[i].pid = getpid();
                                                pid[i].ppid = getppid();
                                                printf("Soy el numero 42, mi PID es: %d\n", getpid());                                                              //NUMERO 42
                                                pids[i] = fork();
                                                
                                                switch (pids[i]) {
                                                    
                                                    case -1: perror("Error en el séptimo fork"); exit(1);
                                                    case 0:
                                                            //configurar_manejador();
                                                            i++;
                                                            pid[i].pid = getpid();
                                                            pid[i].ppid = getppid();
                                                            printf("Soy el numero 46, mi PID es: %d\n", getpid());                                                          //NUMERO 46
                                                            pids[i] = fork();
                                                            
                                                            switch (pids[i]) {
                                                                
                                                                case -1: perror("Error en el octavésimo fork"); exit(1);
                                                                case 0:
                                                                        //configurar_manejador();
                                                                        i++;
                                                                        pid[i].pid = getpid();
                                                                        pid[i].ppid = getppid();
                                                                        printf("Soy el numero 50, mi PID es: %d\n", getpid());                                                          //NUMERO 50
                                                                        pids[i] = fork();
                                                                        
                                                                        switch (pids[i]) {
                                                                            
                                                                            case -1: perror("Error en el noveno fork"); exit(1);
                                                                            case 0:
                                                                                //configurar_manejador();
                                                                                i++;
                                                                                pid[i].pid = getpid();
                                                                                pid[i].ppid = getppid();
                                                                                printf("Soy el numero 54, mi PID es: %d\n", getpid());                                                          //NUMERO 54
                                                                                pids[i] = fork();
                                                                                
                                                                                switch (pids[i]) {
                                                                                    
                                                                                    case -1: perror("Error en el décimo fork"); exit(1);
                                                                                    case 0:

                                                                                        //configurar_manejador();
                                                                                        i++;
                                                                                        pid[i].pid = getpid();
                                                                                        pid[i].ppid = getppid();
                                                                                        printf("Soy el numero 56, mi PID es: %d\n", getpid());                                                          //NUMERO 56
                                                                                        pids[i] = fork();
                                                                                        
                                                                                        switch (pids[i]) {
                                                                                            
                                                                                            case -1: perror("Error en el undécimo fork"); exit(1);
                                                                                            case 0: 
                                                                                                    //configurar_manejador();
                                                                                                    i++;
                                                                                                    pid[i].pid = getpid();
                                                                                                    pid[i].ppid = getppid();
                                                                                                    printf("Soy el numero 57, mi PID es: %d\n", getpid());                                                          //NUMERO 57
                                                                                                    pids[i] = fork();
                                                                                                    
                                                                                                    switch (pids[i]) {
                                                                                                        
                                                                                                        case -1: perror("Error en el dodiciésimo fork"); exit(1);
                                                                                                        case 0:
                                                                                                                //configurar_manejador();
                                                                                                                i++;   
                                                                                                                pid[i].pid = getpid();
                                                                                                                pid[i].ppid = getppid();
                                                                                                                pid[i].sig = 1;
                                                                                                                                                                                                            
                                                                                                                printf("Soy el numero 58, mi PID es: %d\n", getpid());                                                          //NUMERO 58
                                                                                                                
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
                                                            //configurar_manejador();
                                                            i++;
                                                            pid[i].pid = getpid();
                                                            pid[i].ppid = getppid();
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
                                                                            pid[i].sig = 2;
                                                                            printf("Soy el numero 51, mi PID es %d\n",getpid());                                                  //NUMERO 51
                                                                            
                                                                        

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
                                                //configurar_manejador();
                                                i++;
                                                pid[i].pid = getpid();
                                                pid[i].ppid = getppid();
                                                printf("Soy el numero 41, mi PID es: %d\n", getpid());                                                  //NUMERO 41
                                                pids[i] = fork();
                                                switch(pids[i]){
                                                    
                                                    case -1: perror("Error en el decimo noveno fork"); exit(1);
                                                    case 0: 
                                                            //configurar_manejador();
                                                            i++;
                                                            pid[i].pid = getpid();
                                                            pid[i].ppid = getppid();
                                                            printf("Soy el numero 44, mi PID es %d\n",getpid());                                                  //NUMERO 44
                                                            pids[i] = fork();
                                                            switch(pids[i]){    
                                                                case -1: perror("Error en el veintiuno fork"); exit(1);
                                                                case 0: 
                                                                        //configurar_manejador();
                                                                        i++;
                                                                        pid[i].pid = getpid();
                                                                        pid[i].ppid = getppid();
                                                                        printf("Soy el numero 48, mi PID es %d\n",getpid());                                                  //NUMERO 48
                                                                        pids[i] = fork();
                                                                        switch(pids[i]){
                                                                            
                                                                            case -1: perror("Error en el fork veintidos"); exit(1);
                                                                            case 0: 
                                                                                //configurar_manejador();
                                                                                i++;
                                                                                pid[i].pid = getpid();
                                                                                pid[i].ppid = getppid();
                                                                                printf("Soy el numero 52, mi PID es %d\n",getpid());                                                  //NUMERO 52
                                                                                pids[i] = fork();
                                                                                switch(pids[i]){
                                                                                    
                                                                                    case -1: perror("Error en el fork veintitres"); exit(1); 
                                                                                    case 0: 
                                                                                        //configurar_manejador();
                                                                                        i++;
                                                                                        pid[i].pid = getpid();
                                                                                        pid[i].ppid = getppid();
                                                                                        pid[i].sig = 3;
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
                                                                    printf("Soy el numero 45, mi PID es %d\n",getpid());                                                  //NUMERO 45
                                                                    pids[i] = fork();
                                                                    switch(pids[i]){
                                                                        
                                                                        case -1: perror("Error en el fork veintitres"); exit(1);
                                                                        case 0:
                                                                            //configurar_manejador();
                                                                            i++;
                                                                            pid[i].pid = getpid();
                                                                            pid[i].ppid = getppid();
                                                                            printf("Soy el numero 49, mi PID es %d\n",getpid());
                                                                            pids[i] = fork();
                                                                            switch(pids[i]){
                                                                                
                                                                                case -1: perror("Error en el fork veintitres"); exit(1);
                                                                                case 0:
                                                                                    //configurar_manejador();
                                                                                    i++;
                                                                                    pid[i].pid = getpid();
                                                                                    pid[i].ppid = getppid();
                                                                                    pid[i].sig = 4;

                                                                                    printf("Soy el numero 53, mi PID es %d\n",getpid());
                                                                                    
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

int main() {
    struct sigaction sa;
    sa.sa_handler = manejador_SIGTERM;  // Manejador de señales
    sigemptyset(&sa.sa_mask);  // No bloquear ninguna señal durante la ejecución del manejador
    sa.sa_flags = 0;  // Sin flags especiales
    crearArbol();

    
    sigaction(SIGTERM, &sa,NULL); 
    printf("Enviando SIGTERM desde la raíz (37)...\n");

    return 0;
}



// int crearArbol(){
//   struct_pid pids[NUM_PROCESOS];
//   pid_t pid[NUM_PROCESOS];
//   int cont = 0;
//   switch(pid[cont] = fork()){
//     case -1:
//       printf("Error en fork\n");
//       exit(1);
// //38
//     case 0:
//       printf("Proceso hijo %d\n", getpid());
//       pids[cont].pid = getpid();
//       pids[cont].ppid = getppid();
//       //pids[cont].sig = pid;
//       cont++;
//       switch(pid[cont] = fork()){
//         case -1:
//           printf("Error en fork\n");
//           exit(1);
// //39
//         case 0:
//           printf("Proceso hijo %d\n", getpid());
//           pids[cont].pid = getpid();
//           pids[cont].ppid = getppid();
//           //pids[cont].sig = pid;
//           cont++;
//           switch(pid[cont] = fork()){
//             case -1:
//               printf("Error en fork\n");
//               exit(1);
//  //40
//             case 0:
//               printf("Proceso hijo %d\n", getpid());
//               pids[cont].pid = getpid();
//               pids[cont].ppid = getppid();
//               //pids[cont].sig = pid;
//               cont++;
//               switch(pid[cont] = fork()){
//                 case -1:
//                   printf("Error en fork\n");
//                   exit(1);
//   //40
//                 case 0:
//                   printf("Proceso hijo %d\n", getpid());
//                   pids[cont].pid = getpid();
//                   pids[cont].ppid = getppid();
//                   //pids[cont].sig = pid;
//                   cont++;
//                   switch(pid[cont] = fork()){
//                     case -1:
//                       printf("Error en fork\n");
//                       exit(1);
//    //42
//                     case 0:
//                       printf("Proceso hijo %d\n", getpid());
//                       pids[cont].pid = getpid();
//                       pids[cont].ppid = getppid();
//                       //pids[cont].sig = pid;
//                       cont++;
//                       switch(pid[cont] = fork()){
//                         case -1:
//                           printf("Error en fork\n");
//                           exit(1);
//    //46
//                         case 0:
//                           printf("Proceso hijo %d\n", getpid());
//                           pids[cont].pid = getpid();
//                           pids[cont].ppid = getppid();
//                           //pids[cont].sig = pid;
//                           cont++;
//                           switch(pid[cont] = fork()){
//                             case -1:
//                               printf("Error en fork\n");
//                               exit(1);
//     //50
//                             case 0:
//                               printf("Proceso hijo %d\n", getpid());
//                               pids[cont].pid = getpid();
//                               pids[cont].ppid = getppid();
//                               //pids[cont].sig = pid;
//                               cont++;
//                               switch(pid[cont] = fork()){
//                                 case -1:
//                                   printf("Error en fork\n");
//                                   exit(1);  
//      //54
//                                 case 0:
//                                   printf("Proceso hijo %d\n", getpid());
//                                   pids[cont].pid = getpid();
//                                   pids[cont].ppid = getppid();
//                                   //pids[cont].sig = pid;
//                                   cont++;
//                                   switch(pid[cont] = fork()){
//                                     case -1:
//                                       printf("Error en fork\n");
//                                       exit(1);
//       //56
//                                     case 0:
//                                       printf("Proceso hijo %d\n", getpid());
//                                       pids[cont].pid = getpid();
//                                       pids[cont].ppid = getppid();
//                                       //pids[cont].sig = pid;
//                                       cont++;
//                                       switch(pid[cont] = fork()){
//                                         case -1:
//                                           printf("Error en fork\n");
//                                           exit(1);
//        //58
//                                         case 0:
//                                           printf("Proceso hijo %d\n", getpid());
//                                           pids[cont].pid = getpid();
//                                           pids[cont].ppid = getppid();
//                                           pause();
//                                           //pids[cont].sig = pid;
//                                           cont++;
//                                         default:
//                                           printf("Proceso padre %d\n", getpid());
//                                           pids[cont].pid = getpid();
//                                           pids[cont].ppid = getppid();
//                                           //pids[cont].sig = pid;
//                                           cont++;
//                                           pause();
//                                       }
//                                     default:
//                                       printf("Proceso padre %d\n", getpid());
//                                       pids[cont].pid = getpid();
//                                       pids[cont].ppid = getppid();
//                                       //pids[cont].sig = pid; 
//                                       cont++;
//                                       pause();
//                                   }
//                                 default:
//                                   printf("Proceso padre %d\n", getpid());
//                                   pids[cont].pid = getpid();
//                                   pids[cont].ppid = getppid();
//                                   //pids[cont].sig = pid;
//                                   cont++;
//                                   pause();
//                               }
//                             default:
//                               printf("Proceso padre %d\n", getpid());
//                               pids[cont].pid = getpid();
//                               pids[cont].ppid = getppid();
//                               //pids[cont].sig = pid;  
//                               cont++;
//                               pause();
//                           }
//                         default:
//                           pids[cont].pid = getpid();
//                           pids[cont].ppid = getppid();
//                           //pids[cont].sig = pid;
//                           cont++;
//                           printf("Proceso padre %d\n", getpid());
//                           pause();

//                   }
//                   default:
//                     pids[cont].pid = getpid();
//                     pids[cont].ppid = getppid();
//                     //pids[cont].sig = pid;
//                     cont++;
//                     printf("Proceso padre %d\n", getpid());
//                     pause();
//                     switch(pid[cont] = fork()){
//                       case -1:
//                         printf("Error en fork\n");
//                         exit(1);
//    //43
//                       case 0:
//                         printf("Proceso hijo %d\n", getpid());
//                         pids[cont].pid = getpid();
//                         pids[cont].ppid = getppid();
//                         //pids[cont].sig = pid;
//                         cont++;
//                         switch(pid[cont] = fork()){
//                           case -1:
//                             printf("Error en fork\n");
//                             exit(1);
//    //47                          
//                           case 0:
//                             printf("Proceso hijo %d\n", getpid());
//                             pids[cont].pid = getpid();
//                             pids[cont].ppid = getppid();
//                             //pids[cont].sig = pid;
//                             cont++;
//                             switch(pid[cont] = fork()){
//                               case -1:
//                                 printf("Error en fork\n");
//                                 exit(1);
//     //51
//                               case 0:
//                                 printf("Proceso hijo %d\n", getpid());
//                                 pids[cont].pid = getpid();
//                                 pids[cont].ppid = getppid();
//                                 //pids[cont].sig = pid;
//                                 cont++;
//                                 pause();
//                               default:
//                                 pids[cont].pid = getpid();
//                                 pids[cont].ppid = getppid();
//                                 //pids[cont].sig = pid;
//                                 cont++;
//                                 printf("Proceso padre %d\n", getpid());
//                                 pause();
//                             }
//                           default:
//                             pids[cont].pid = getpid();
//                             pids[cont].ppid = getppid();
//                             //pids[cont].sig = pid;
//                             cont++;
//                             printf("Proceso padre %d\n", getpid());
//                             pause();
//                         }
//                       default:
//                         pids[cont].pid = getpid();
//                         pids[cont].ppid = getppid();
//                         //pids[cont].sig = pid;
//                         cont++;
//                         printf("Proceso padre %d\n", getpid());
//                         pause();
//                   }
//               }

//               switch(pid[cont] = fork()){
//                 case -1:
//                   printf("Error en fork\n");
//                   exit(1);
//   //41
//                 case 0:
//                   printf("Proceso hijo %d\n", getpid());
//                   pids[cont].pid = getpid();
//                   pids[cont].ppid = getppid();
//                   //pids[cont].sig = pid;
//                   cont++;
//                   switch(pid[cont] = fork()){
//                     case -1:
//                       printf("Error en fork\n");
//                       exit(1);
//   //44
//                     case 0:
//                       printf("Proceso hijo %d\n", getpid());
//                       pids[cont].pid = getpid();
//                       pids[cont].ppid = getppid();
//                       //pids[cont].sig = pid;
//                       cont++;
//                       switch(pid[cont] = fork()){
//                         case -1:
//                           printf("Error en fork\n");
//                           exit(1);
//    //48
//                         case 0:
//                           printf("Proceso hijo %d\n", getpid());
//                           pids[cont].pid = getpid();
//                           pids[cont].ppid = getppid();
//                           //pids[cont].sig = pid;
//                           cont++;
//                           switch(pid[cont] = fork()){
//                             case -1:
//                               printf("Error en fork\n");
//                               exit(1);
//     //52
//                             case 0:
//                               printf("Proceso hijo %d\n", getpid());
//                               pids[cont].pid = getpid();
//                               pids[cont].ppid = getppid();
//                               //pids[cont].sig = pid;
//                               cont++;
//                               switch(pid[cont] = fork()){
//                                 case -1:
//                                   printf("Error en fork\n");
//                                   exit(1);
//      //55
//                                 case 0:
//                                   printf("Proceso hijo %d\n", getpid());
//                                   pids[cont].pid = getpid();
//                                   pids[cont].ppid = getppid();
//                                   //pids[cont].sig = pid;
//                                   cont++;
//                                   pause();
//                                 default:
//                                   pids[cont].pid = getpid();
//                                   pids[cont].ppid = getppid();
//                                   //pids[cont].sig = pid;
//                                   cont++;
//                                   printf("Proceso padre %d\n", getpid());
//                                   pause();
//                               }
//                             default:
//                               pids[cont].pid = getpid();
//                               pids[cont].ppid = getppid();
//                               //pids[cont].sig = pid;
//                               cont++;
//                               printf("Proceso padre %d\n", getpid());
//                               pause();
//                           }
//                         default:
//                           pids[cont].pid = getpid();
//                           pids[cont].ppid = getppid();
//                           //pids[cont].sig = pid;
//                           cont++;
//                           printf("Proceso padre %d\n", getpid());
//                           pause();
//                       }
                        
//                     default:
//                       pids[cont].pid = getpid();
//                       pids[cont].ppid = getppid();
//                       //pids[cont].sig = pid;
//                       cont++;
//                       printf("Proceso padre %d\n", getpid());
//                       switch(pid[cont] = fork()){
//                         case -1:
//                           printf("Error en fork\n");
//                           exit(1);
//   //45                          
//                         case 0:
//                           printf("Proceso hijo %d\n", getpid());
//                           pids[cont].pid = getpid();
//                           pids[cont].ppid = getppid();
//                           //pids[cont].sig = pid;
//                           cont++;
//                           switch(pid[cont] = fork()){
//                             case -1:
//                               printf("Error en fork\n");
//                               exit(1);
//    //49
//                             case 0:
//                               printf("Proceso hijo %d\n", getpid());
//                               pids[cont].pid = getpid();
//                               pids[cont].ppid = getppid();
//                               //pids[cont].sig = pid;
//                               cont++;
//                               switch(pid[cont] = fork()){
//                                 case -1:
//                                   printf("Error en fork\n");
//                                   exit(1);
                                  
//     //53
//                                 case 0:
//                                   printf("Proceso hijo %d\n", getpid());
//                                   pids[cont].pid = getpid();
//                                   pids[cont].ppid = getppid();
//                                   //pids[cont].sig = pid;
//                                   cont++;
//                                   pause();
//                                 default:
//                                   pids[cont].pid = getpid();
//                                   pids[cont].ppid = getppid();
//                                   //pids[cont].sig = pid;
//                                   cont++;
//                                   printf("Proceso padre %d\n", getpid());
//                                   pause();
//                               }
//                             default:
//                               pids[cont].pid = getpid();
//                               pids[cont].ppid = getppid();
//                               //pids[cont].sig = pid;
//                               cont++;
//                               printf("Proceso padre %d\n", getpid());
//                               pause();
//                           }
//                         default:
//                           pids[cont].pid = getpid();
//                           pids[cont].ppid = getppid();
//                           //pids[cont].sig = pid;
//                           cont++;
//                           printf("Proceso padre %d\n", getpid());
//                           pause();
//                       }
//                       pause();
//                   }
//                 default:
//                   pids[cont].pid = getpid();
//                   pids[cont].ppid = getppid();
//                   //pids[cont].sig = pid;
//                   cont++;
//                   printf("Proceso padre %d\n", getpid());
//                   pause();
                  
//               }
//              default:
//               pids[cont].pid = getpid();
//               pids[cont].ppid = getppid();
//               //pids[cont].sig = pid;
//               cont++;
//               printf("Proceso padre %d\n", getpid());
//               pause();
//           }
//         default://39
//           pids[cont].pid = getpid();
//           pids[cont].ppid = getppid();
//           //pids[cont].sig = pid; 
//           cont++;
//           printf("Proceso padre %d\n", getpid());
//           pause();
          
//       }
//       exit(0);
//     default://38
//       pids[cont].pid = getpid();
//       pids[cont].ppid = getppid();
//       //pids[cont].sig = pid;
//       cont++;
//       printf("Proceso padre %d\n", getpid());
//       pause();
      
//     }
//     default: //37
//       pids[cont].pid = getpid();
//       pids[cont].ppid = getppid();
//       //pids[cont].sig = pid;
//       cont++;
//       printf("Proceso padre %d\n", getpid());
//       pause();
//   }
//   return 0;

// }