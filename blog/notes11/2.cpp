#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in sin;
    char indata[1024] = {0};
    int sock; // 設定通訊協定
    int port = 8000;
    sock = socket(AF_INET, SOCK_STREAM, 0); // 設定通訊協定
    if (sock == -1)
    {
        perror("sock error");
        exit(1);
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
    while (true)
    {
        if (recv(sock, indata, sizeof(indata), 0) == -1) // 接收資料
        {
            perror("recv error");
            break;
        }
        printf("recv: %s\n", indata);
        break;
    }
    close(sock);
    return 0;
}