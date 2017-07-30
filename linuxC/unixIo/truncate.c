#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
//拓展文件 形成空洞文件
int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("a.out fileName\n");
        exit(1);
    }
    long int len = strtol(argv[2], NULL, 10);
    int ret = truncate(argv[1], len);
    if(ret == -1)
    {
        perror("truncate");
        exit(1);
    }
    return 0;
}
