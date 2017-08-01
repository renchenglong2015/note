#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
//修改已经打开文件的属性
//int fcntl(int fd, int cmd);
//int fcntl(int fd, int cmd, long arg);
//int fcntl(int fd, int cmd, struct flock* lock);
// 
int main(void)
{
    int fd;
    int flag;
    char* s  = "1111111111111111";
    char* s1 = "2222222222222222";

    //只写的方式打开
    fd = open("renchenglong.txt", O_WRONLY);
    if(fd == -1){
        perror("open");
        exit(1);
    }
    if(write(fd, s1, strlen(s1)) == -1){
        perror("write");
        exit(1);
    }

    flag = fcntl(fd, F_GETFL, 0);
    if(flag == -1)
    {
        perror("fcntl");
        exit(1);
    }
    //将文件状态转换为追加写
    flag |= O_APPEND;
    if(fcntl(fd, F_SETFL, flag) == -1){
        perror("fcntl");
        exit(1);
    }
    
    if(write(fd, s, strlen(s)) == -1){
        perror("write");
        exit(1);
    }

    close(fd);
    return 0;
    

}

