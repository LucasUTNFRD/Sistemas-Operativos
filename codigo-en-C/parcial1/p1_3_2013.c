#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void *funcion(void *);

int main(void) {
  pthread_t h1;
  pthread_create(&h1, NULL, funcion, NULL);
  pthread_join(h1, NULL);
  return 0;
}

void *funcion(void *p) {
  int fd = open("abecedario", O_CREAT | O_TRUNC | O_WRONLY, 0700);
  int letra = 'A';
  while (letra <= 'Z') {
    write(fd, &letra, 1);
    letra++;
    sleep(2);
  }
  close(fd);
  printf("funcion():fin!\n");
  pthread_exit(0);
}
