#include <unistd.h>
#include <iostream>

int main()
{
    int x = 1;
    pid_t pid = fork();//建立新程序
    if (pid == 0)//子
    {
        x--;
        printf("p:%d\n", x);
    }
    else if (pid > 0)//父
    {
        printf("p:%d\n", x);
    }
    else
    {
        perror("pid error");
        exit(1);
    }
    return 0;
}