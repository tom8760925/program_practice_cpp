#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>

int main()
{
    hostent *hp;
    hp = gethostbyname("www.miaoli.gov.tw"); // 使用網址
    if (hp == NULL)
    {
        return 1;
    }

    printf("p:%s\n", hp->h_name);                                // 網址
    printf("p:%d\n", hp->h_addrtype);                            // 類型
    printf("p:%s\n", *hp->h_aliases);                            // 備用host
    printf("p:%d\n", hp->h_length);                              // 長度
    struct in_addr hpad = *(struct in_addr *)hp->h_addr_list[0]; // 取得網路字串
    char *hpip = inet_ntoa(hpad);                                // 轉換成十進制
    printf("p:%s\n", hpip);                                      // ip

    printf("-------\n");

    hostent *hpa;

    hpa = gethostbyaddr(hp->h_addr_list[0], hp->h_length, hp->h_addrtype); // 使用網路字節

    if (hp == NULL)
    {
        return 1;
    }

    printf("p:%s\n", hpa->h_name);                                 // 網址
    printf("p:%d\n", hpa->h_addrtype);                             // 類型
    printf("p:%s\n", *hpa->h_aliases);                             // 備用host
    printf("p:%d\n", hpa->h_length);                               // 長度
    struct in_addr hpada = *(struct in_addr *)hpa->h_addr_list[0]; // 取得網路字串
    char *hpipa = inet_ntoa(hpada);                                // 轉換成十進制
    printf("p:%s\n", hpipa);

    return 0;
}