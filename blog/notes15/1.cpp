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
            char *argv[] = {NULL}; // 參數
            r = execv("./2", argv);
            if (r == -1)
                perror("execl error");
        }
        else if (pid1 > 0) // 父
        {
            char *argv[] = {"ls", "-l", NULL}; // 參數
            r = execv("/bin/ls", argv);
            if (r == -1)
                perror("execl error");
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

            r = execl("./2", NULL);
            if (r == -1)
                perror("execl error");
        }
        else if (pid1 > 0) // 父
        {
            r = execl("/bin/ls", "ls", "-l", NULL);
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