#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main()
{
    struct addrinfo hints;
    struct addrinfo *result;
    struct addrinfo *res;
    int i;

    // 設定hints
    memset(&hints, 0, sizeof(struct addrinfo));
    // 設定flags
    hints.ai_flags = AI_PASSIVE; // 使用bind()
    // 設定ipv4或ipv6
    hints.ai_family = AF_UNSPEC; // 使用ipv4或ipv6
    // 設定返回的sock類型
    hints.ai_socktype = SOCK_DGRAM; // 使用UDP 或 SOCK_STREAM 使用TCP
    // 設定協定
    hints.ai_protocol = 0; // 不設定就設為0
    // 設定主機名稱
    hints.ai_canonname = NULL;
    // 設定主機位子
    hints.ai_addr = NULL;
    // 設定位子長度
    hints.ai_addrlen = NULL;
    // 下一個結構
    hints.ai_next = NULL;

    // getaddrinfo(網址, port, 設定值, 傳送值);
    i = getaddrinfo("www.miaoli.gov.tw", NULL, &hints, &result);
    if (i != 0)
    {
        return 1;
    }

    for (res = result; res != NULL; res = res->ai_next)
    {
        // 網址
        char hostname[NI_MAXHOST] = "";
        char service[NI_MAXSERV] = "";

        // getnameinfo(位子, 位子長度, 名稱, 名稱長度, ANSI 字串, ANSI 字串長度, 設定flags);
        i = getnameinfo(res->ai_addr, res->ai_addrlen, hostname, NI_MAXHOST, service, NI_MAXSERV, 0);
        if (i != 0)
        {
            continue;
        }
        printf("hostname: %s\n", hostname);
        printf("service: %s\n", service);
    }

    // 釋放addrinfo
    freeaddrinfo(result);
    freeaddrinfo(res);
    return 0;
}