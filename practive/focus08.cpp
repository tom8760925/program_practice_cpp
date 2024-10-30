#include <iostream>
#include <stdio.h>

int main()
{
    const char *str1 = "abcde\0f";
    char str2[16];
    char str3[16];

    std::cout << "str1:" << str1 << '\n';

    std::cout << "----------\n";

    // 只複製到\0之前
    strcpy(str2, str1);
    std::cout << "str2:" << str2[6] << '\n';

    std::cout << "----------\n";

    // 全部都複製
    memcpy(str3, str1, sizeof(str1));
    std::cout << "str2:" << str3[6] << '\n';

    std::cout << std::endl;

    return 0;
}