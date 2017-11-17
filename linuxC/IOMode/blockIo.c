#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define BUFSIZE 4096
/**
 *  当用户进程调用read这个系统调用，kernal开始了io的第一个阶段，准备数据。对于网络IOL来说，
 *  很多时候在一开始还没有到达时，这个时候内核就要等待足够的数据到来。而在用户进程这边，整个进程会被阻塞。
 *  当kernal一直等到数据准备好了，它就会将数据从kernal中拷贝到用户内存，然后kernal返回结果，用户进程才
 *  解除block的状态，重新运行起来。
 */
int main(void)
{
    int n;
    char buf[BUFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0)
    {
        if(write(STDOUT_FILENO, buf, n) != n)
        {
            perror("write error:");
        }    
    }
    if(n < 0)
    {
        perror("read error");
    }
}
