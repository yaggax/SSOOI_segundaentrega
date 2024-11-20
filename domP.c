#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // Necesario para usar wait()

typedef struct {
    int pid;
    int estado;
} Ficha;

int main() {
    int pid, pid2;
    Ficha ficha;

    pid = fork();  // Primer fork para crear el primer hijo

    if (pid == -1) {
        perror("Error en el primer fork");
        exit(1);
    }

    if (pid == 0) {  // primer hijo
        printf("Soy el primer hijo, mi PID es: %d\n", getpid());
        exit(0);  // primer hijo termina aquí
    } else {  // Código padre
        ficha.pid = pid;
        ficha.estado = 1;

        pid2 = fork();  // Segundo fork para crear el segundo hijo

        if (pid2 == -1) {
            perror("Error en el segundo fork");
            exit(1);
        }

        if (pid2 == 0) {  // Código del segundo hijo
            printf("Soy el segundo hijo, mi PID es: %d\n", getpid());
            exit(0);  // El segundo hijo termina aquí
        } else {  // Código del padre
            printf("Soy el padre, mi PID es: %d\n", getpid());

            // El padre espera a que ambos hijos terminen
            wait(NULL);  // Espera al primer hijo
            wait(NULL);  // Espera al segundo hijo

            printf("El padre ha terminado, su PID es: %d\n", getpid());
        }
    }

    return 0;
}
