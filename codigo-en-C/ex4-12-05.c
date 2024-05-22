#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int var = 0;
int salir = 0;

void *thread_function(void *args) {
  var++;
  printf("contador :%d\n", var);
  return NULL;
}

void handler_SIGUSR1(int sig) {
  // crear el hilo
  pthread_t thread;
  pthread_create(&thread, NULL, thread_function, NULL);
  pthread_join(thread, NULL);
};

void handler_SIGALRM(int sig) { salir = 1; };

int main(void) {
  signal(SIGUSR1, handler_SIGUSR1);
  signal(SIGALRM, handler_SIGALRM);

  alarm(60);
  while (!salir) {
    // pause();
  }

  return 0;
}
