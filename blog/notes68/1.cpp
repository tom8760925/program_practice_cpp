#include <iostream>
namespace a
{
    struct s
    {
        int n = 0;
    };
    s operator+(s s1, s s2)
    {
        s s3;
        s3.n = s1.n + s2.n;
        return s3;
    }
}
int main()
{
    a::s s1{1};
    std::cout << s1.n << std::endl;
    a::s s2{2};
    std::cout << s2.n << std::endl;
    // a::operator+(s1, s2);如果沒有ADL就需要這樣寫
    // operator+(s1, s2);但有ADL就能這樣樣寫
    a::s s3 = s1 + s2;
    std::cout << s3.n << std::endl;
    return 0;
}