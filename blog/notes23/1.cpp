#include <arpa/inet.h>
#include <iostream>

int main()
{
    char ip[] = "192.168.1.10";
    in_addr add1, add2, add3, add4, add5, add6, add7;
    std::cout << "1.-------\n";
    // 1.轉換成網路字節
    add1.s_addr = inet_addr(ip);
    std::cout << add1.s_addr << std::endl;
    std::cout << "2.-------\n";
    // 2.轉換成網路位子
    if (inet_aton(ip, &add2) == 0)
    {
        return 1;
    }
    std::cout << add2.s_addr << std::endl;
    std::cout << "3.-------\n";
    // 3.獲取網路位置
    add3.s_addr = inet_netof(add2);
    std::cout << add3.s_addr << std::endl;
    std::cout << "4.-------\n";
    // 4.獲取主機位置
    add4.s_addr = inet_lnaof(add2);
    std::cout << add4.s_addr << std::endl;
    std::cout << "5.-------\n";
    // 5.組合網路位置和主機位置
    add5 = inet_makeaddr(add3.s_addr, add4.s_addr);
    std::cout << add5.s_addr << std::endl;
    std::cout << "6.-------\n";
    // 6.轉換成主機字節
    add6.s_addr = inet_network(ip);
    std::cout << add6.s_addr << std::endl;
    std::cout << "7.-------\n";
    // 7.轉換成十進制
    std::cout << inet_ntoa(add1) << std::endl;
    std::cout << "8.-------\n";
    // 8.轉換成十進制
    char str[INET_ADDRSTRLEN];
    std::cout << inet_ntop(AF_INET, &add1.s_addr, str, sizeof(str)) << std::endl;
    std::cout << str << std::endl;
    std::cout << "9.-------\n";
    // 9.轉換成網路字節
    if (inet_pton(AF_INET, ip, &add7.s_addr) == 0)
    {
        return 1;
    }
    std::cout << add7.s_addr << std::endl;

    return 0;
}