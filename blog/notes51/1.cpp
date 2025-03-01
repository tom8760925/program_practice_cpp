#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    // 字串長度
    std::cout << "strlen:" << std::strlen("abc") << std::endl;
    // 字串複製
    char c[10];
    std::strcpy(c, "abc");
    std::cout << "strcpy:" << c << std::endl;
    // 字串串接
    char c1[10] = "abc";
    std::strcat(c1, "def");
    std::cout << "strcat:" << c1 << std::endl;
    // 轉換成小寫
    std::cout << "tolower:" << std::tolower('A') << std::endl;
    // 轉換成大寫
    std::cout << "toupper:" << std::toupper('a') << std::endl;
    // 轉換成浮點數
    std::cout << "atof:" << std::atof("1.1") << std::endl;
    // 轉換成整數
    std::cout << "atoi:" << std::atoi("1") << std::endl;
    // 轉換成長整數
    std::cout << "atol:" << std::atol("1") << std::endl;

    return 0;
}