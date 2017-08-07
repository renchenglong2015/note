#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
//僵尸进程：进程结束，父进程未回收,子进程残留资源（PCB）存放在内核中
int main(void){
    pid_t pid;
    pid = fork();
    if(pid == 0){
        printf("我是子进程，我的父进程id是%d\n",getppid());
        sleep(5);
        printf("我死了----------------------------------");
    }else if(pid > 0){
        while(1){
        printf("我是父进程，我的进程id是%d,我的儿子是%d\n",getpid(), pid);
        sleep(1);
        }
    }else{
        perror("fork");
        exit(1);
    }
    return 0;


}
