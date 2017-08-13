#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
/*程序会不时先打印$提示符，后打印程序运行的结果。
 * 这是因为父进程在运行ls命令时，将输出结果通过管道传递给子进程
 * 去执行wc命令。这时父进程先于子进程打印EC结果之前被SHELL的wait回收，
 * shell就会先于子进程打印wc结果之前打印$提示符
 * 解决办法：让子进程执行ls，父进程执行wc。或者在兄弟进程间完成
 *
 *
*/
 int main(void){
    pid_t pid;
    int fd[2];
    
    pipe(fd);
    pid = fork();

    if(pid == 0){
        close(fd[1]);//子进程从管道中读取数据，关闭写端       
        dup2(fd[0], STDIN_FILENO);//让wc从管道中读取数据
        execlp("wc", "wc", "-l", NULL);
    }else{
        close(fd[0]);//父进程向管道中写数据，关闭读端
        dup2(fd[1], STDOUT_FILENO);
        execlp("ls", "ls", NULL);
    }
    return 0;
}
