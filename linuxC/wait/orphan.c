#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
//此示例演示孤儿进程的产生，是由于父进程先于子进程结束，由init进程领养子进程
int main(void){
    pid_t pid;
    pid = fork();
    if(pid == 0){
        while(1){
            printf("我是子进程，我的父进程是%d\n", getppid());
            sleep(1);
        }
    }else if(pid > 0){
        printf("我是父进程，我的进程是%d\n", getpid());
        sleep(5);
        printf("我要死了");
    }else{
        perror("fork");
        exit(1);
    }
    return 0;
}
