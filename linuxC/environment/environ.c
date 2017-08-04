#include <stdio.h>
#include <unistd.h>
//环境变量是指在操作系统中用来指定操作系统运行环境的一些参数。
//引入环境变量表
extern char** environ;

int main()
{
    int i;
    for(i = 0; environ[i] != NULL; i++){
        printf("%s\n", environ[i]);
    }

    return 0;
    
}


