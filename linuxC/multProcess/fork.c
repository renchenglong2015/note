#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//父子进程共享 1.文件描述符（打开文件的结构体） 2.mmap建立的映射区（进程间通信共享）

int main(int argc, char *argv[])
{
    //默认创建5个进程
    int n = 5, i;
    
    if(argc == 2){
        n = atoi(argv[1]);
    }
    for(i = 0; i < n; i++){
        if(fork() == 0){
            break;
        }
    }
    if(n == i){
        sleep(n);
        printf("i am parent, pid =%d\n", getpid());
    }else{
        sleep(i);
        printf("i am %dth child, pid = %d\n", i+1, getpid());
    }
    return 0;
}

