#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "qq_ipc.h"
#include "mylink.h"

#define SERVER_PORT "SEV_FIFO"

mylink head = NULL;

void sys_err(char *str)
{
    perror(str);
    exit(-1);
}
//有新用户登录时，将用户插入到链表
int login_qq(struct QQ_DATA_INFO *buf, mylink *head)
{
    int fd;
    //获取登录者名字，以只写的方式打开以其名字命名的私有
    fd = open(buf->srcname, O_WRONLY);
    mylink node = make_node(buf->srcname, fd);
    return 0;
}
//客户端发送聊天，服务器负责转发聊天内容
void transfer_qq(struct QQ_DATA_INFO *buf, mylink *head)
{
    mylink p = mylink_search(head, buf->destname);
    //目标用户不在，封装3号数据包
    if(p == NULL)
    {
        struct QQ_DATA_INFO lineout = {3};
        strcpy(lineout.destname, buf->destname);
        //获取客户端节点
        mylink q = mylink_search(head, buf->srcname);
        //通过私有管道写给来源客户端
        write(q->fifo_fd, &lineout, sizeof(lineout));
    }
    write(p->fifo_fd, buf, sizeof(*buf));
}

//退出登录
int logout_qq(struct QQ_DATA_INFO *buf, mylink *head)
{
    //从链表中找到该客户节点
    mylink p = mylink_search(head, buf->srcname);
    //关闭其对应的私有管道描述符
    close(p->fifo_fd);
    mylink_delete(head, p);
    free_node(p);
}
void err_qq(struct QQ_DATA_INFO *buf)
{
    fprintf(stderr,"bad client %s connect \n", buf->srcname);
}
int main(void)
{
    //公共管道文件描述符（读端）
    int server_fd;
    struct QQ_DATA_INFO dbuf;
    if(access(SERVER_PORT, F_OK) != 0)
    {
        mkfifo(SERVER_PORT, 0664);
    }
    if((server_fd = open(SERVER_PORT, O_RDONLY)) < 0)
        sys_err("open");
    mylink_init(&head);
    while(1){
        read(server_fd, &dbuf, sizeof(dbuf));
        printf("%d", dbuf.protocal);
        switch (dbuf.protocal){
            case 1 : login_qq(&dbuf, &head);break;
            case 2 : transfer_qq(&dbuf, &head);break;
            case 4 : logout_qq(&dbuf, &head);break;
            default: err_qq(&dbuf);         
        }
    }
    close(server_fd);
}



