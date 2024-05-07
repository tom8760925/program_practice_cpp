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
            char *argv[] = {NULL};
            char *envp[] = {"A=1", "B=2", NULL};
            r = execve("./4", argv, envp);
            if (r == -1)
                perror("execvp error");
        }
        else if (pid1 > 0) // 父
        {
            char *argv[] = {"ls", "-l", NULL};
            char *envp[] = {NULL};
            r = execve("/bin/ls", argv, envp);
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
            char *envp[] = {NULL};
            r = execle("/bin/ls", "ls", "-l", NULL, envp);
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