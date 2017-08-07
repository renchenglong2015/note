#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(void){
    int fd;
    fd = open("ps.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fd < 0){
        perror("open");
        exit(1);
    }
    dup2(fd, STDOUT_FILENO);
    execlp("ps", "ps", "aux", NULL);
    close(fd);//一旦成功，就不会回来了。依赖于隐式回收。
    return 0;
}

