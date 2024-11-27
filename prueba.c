#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void configurar_manejador();
void manejadora(int sig);

int crear_arbol(int nivel, int max_nivel, pid_t *pids, int *indice);

int main() {
    pid_t pids[17];
    configurar_manejador();
    crear_arbol(0, 3, pids, 0); // Ajustar max_nivel según sea necesario
    pause();
    return 0;
}

void manejadora(int sig) {
    printf("Manejador recibido señal %d\n", sig);
    // Asumiendo que pids contiene todos los PIDs hasta el índice actual
    int i;
    for ( i = 0; i < *indice; i++) {
        kill(pids[i], SIGTERM);
    }
    exit(0);
}

void configurar_manejador() {
struct sigaction sa;
    sa.sa_handler = manejadora;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error al configurar SIGTERM");
        exit(1);
    }}

int crear_arbol(int nivel, int max_nivel, pid_t *pids, int *indice) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("Error en fork");
        exit(1);
    } else if (pid == 0) { // Proceso hijo
        configurar_manejador();
        printf("Soy el proceso %d, nivel %d\n", getpid(), nivel);
        if (nivel < max_nivel) {
            crear_arbol(nivel + 1, max_nivel, pids, indice);
        }
        pause();
    } else { // Proceso padre
        pids[*indice] = pid;
        (*indice)++;
        if (nivel < max_nivel) {
            crear_arbol(nivel + 1, max_nivel, pids, indice);
        }
        wait(NULL);
    }
    return 0;
}