#include <iostream>
#include "2.cpp"

// class
class a
{
public:
    a()
    {
        std::cout << "a" << std::endl;
    }
};

// 別名
typedef a A;
// 別名其他檔案的class
typedef b B;

int main()
{
    A aa;
    B bb;
    // 使用其他檔案裡的別名class
    C cc;
    return 0;
}