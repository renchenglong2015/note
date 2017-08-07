#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int foo = 100;
//set follow-fork-mode child 命令在fork后跟踪子进程
//ser follow-fork-mode parent 父进程 默认
int main(void){

    pid_t pid;
    pid = fork();

    if(pid == -1){
        perror("fork");
        exit(1);
    }else if(pid > 0){
        sleep(1);
        printf("%d\n",&foo);
        foo = 10;
        printf("父进程foo变量重新赋值后地址为%d\n", &foo);
        printf("我是父进程 = %d, parentID = %d, foo = %d\n", getpid(), getppid(), foo);
    }else if(pid == 0){
        printf("%d\n", &foo);
        foo = 50;
        printf("子进程foo变量重新赋值后地址为%d\n", &foo);
        printf("我是子进程 = %d, parentId = %d, foo = %d\n", getpid(), getppid(), foo);        
       
    }
    printf("foo = %d\n" , foo);
    return 0;

}
