#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char* argv[])
{
    if(argc < 2)
    {
        printf("a.out dir\n");
        exit(1);
    }
    //修改当前进程的路径
    int ret = chdir(argv[1]);

    if(ret == -1)
    {
        perror("chdir");
        exit(1);
    }

    int fd = open("renchenglong.txt", O_CREAT | O_RDWR, 0777);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    close(fd);

    char buf[64];
    //获取当前进程工作目录
    getcwd(buf, sizeof(buf));

    printf("当前工作目录是: %s\n", buf);

    return 0;

    
}
