#include <iostream>

// 假裝是其他檔案的函式
int func(int n)
{
    // 宣告外部函數
    extern int e;
    return n + e;
}

int e;

int main()
{
    e = 1;
    std::cout << func(1) << std::endl;
    return 0;
}