#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//exec函数族
//execlp 从PATH环境变量中所指的目录找中查找符合参数file的文件名
//然后找到后便执行改文件，然后将第二个以后的参数，当作arg[0],arg[1],最后一个参数以NULL结尾
int main(int argc, char *argv[]){
    pid_t pid;
    pid = fork();
    if(pid == -1){
        perror("fork");
        exit(1);
    }else if(pid > 0){
        sleep(1);
        printf("-----------");
    }else{
        //execlp("ls", "ls", "-l" ,"-a",NULL);
        execl("./a.out", "a.out" , NULL);
    }
    return 0;


}
