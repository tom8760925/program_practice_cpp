#include <iostream>
#include "test.h"
using namespace std;

void test1();
void test2();
void test3();

int main()
{
    test1();
    printf("---------\n");
    test2();
    printf("---------\n");
    test3();
    return 0;
}
void test1()
{
    printf("p:%d\n", a()); // 使用a()函式
}
void test2()
{
    test_class t;
    t.test_a = 1;
    t.test_b = 2;
    printf("p:%d\n", t.test_c()); // 使用class中的test_c()函式
}
void test3()
{
    test_namespace::test_class t;
    t.test_a = 1;
    t.test_b = 2;
    printf("p:%d\n", t.test_c());               // 使用class中的test_c()函式
    printf("p:%d\n", test_namespace::test_e()); // 使用test_e()函式
}
