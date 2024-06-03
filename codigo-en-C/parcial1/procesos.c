#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  pid_t pid = fork();
  if (pid == -1) {/*fork fallo */
   printf("error en el fork\n"); 
   exit(pid);
  }
  else if (pid == 0) {
    printf("hola mundo soy el hijo %d y mi padre es %d\n",getpid(),getppid());
    exit(9);
  }else{
    printf("hola mundo soy el padre %d y mi padre es %d y mi hijo es %d\n ",getpid(),getppid(),pid);
    exit(7);
  }
  return 0;
}

