#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
//用stat函数实现 linux ls -l 命令 
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("./a.out filename\n");
        exit(1);
    }
    struct stat st;
    int ret = stat(argv[1], &st);
    if(ret == -1){
        perror("stat");
    }
    //存储文件类型 访问权限
    char params[11] = {0};
    //判断文件类型
    //"l":链接文件 "d"代表目录 "-"代表普通文件 "b"代表块设备文件 
    //"c"代表字符设备文件 "s" sockects套接字 "p" 管道
    switch(st.st_mode & S_IFMT)
    {
        case S_IFIFO:
            params[0] = 'p';
            break;
        case S_IFCHR:
            params[0] = 'c';
            break;
        case S_IFDIR:
            params[0] = 'd';
            break;
        case S_IFBLK:
            params[0] = 'b';
            break;
        case S_IFREG:
            params[0] = '-';
            break;
        case S_IFLNK:
            params[0] = 'l';
            break;
        case S_IFSOCK:
            params[0] = 's';
            break;
        default:
            params[0] = '?';
            break;
    }
    //判断文件的访问权限
    //文件所有者
    params[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
    params[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
    params[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
    //文件所属组
    params[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
    params[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
    params[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
    //其他人
    params[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
    params[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
    params[9] = (st.st_mode & S_IXOTH) ? 'x' : '-';
    //硬链接计数
    int linkNum = st.st_nlink;
    //文件所有者
    char* fileUser = getpwuid(st.st_uid)->pw_name;
    //文件所属组
    char* fileGrp = getgrgid(st.st_gid)->gr_name;
    //文件大小
    int fileSize = (int)st.st_size;
    //修改时间
    char* time = ctime(&st.st_mtime);
    char mtime[512] = {0};
    strncpy(mtime, time, strlen(time)-1);

    char buf[1024];
    sprintf(buf, "%s   %d   %s   %s   %d   %s   %s", params, linkNum, fileUser, fileGrp, fileSize, mtime, argv[1]);

    printf("%s\n", buf);
    return 0;   
}
