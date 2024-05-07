#include <unistd.h>
#include <iostream>
int main()
{
    int x, r;
    pid_t pid = fork(); // 建立新程序
    if (pid == 0)       // 子
    {
        pid_t pid1 = fork(); // 建立新程序
        if (pid1 == 0)       // 子
        {
        }
        else if (pid1 > 0) // 父
        {
            char *argv[] = {"ls", "-l", NULL};
            r = execvp("ls", argv);
            if (r == -1)
                perror("execvp error");
            wait(&x);
        }
        else
        {
            perror("pid error");
            exit(1);
        }
    }
    else if (pid > 0) // 父
    {
        pid_t pid1 = fork(); // 建立新程序
        if (pid1 == 0)       // 子
        {
        }
        else if (pid1 > 0) // 父
        {
            r = execlp("ls", "ls", "-l", NULL);
            if (r == -1)
                perror("execl error");
            wait(&x);
        }
        else
        {
            perror("pid error");
            exit(1);
        }
        wait(&x);
    }
    else
    {
        perror("pid error");
        exit(1);
    }
    return 0;
}