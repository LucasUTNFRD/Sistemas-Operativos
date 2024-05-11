#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void write_alphabet(FILE* file, char start, char end) {
    for (char c = start; c <= end; ++c) {
        fprintf(file, "%c", c);
    }
}

int main() {
    FILE* file = fopen("output.txt", "w");
    if (!file) {
        perror("Error al abrir el archivo");
        return 1;
    }

    pid_t pid1 = fork();
    if (pid1 == 0) {
        // Proceso hijo 1: escribe letras mayúsculas
        write_alphabet(file, 'A', 'Z');
        exit(0);
    } else if (pid1 > 0) {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            // Proceso hijo 2: escribe letras minúsculas
            write_alphabet(file, 'a', 'z');
            exit(0);
        } else if (pid2 > 0) {
            // Proceso padre: espera a que ambos hijos terminen
            wait(NULL);
            wait(NULL);
            fclose(file);
            printf("Archivo 'output.txt' creado con éxito.\n");
        } else {
            perror("Error al crear el segundo proceso hijo");
            return 1;
        }
    } else {
        perror("Error al crear el primer proceso hijo");
        return 1;
    }

    return 0;
}
