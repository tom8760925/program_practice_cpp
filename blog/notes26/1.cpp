#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main()
{
    // 一般不使用
    // 宣告
    sockaddr s;
    // 設定型態ipv4
    s.sa_family = AF_INET;
    // 設定長度
    s.sa_len = NULL;
    // 設定ip+port+zero
    // s.sa_data = ;

    // 宣告ipv4
    sockaddr_in s4;
    // 設定ip
    s4.sin_addr.s_addr = inet_addr("127.0.0.1");
    // 設定型態ipv4
    s4.sin_family = AF_INET;
    // 設定port號
    s4.sin_port = htons(8080);
    // 保留不使用
    // s4.sin_zero =;
    // 設定型態長度
    s4.sin_len = NULL;

    return 0;
}