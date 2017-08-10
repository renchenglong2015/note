#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int n = 5, i;
    pid_t p, q, wpid;
    if(argc > 2){
        n = atoi(argv[1]);
    }
    
    for(i=0; i<n; i++){
        p = fork();
        if(p == 0){
            break;
        }else if(i == 3){//获取第四个子进程的进程id号
            q = p;
        }
    }
    if(n == i){
        sleep(n);
        printf("我是父进程，进程id是%d,组id是%d\n", getpid(), getgid());
        //waitpid(q, NULL, 0);单独回收某个子进程
        do{
            //当参数为WNOHANG时，返回值为0时，代表子进程正在进行中
            wpid = waitpid(-1, NULL, WNOHANG);
            if(wpid > 0){
                n--;
            }
        } while(n > 0);
        printf("回收完毕\n");
        while(1);
    }else{
        sleep(i);
        printf("我是第%d个孩子，pid = %d, gpid = %d\n", i+1, getpid(), getgid());
    }
    return 0;

}
