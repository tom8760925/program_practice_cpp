#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <ctime>

int main()
{
    struct sockaddr_in sinadd, cinadd;
    struct sockaddr_in cliall[1024];
    socklen_t addlen;
    char indata[1024] = {0}, outdata[1024] = {0};
    int sock, csock, crecv, ssel;
    int port = 8000;
    int on = 1;
    int maxfd = 0, maxi = 0;
    int client[1024];
    fd_set fdread;  // 有幾個連線
    fd_set fdread2; // 有幾個連線
    fd_set fdwrite; // 有幾個準備傳送資料
    struct timeval tv;
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
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int)) == -1) // 設定為TCP，對bind設定釋放的通訊端立即可以使用
    {
        perror("setsockopt error");
        exit(1);
    }
    else
    {
        printf("setsockopt OK\n");
    }
    sinadd.sin_family = AF_INET;                     // 設定使用IP
    sinadd.sin_addr.s_addr = inet_addr("127.0.0.1"); // 設定IP，轉換成符合sin_addr的u_long
    sinadd.sin_port = htons(port);                   // 設定port號，轉換成網路序
    // sin.sin_addr.s_addr = INADDR_ANY;//如果不指定ip，可以這樣用
    if (bind(sock, (struct sockaddr *)&sinadd, sizeof(sinadd)) == -1) // 綁定ip和port，如果使用using namespace std;，這裡要加::不然會發生錯誤，因為會讓編譯器以為要使用std::bind造成錯誤。
    {
        perror("bind error");
        exit(1);
    }
    else
    {
        printf("bind OK\n");
    }
    printf("server start at: %s:%d\n", inet_ntoa(sinadd.sin_addr), port);
    if (listen(sock, 5) == -1) // 監聽接口，接口數量最多5個
    {
        perror("listen error");
        exit(1);
    }
    else
    {
        printf("listen OK\n");
    }
    printf("wait...\n");
    FD_ZERO(&fdread);       // 清空
    FD_ZERO(&fdwrite);      // 清空
    FD_SET(sock, &fdread);  // 設定
    FD_SET(sock, &fdwrite); // 設定
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    maxfd = sock;
    memset(client, -1, sizeof(int) * 1024);
    addlen = sizeof(cinadd);
    while (true)
    {
        FD_ZERO(&fdread2); // 清空
        fdread2 = fdread;
        ssel = select(maxfd + 1, &fdread2, &fdwrite, (fd_set *)0, /*(struct timeval *)*/ &tv); // 監控描述符組，只要有事件就對變成1，例如socket的描述符是第3位置，有事件就會成1，，回傳值等於有幾個描述符在監控
        if (ssel == -1)
        {
            perror("recv error");
            close(ssel);
            break;
        }
        else if (ssel == 0)
        {
            continue;
        }
        if (FD_ISSET(sock, &fdread2)) // 判斷描述黨是否為1
        {
            int i = 0;
            csock = accept(sock, (struct sockaddr *)&cinadd, &addlen);                     // 等待請求
            printf("accept: %s:%d\n", inet_ntoa(cinadd.sin_addr), ntohs(cinadd.sin_port)); // 顯示請求的ip和port，ip轉換成十進位，port轉換成電腦序。
            FD_SET(csock, &fdread);                                                        // 設定
            for (; i < 1024; i++)                                                          // 將描述符和sockaddr_in記錄
            {
                if (client[i] == -1)
                {
                    client[i] = csock;
                    cliall[i] = cinadd;
                    break;
                }
            }
            if (csock > maxfd) // 更新最大值
                maxfd = csock;
            if (i > maxi) // 更新最大值
                maxi = i;

            if (ssel == 1) // 只有連線請求
            {
                continue;
            }
        }
        for (int i = 0; i <= maxi; i++)
        {
            if (client[i] == -1) // 沒有描述符就跳過
                continue;
            memset(indata, '\0', 1024);        // 清空資料
            memset(outdata, '\0', 1024);       // 清空資料
            if (FD_ISSET(client[i], &fdread2)) // 判斷是否接收資料請求
            {
                crecv = recv(client[i], indata, sizeof(indata), 0); // 接收資料
                if (crecv == -1)
                {
                    perror("recv error");
                    close(crecv);
                    continue;
                }
                else if (crecv == 0)
                {
                    printf("close\n");
                    FD_CLR(client[i], &fdread);
                    FD_CLR(client[i], &fdwrite);
                    client[i] = -1;
                    close(client[i]);
                    continue;
                }
                else
                {
                    time_t now = time(0);
                    printf("%d:%d:%d ", localtime(&now)->tm_hour, localtime(&now)->tm_min, localtime(&now)->tm_sec); // 輸出時間
                    printf("%s:%d inout:%s\n", inet_ntoa(cliall[i].sin_addr), ntohs(cliall[i].sin_port), indata);
                    FD_SET(csock, &fdwrite);
                }
            }
            if (FD_ISSET(client[i], &fdwrite)) // 判斷是否輸出資料請求
            {
                strcpy(outdata, indata);
                if (send(client[i], outdata, strlen(outdata), 0) == -1) // 傳送資料
                {
                    perror("send error");
                    continue;
                }
                FD_CLR(client[i], &fdwrite);
            }
        }
    }
    close(sock);
    return 0;
}