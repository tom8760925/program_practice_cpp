#include <iostream>
#include "3.cpp"

// 別名其他檔案的class
typedef c C;

// class
class b
{
public:
    b()
    {
        std::cout << "b" << std::endl;
    }
};
