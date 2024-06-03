#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork error");
  } else if (pid == 0) { // hijo
    pid = fork();
    if (pid == 0) {
      pid = fork();
    }
  } else { // padre
    pid = fork();
  }
  printf("soy el padre %d de %d mi padre es %d\n", getpid(), pid, getppid());
  wait(NULL);
  wait(NULL);
  exit(0);
  return 0;
}
