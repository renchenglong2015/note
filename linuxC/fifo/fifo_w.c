#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void sys_err(char *str)
{
    perror(str);
    exit(-1);
}
int main(int argc, char *argv[]){
    int fd, i;
    char buf[1024];
    if(argc < 2){
        printf("./a.out fifoname");
        return -1;
    }
    fd = open(argv[1], O_WRONLY);
    if(fd == -1)
        sys_err("open");
    i = 0;
    while(1){
        sprintf(buf, "hello world %d\n", i++);
        write(fd, buf, strlen(buf));
        sleep(1);
    }
    close(fd);
    return 0;

}
