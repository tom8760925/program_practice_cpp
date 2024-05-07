#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in sinadd, cinadd;
    socklen_t addlen;
    char indata[1024] = {0}, outdata[1024] = {0};
    int sock, csock, crecv;
    int port = 8000;
    int on = 1;
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
    addlen = sizeof(cinadd);

    while (true)
    {
        csock = accept(sock, (struct sockaddr *)&cinadd, &addlen);                     // 等待請求
        printf("accept: %s:%d\n", inet_ntoa(cinadd.sin_addr), ntohs(cinadd.sin_port)); // 顯示請求的ip和port，ip轉換成十進位，port轉換成電腦序。
        while (true)
        {
            memset(indata, '\0', 1024);                     // 清空資料
            memset(outdata, '\0', 1024);                    // 清空資料
            crecv = recv(csock, indata, sizeof(indata), 0); // 接收資料
            if (crecv == -1)
            {
                perror("recv error");
                close(crecv);
                break;
            }
            else if (crecv == 0)
            {
                printf("close\n");
                close(crecv);
                break;
            }
            printf("recv:%s\n", indata);
            strcpy(outdata, indata);                  // 複製字串
            send(csock, outdata, strlen(outdata), 0); // 傳送資料
        }
    }
    close(sock);
    return 0;
}