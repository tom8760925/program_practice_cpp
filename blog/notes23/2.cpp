#include <arpa/inet.h>
#include <iostream>

int main()
{
    // 轉換成網路字節32位的
    std::cout << "p:" << htonl(8080) << '\n';
    // 轉換成網路字節16位的
    std::cout << "p:" << htons(8080) << '\n';
    std::cout << "--------\n";
    // 網路字節32位轉換成主機字節
    std::cout << "p:" << ntohl(htonl(8080)) << '\n';
    // 網路字節16位轉換成主機字節
    std::cout << "p:" << ntohs(htons(8080)) << '\n';
    std::cout << std::endl;
    return 0;
}