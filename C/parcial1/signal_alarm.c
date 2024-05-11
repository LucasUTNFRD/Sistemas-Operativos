#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void handler(void);

volatile int loop = 1;

void handler2(int sig);

int main(void) {
	pid_t pid ;
	pid = fork();
	if (pid > 0)
	{
        signal(SIGALRM,handler2);
        alarm(5);
        handler();
		while(loop){

        }
        wait(NULL);
    }
	else
	{
        alarm(5);
        pause();

    }
	return 0 ;
}

void handler2(int sig){
    loop = 0;
}
void handler(void) { printf("Padre dice hola\n"); }
