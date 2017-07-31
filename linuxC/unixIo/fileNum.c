#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int getfileNums(char* rootDir)
{
    //打开目录
    DIR* dir = opendir(rootDir);
    if(dir == NULL){
        perror("opendir");
        exit(1);
    }
    int total = 0;
    char path[1024] = {0};
    //返回一条记录项
    //struct dirent
    //{
    //    ino_t d_ino;               // 此目录进入点的inode
    //    ff_t d_off;                // 目录文件开头至此目录进入点的位移
    //    signed short int d_reclen; // d_name 的长度, 不包含NULL 字符
    //    unsigned char d_type;      // d_name 所指的文件类型 
    //    har d_name[256];         // 文件名
    //}；
    struct dirent* ptr = NULL;
    while((ptr = readdir(dir)) != NULL){
        //跳过.和 ..
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0){
            continue;
        }
        // DT_UNKNOWN，未知的类型
        // DT_REG，普通文件
        // DT_DIR，普通目录
        // DT_FIFO，命名管道或FIFO
        // DT_SOCK，本地套接口
        // DT_CHR，字符设备文件
        // DT_BLK，块设备文件
        if(ptr->d_type == DT_REG){
            total++;            
        }
        if(ptr->d_type == DT_DIR){
            sprintf(path, "%s/%s", rootDir, ptr->d_name);
            total += getfileNums(path);
        }
    }
    closedir(dir);
    return total;

}


int main(int argc, char* argv[])
{
    //读取命令行输入的目录
    int fileNum = getfileNums(argv[1]);

    //打印
    printf("%s 有%d个文件\n", argv[1], fileNum);
    return 0;
}
