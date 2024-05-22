#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

volatile int salir = 0;
volatile int cMayus, cMinus = 0;

void sig_handler(int sig) { // solo puede salir ambos esta completos
  if (cMayus == 26 && cMinus == 26) {
    salir = 1;
  } else {
    printf("el abcedario no esta completo por alguno de los hilos\n");
  }
};

void *escribir_minusculas(void *args) {
  int fd = open("abcmin.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  char minuscula = 'a';
  while (minuscula <= 'z') {
    printf("letra escrita %c: ,contador: %d\n", minuscula, cMinus);
    write(fd, &minuscula, 1);
    sleep(1); // simular que demora en escribir
    minuscula++;
    cMinus++;
  }
  close(fd);
  return NULL;
};

void *escribir_mayusuculas(void *args) {
  int fd = open("abcmay.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  char mayuscula = 'A';
  while (mayuscula <= 'Z') {
    printf("letra escrita %c: ,contador: %d\n", mayuscula, cMayus);
    write(fd, &mayuscula, 1);
    sleep(1); // simular que demora en escribir
    mayuscula++;
    cMayus++;
  }
  close(fd);
  return NULL;
};

int main(void) {
  signal(SIGUSR1, sig_handler);
  pthread_t hilo1, hilo2;
  pthread_create(&hilo1, NULL, escribir_minusculas, NULL);
  pthread_create(&hilo2, NULL, escribir_mayusuculas, NULL);
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);
  while (!salir)
    ;

  return 0;
}
