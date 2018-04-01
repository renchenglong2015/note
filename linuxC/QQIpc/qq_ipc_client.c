#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "qq_ipc.h"
#include "mylink.h"

#define SERVER_PROT "SEV_FIFO"

void sys_err(char *str)
{
    perror(str);
    exit(1);
}
int main(int argc, char *argv[])
{
    int server_fd, client_fd, flag, len;
    struct QQ_DATA_INFO dbuf;
    char cmdbuf[256];

    if(argc < 2){
        printf("./client name\n");
        exit(1);
    }
    if((server_fd = open(SERVER_PROT, O_WRONLY)) < 0)
    {
        sys_err("open");
    }
    mkfifo(argv[1], 0777);
    struct QQ_DATA_INFO cbuf, tmpbuf, talkbuf;
    //1号登陆包
    cbuf.protocal = 1;
    strcpy(cbuf.srcname, argv[1]);
    //非阻塞，且只读
    client_fd = open(argv[1], O_RDONLY | O_NONBLOCK);
    
    //设置标准输入区缓冲区读写为非阻塞
    flag = fcntl(STDIN_FILENO, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(STDIN_FILENO, F_SETFL, flag);
    //向公共管道中写入"登陆包",表示客户端登陆
    write(server_fd, &cbuf, sizeof(cbuf));

    while(1)
    {
        //读私有管道
        len = read(client_fd, &tmpbuf, sizeof(tmpbuf));
       if(len > 0){
           if(tmpbuf.protocal == 3){
               printf("%s 不在线\n", tmpbuf.destname);            
           }else if(tmpbuf.protocal == 2){
               printf("%s : %s\n", tmpbuf.srcname,tmpbuf.data);
           }
       }else if(len < 0){
           if(errno != EAGAIN)
               sys_err("client read");
       }                             
       //读取用户输入
       len = read(STDIN_FILENO, cmdbuf, sizeof(cmdbuf));
       if(len > 0)
       {
           char *dname, *databuf;
           memset(&talkbuf, 0, sizeof(talkbuf));
           //填充字符串结束标识
           cmdbuf[len] = '\0';
           dname = strtok(cmdbuf, "#\n");
           if(strcmp("exit", dname)== 0){
               talkbuf.protocal = 4;
               strcpy(talkbuf.srcname, argv[1]);
               //将退出登录包发送给服务器
               write(server_fd, &talkbuf, sizeof(talkbuf));
               break;
           }else{
               talkbuf.protocal = 2;
               //填充聊天目标的用户名
               strcpy(talkbuf.destname, dname);
              //填充发送聊天内容的用户名
               strcpy(talkbuf.srcname, argv[1]);
               databuf = strtok( NULL, "\0");
               strcpy(talkbuf.data, databuf); 
           }
           //将聊天包写入公共管道
           write(server_fd, &talkbuf, sizeof(talkbuf));
       }
    }
    unlink(argv[1]);
    close(client_fd);
    close(server_fd);
    return 0;
}
