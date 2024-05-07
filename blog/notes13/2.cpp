#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <typeinfo>
int main()
{
    struct sockaddr_in sin;
    char indata[1024] = {0}, outdata[1024] = {0};
    std::string inputfgets;
    int sock, crecv; // 設定通訊協定
    int port = 8000;
    bool cin_while = true;
    sock = socket(AF_INET, SOCK_STREAM, 0); // 設定通訊協定
    if (sock == -1)
    {
        perror("socket error");
        exit(1);
    }
    else
    {
        printf("socket OK\n");
    }
    sin.sin_family = AF_INET;                     // 設定使用IP
    sin.sin_addr.s_addr = inet_addr("127.0.0.1"); // 設定IP，轉換成符合sin_addr的u_long
    // sin.sin_addr.s_addr = INADDR_ANY;//如果不指定ip，可以這樣用
    sin.sin_port = htons(port);                                    // 設定port號，轉換成網路序
    if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1) // 綁定ip和port。
    {
        perror("connect error");
        exit(1);
    }
    else
    {
        printf("connect OK\n");
    }
    while (cin_while)
    {
        printf("輸入1傳送資料\n");
        printf("輸入2離開\n");
        printf("P:");
        std::cin >> inputfgets;
        try
        {
            switch (std::stoi(inputfgets))
            {
            case 1:
                while (true)
                {
                    memset(indata, '\0', 1024);  // 等待請求
                    memset(outdata, '\0', 1024); // 等待請求
                    printf("輸入exit結束資料輸入\n");
                    printf("p:");
                    std::cin >> outdata; // 輸入資料
                    if (strcmp(outdata, "exit") == 0)
                    {
                        close(crecv);
                        break;
                    }
                    send(sock, outdata, strlen(outdata), 0);       // 傳送資料
                    crecv = recv(sock, indata, sizeof(indata), 0); // 接收資料
                    if (crecv == -1)
                    {
                        perror("recv error");
                        close(crecv);
                        exit(1);
                    }
                    else if (crecv == 0)
                    {
                        printf("close\n");
                        close(crecv);
                        exit(1);
                    }
                    printf("recv: %s\n", indata);
                }
                std::cout << "結束資料輸入" << std::endl;
                break;
            case 2:
                cin_while = false;
                printf("exit\n");
                break;
            default:
                printf("輸入錯誤(請輸入半形的1-2)\n");
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            printf("輸入錯誤(請輸入半形的1-2)\n");
        }
    }
    close(sock);
    return 0;
}