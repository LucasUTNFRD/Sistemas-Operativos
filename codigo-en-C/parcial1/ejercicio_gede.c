//
// Created by lucas on 5/5/24.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>


int main(int argc,char *argv[]){
   pid_t pid;
   for(size_t i =1;i<argc;i++){
       pid = fork();
       if(pid<0){
           perror("fork error\n");
       }else if(pid == 0){//proceso hijo
           if(execlp(argv[i],argv[i],NULL)==-1){
               perror("exec error");
           }

       }else{//proceso padre
           waitpid(pid,NULL,0);// aca tenes que esperar al hijo
       }
//    printf("argumento : %s\n",argv[i]);
   }

}