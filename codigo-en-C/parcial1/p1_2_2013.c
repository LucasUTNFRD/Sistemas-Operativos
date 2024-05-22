#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(void);
int fd = 0;
int main() {
  fd = open("abecedario", O_CREAT | O_TRUNC | O_WRONLY, 0700);
  signal(SIGUSR1, (void *)handler);
  alarm(7);
  while (1) {
    raise(SIGUSR1);
    kill(getpid(), SIGUSR1);
  }
  close(fd);
  exit(0);
}
void handler(void) {
  static char letra = 'A';
  write(fd, &letra, 1);
  letra++;
  pause();
}
