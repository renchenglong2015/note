#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
 /**
  *MAP_
  *
  * 
  */
 int main(void)
{
    int *p;
    pid_t pid;

    p = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED | MAP_ANON, -1,  0);
    *p = 20;
    if(p == MAP_FAILED){
        perror("mmap error");
        exit(1);
    }
    pid = fork();
    if(pid == 0){
        *p = 1000;
        printf("子进程 *p = %d\n", *p);
    }else{
        printf("父进程 *p = %d\n", *p);
        sleep(1);
        printf("1s后父进程 *p = %d\n", *p);
    }
     munmap(p, 4);
    return 0;


}
