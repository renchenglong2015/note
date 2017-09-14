#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
//父子进程之间共享：1打开的文件。2.mmap建立的内存映射区（但必须要使用MAP_SHARED）
int var = 100;

int main(){
    int *p;
    pid_t pid;
    int fd;
    fd = open("temp", O_RDWR|O_CREAT|O_TRUNC, 0664);
    if(fd < 0){
        perror("open error");
        exit(1);
    }
    unlink("temp");  //删除临时文件目录项，使之具备被释放条件
    ftruncate(fd, 4);

    //p = (int *)mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
    p = (int *)mmap(NULL , 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(p == MAP_FAILED){
        perror("mmap error");
        exit(1);
    }
    close(fd); //映射区建立完毕，即可关闭文件。
    pid = fork();
    if(pid == 0){
        *p = 1024;
        var = 1000;
        printf("child *p = %d, var = %d\n", *p, var);
    }else{
        sleep(1);
        printf("parent *p = %d, var = %d\n", *p, var);
        wait(NULL);
        int ret = munmap(p, 4);
        if(ret == -1){
            perror("munmap error");
        }
    }
    return 0;
}
