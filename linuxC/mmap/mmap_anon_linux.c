#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
/**
 *通过使用发现映射区来完成文件操作十分方便，父子进程间通信也容易。但缺陷是，每次创建映射区一定要
 *依赖一个文件，通常需要open创建一个文件，然后再进行unlink，close文件。
 *可以直接使用匿名映射，使用MAP_ANONYMOUS(或者MAP_ANON),这两个宏是linux特有的宏，类unix系统不可以。
 */ 

 int main(void)
{
    int *p;
    pid_t pid;
    p = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
    if(p == MAP_FAILED){
        perror("mmap error");
    }
    pid = fork();
    if(pid == 0){
        *p = 2000;
        printf("child, *p = %d\n", *p);
    }else{
        sleep(1);
        printf("parent, *p = %d\n", *p);
    }
    munmap(p, 4);
    return 0;
}
