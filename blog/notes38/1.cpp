#include <iostream>

template <typename T>
void func(T t)
{
    // 判斷輸入資料的型態
    if (std::is_same<T, int>::value)
    {
        std::cout << "I:" << t << std::endl;
    }
    else if (std::is_same<T, char>::value)
    {
        std::cout << "C:" << t << std::endl;
    }
}

int main()
{
    int n = 1;
    func(n);
    char c = 'a';
    func(c);
    return 0;
}