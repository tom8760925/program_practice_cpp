#include <unistd.h>
#include <iostream>

int main()
{
    pid_t pid = fork(); // 建立新程序
    if (pid == 0)       // 子
    {
        sleep(5);
        printf("p:B(%d)\n", getpid());
    }
    else if (pid > 0) // 父
    {
        printf("p:A(%d)\n", getpid());
        wait(nullptr);
        printf("p:---\n");
    }
    else
    {
        perror("pid error");
        exit(1);
    }
    return 0;
}