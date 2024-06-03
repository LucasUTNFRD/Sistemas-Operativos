#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
  char *frase = "Hola Querido Mundo 2012";
  pid_t pid;
  int i;
  for (i = 0; i < strlen(frase); i++) {
    pid = fork();
    if (pid > 0) {
      sleep(1); // para sincronizar mejor
      printf("%d = %c\n", getpid(), frase[i]);
      break;
    }
  }
  exit(0);
  return 0;
}

// mismo pero arranca escribiendo el ultimo proceso
int main(void) {
  char *frase = "Hola Querido Mundo 2012";
  pid_t pid;
  int i;
  for (i = 0; i < strlen(frase); i++) {
    pid = fork();
    if (pid > 0)
      break;
  }
  wait(NULL);
  if (i != 0) {
    printf("%d = %c\n", getpid, frase[strlen(frase) - i]);
  }
  exit(0);
  return 0;
}
