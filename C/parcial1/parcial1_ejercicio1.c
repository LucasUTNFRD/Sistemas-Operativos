//
// Created by lucas on 5/2/24.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    pid = fork();
    pid = fork();
    printf("pid es %d\n",pid);
    if (pid>0){
        fork();
        printf("pid es %d\n",pid);
    }
    return pid;

}
