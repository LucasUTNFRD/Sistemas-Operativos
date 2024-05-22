//
// Created by lucas on 5/2/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char **argv) {
  int i;
  for (i = 0; i < atoi(argv[1]); i++) {
    fork();
    printf("hijo [%d] padre[%d] iteracion[%d]\n", getpid(), getppid(), i);
    if (atoi(argv[2]) == 1)
      sleep(2);
    else
      wait(0);
  }
  return 0;
}
