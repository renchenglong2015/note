#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd = open("renchenglong.txt", O_RDWR | O_CREAT);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }

    int fd1 = open("renchenglong1.txt", O_RDWR | O_CREAT);
    if(fd1 == -1)
    {
        perror("open");
        exit(1);
    }
    printf("fd = %d\n", fd);
    printf("fd1 = %d\n", fd1);
    //目标文件描述符（第二个参数）变成资源描述符(dup2函数的第一个参数)的复制品，
    //执行成功后返回被复制的文件描述符
    int ret = dup2(fd1, fd);
    
    if(ret == -1)
    {
        perror("dup2");
        exit(1);
    }
    printf("当前 fd = %d\n", ret);
    char* buf = "任成龙 ！！！！！！！！！！";
    write(fd, buf, strlen(buf));
    write(fd1, "hello", 5);
    close(fd);
    close(fd1);


}
