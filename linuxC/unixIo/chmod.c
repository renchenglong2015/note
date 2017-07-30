#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
// 基于chmod函数，实现linux下chmod命令
// 编译后执行 ./a.out aaa 777
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("a.out filename\n");
        exit(1);
    }
    long base = strtol(argv[2], NULL, 8);
    int ret = chmod(argv[1], base);
    if(ret == -1)
    {
        perror("chmod");
        exit(1);
    }
    return 0;
}

