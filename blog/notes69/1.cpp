#include <assert.h>
#include <iostream>
int main()
{
    int n = 0;
    // 不離開
    assert(n == 0);
    // 離開
    assert(n == 1);
    return 0;
}