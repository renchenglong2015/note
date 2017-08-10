#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void)
{
    pid_t pid, wpid;
    int i;
    for(i = 0; i < 5; i++){
        pid = fork();
        if(pid == 0){
            break;
        }else if(pid < 0){
            perror("fork");
            exit(1);
        }
    }
    if(i == 5){
        printf("我是父进程，pid = %d\n", getpid());
        int status;
        //当子进程还在进行中，且参数为WNOHANG时，返回0
        while((wpid = waitpid(-1, &status, WNOHANG)) >= 0){
            if(WIFEXITED(status)){
                printf("Child exited with code %d\n", WEXITSTATUS(status));
            }else if(WIFSIGNALED(status)){
                printf("Child terminated abnormally, signal %d\n", WTERMSIG(status));
            }
            sleep(1);   
        
        }
       
    }else if(i == 0){
        sleep(i);
        printf("I'm process child, pid = %d\n", getpid());
        exit(10);
    }else if(i == 1){
        sleep(i);
        printf("I'm process child, pid = %d\n", getpid());
        execl("./abnor", "abnor", NULL);    
    }else{
        sleep(i);
        printf("I'm process child, pid = %d\n", getpid());
        return i;
    }
    return 0;


}
