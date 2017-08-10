#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int n = 5, i;
    pid_t p, q;
    if(argc == 2){
        n = atoi(argv[1]);
    }
    for(i = 0; i < n; i++){
        p = fork();
        if(p == 0){
            break;
        }
    }
    if(i == n){
        sleep(n);
        printf("我是父进程，pid = %d\n", getpid());
        for(i = 0; i < n; i++){
            q = waitpid(-1, NULL, WNOHANG);
            printf("wait pid = %d\n", q);
        }
        while(1);
    }else{
        sleep(i);
        printf("I'm %dth child, pid = %d\n", i+1, getpid());
    }
}
