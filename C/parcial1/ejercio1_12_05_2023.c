//
// Created by lucas on 5/2/24.
//
int main(int argc,char **argv) {
    int i;
    for (i = 0; i < atoi(argv[1]); i++) {
        fork();
        printf("hijo [%d] padre[%d] iteracion[%d]\n", getpid(), getppid(),i);
        if (atoi(argv[2]) == 1) sleep(2);
        else wait(0);
    }
    return 0;
}