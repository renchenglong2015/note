#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    pid_t pid;
    int fd[2], i;
    pipe(fd);

    for(i = 0; i < 2; i++){
        pid = fork();
        if(pid == 0){
            break;
        }
    }
    //父进程
    if(i == 2){
        close(fd[0]);
        close(fd[1]);
        for(i = 0; i < 2; i++)
            wait(NULL);
    }else if(i == 0){
        //关闭读端， 写
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execlp("ls", "ls", NULL);
    }else if(i == 1){
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc","-l", NULL);
    }
    return 0;
}
