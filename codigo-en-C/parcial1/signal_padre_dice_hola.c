//
// Created by lucas on 5/5/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void mensaje(void);
void alarm_handler(int sig);
//void signal_handler(int sig);

volatile int loop = 1;

int main(void) {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        pause();
        //hijo deberia esperar a que papito imprima
        signal(SIGINT,SIG_DFL);
        //interrumpir
    }
    else {
        signal(SIGALRM,alarm_handler);
        alarm(3);
        while(loop){
//            signal(SIGUSR1,signal_handler);
            mensaje();
        }
        kill(getpid(),SIGINT);
        wait(NULL);//padre debe esperar al hijo
    }
    return 0 ;
}

void alarm_handler(int sig){
    loop = 0;
}


void mensaje(void) {
    printf("Padre dice hola\n");
}