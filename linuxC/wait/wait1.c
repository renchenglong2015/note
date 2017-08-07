#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    pid_t pid, wpid;

    pid = fork();
    if(pid == -1){
        perror("fork error");
        exit(1);
    }else if(pid == 0){
        printf("我是儿子进程 pid = %d\n", getpid());
        sleep(7);
    }else{
        wpid = wait(NULL);//阻塞等待子进程退出，回收子进程残留资源，获取子进程结束状态
        if(wpid == -1){
            perror("wait error");
        }
        printf("我是父进程 pid = %d，我回收了子进程 %d\n", getpid(), wpid);
    }
    return 0;
}
