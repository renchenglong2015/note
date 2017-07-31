#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd = open("renchenglong.txt", O_CREAT | O_RDWR);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    
    printf("file open fd = %d\n", fd);
    //找到进程文件描述符中第一个可用的文件描述符，将参数指定的文件复制到该文件描述符后，返回这个文件描述符
    int ret = dup(fd);    
    if(ret == -1)
    {
        perror("dup");
        exit(1);
    }
    printf("dup fd = %d\n", ret);
    char* buf = "琼州学院？？？？？？\n";
    char* buf1 = "热带海洋大学！！！！\n";

    write(fd, buf, strlen(buf));
    write(ret, buf1, strlen(buf1));
    close(fd);
    return 0;
}
