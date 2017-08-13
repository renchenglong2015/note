#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}
int main(void){
    pid_t pid;
    char buf[1024];
    int fd[2];
    char *p = "中国共产党万岁!!!!!\n";

    //pipe创建管道，fd[0],fd[1]分别指向读端写端
    if(pipe(fd) == -1){
        sys_err("pipe");
    }
    pid = fork();
    //父进程关闭管道读端，子进程关闭管道写端。父进程向子进程中写入数据。
    if(pid < 0){
        sys_err("fork error");
    }else if(pid == 0){
        close(fd[1]);
        int len = read(fd[0],buf, sizeof(buf));
        write(STDOUT_FILENO, buf, len);
        close(fd[0]);
    }else{
        close(fd[0]);
        sleep(2);
        write(fd[1], p, strlen(p));
        wait(NULL);
        close(fd[1]);
    }
    return 0;
}
