#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
//   O_TRUNC: This flag specifies that if the file already exists and is a regular file, and if it is successfully opened for writing or appending, its length shall be truncated to 0.
//
// O_CREAT: This flag specifies that if the file does not exist, it shall be created.
//
// O_WRONLY: This flag specifies that the file is opened for writing only.
//
// 0777: This is the mode of the file. It specifies the permissions for the newly created file. 0777 in octal means that the file will have read, write, and execute permissions for the owner, group, and others.
  int fd = open("abcedario",O_TRUNC|O_CREAT|O_WRONLY,0777);
  pid_t pid = fork();
  char cp = 'a';
  char cc = 'A';
  if (pid > 0) {/*parent process */
    while(cp<='z'){
      write(fd,&cp,1);
      cp++;
    }
  }else if (pid == 0) { /*child process */
  
  }{
    while (cc<='Z') {
      write(fd,&cc,1);
      cc++;
    }
  }
  close(fd);

  return 0;
}

