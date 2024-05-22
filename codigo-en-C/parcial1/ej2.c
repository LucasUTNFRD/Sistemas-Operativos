#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
void f_child(int);
void f_alarma(int);
void f_usr(int);
int salir = 0;

void f_child(
    int s) { // cuando reciba la senial indica que el proceso hijo a terminado
  printf("f_child():soy %d\n", getpid());
  wait(0);
  salir = 1;
}

void f_alarma(int s) {
  printf("f_alarma():soy %d\n", getpid());
  raise(SIGUSR1); // envia senial a f_usr
}

void f_usr(int s) {
  printf("recibi alarma SIGUSR1\n");
  salir = 1;
} // estable salir 1 permitiendo romper loop

int main(int arg, char *argv[]) {
  signal(SIGCHLD, f_child);
  signal(SIGALRM, f_alarma);
  signal(SIGUSR1, f_usr);
  alarm(2);
  fork();
  printf("Soy el hijo %d hijo de %d\n", getpid(), getppid());
  while (!salir)
    ;
  return 0;
}
