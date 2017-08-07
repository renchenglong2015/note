#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void){
    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == -1){
        perror("fork");
        exit(1);
    }else if(pid == 0){
#if 0
        printf("我是子进程，pid = %d\n", getpid());
        execl("./abnor", "abnor", NULL);
#endif
        sleep(1);
        exit(10);
    }else{
        wpid = wait(&status);//传出参数
        if(WIFEXITED(status)){//正常退出
            printf("我是父进程，我的子进程%did正常退出\n", wpid);
            printf("返回值是%d\n", WEXITSTATUS(status));
        }else if(WIFSIGNALED(status)){
            printf("子进程异常退出, killed by signal %d\n", WTERMSIG(status));//获取信号编号
        
        }
    
    }
    return 0;

}
