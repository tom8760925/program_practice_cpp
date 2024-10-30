#include <iostream>
#include <stdio.h>

// 列舉
enum a
{
    no01,
    no02
};

// 列舉
enum b
{
    no03 = 1,
    no04 = 2
};

int main()
{
    // a
    printf("p:%d\n", a::no01);
    printf("p:%d\n", a::no02);

    printf("---------\n");

    // b
    printf("p:%d\n", b::no03);
    printf("p:%d\n", b::no04);

    return 0;
}