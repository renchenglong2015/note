#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *my_getenv(const char *name)
{
    char *p =NULL;
    int i =0;
    int len;
    while(environ[i] != NULL){
        p = strstr(environ[i],"=");
        len = p - environ[i];
        if(strncmp(name, environ[i], len) == 0){
            return p+1;
        }        
        i++;
    }
    
}


int main(int argc, char *argv[])
{
    char *p = NULL;
    p = my_getenv(argv[1]);
    printf("%s\n",p);
    
    //setenv
    char *val;
    const char *name = "renchenglong";
    
    val = getenv(name);
    printf("1, %s = %s\n", name, val);
    setenv(name, "zhangyandi", 1);
    val = getenv(name);
    printf("2, %s = %s\n", name ,val);
    
    int ret = unsetenv("renchenglong");
    printf("ret = %d\n", ret);

    val = getenv(name);
    printf("3, %s = %s\n", name, val);


    return 0;

}

