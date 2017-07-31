#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//unlink 硬链接数减1，当硬链接数为0时，内核会释放数据块和inode,
//当硬链接数为0时，但有进程打开此文件，并持有文件描述符，则等该进程关闭文件时，内核才会去删除文件
//利用此特性，创建临时文件，先创建一个文件，然后马上unlink此文件
int main(void)
{
    int fd = open("tempfile", O_CREAT | O_RDWR, 0755);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    int ret = unlink("tempfile");
    if(ret == -1)
    {
        perror("unlink");
        exit(1);
    }
    char buf[1024];
    write(fd, "renchenglong", 12);
    lseek(fd, 0, SEEK_SET);
    int len = read(fd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, len);
    close(fd);

    return 0;

}
