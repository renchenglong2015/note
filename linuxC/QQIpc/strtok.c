#include<string.h>
#include<stdio.h>
/**
 * strtok()用来将字符串分隔成一个片段，参数s指向欲分隔的字符串，
 * 参数delim分隔符字符串。当strtok()在参数s的字符串中发现参数delim中包含的分隔字符串时，
 * 将会该字符改成'/0'，第一次调用时，strtok()必需给予参数s字符串，往后的调用将参数设置为NULL，
 * 每次调用成功，则返回指向被分隔出片段的指针。
 */
int main(void)
{
    char input[16]="abc,d";
    char*p;
    /*strtok places a NULL terminator
     *     infront of the token,if found*/
    p=strtok(input,",");
    if(p)
        printf("%s\n",p);//abc
    /*Asecond call to strtok using a NULL
     *         as the first parameter returns a pointer
     *                 to the character following the token*/
    p=strtok(NULL,",");
    if(p)
        printf("%s\n",p);//d
    return 0;
}
