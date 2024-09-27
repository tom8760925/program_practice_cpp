#include <deque>
#include <iostream>

using namespace std;

void deque1();

int main()
{
    deque1();
    return 0;
}
void deque1()
{
    deque<int> d = {1, 2, 3, 4, 5}; // 宣告
    for (int n : d)                 // 顯示資料
    {
        printf("p:%d\n", n);
    }
    printf("----------\n");
    printf("p:%d\n", int(d.size())); // 大小
    printf("----------\n");
    printf("p:%s\n", d.empty() ? "true" : "false"); // 是否空白
    printf("----------\n");
    d.pop_front();                              // 刪除頭
    d.pop_back();                               // 刪除尾
    d.push_front(0);                            // 新增在頭
    d.push_back(6);                             // 新增在尾
    for (auto n = d.begin(); n != d.end(); n++) // 顯示資料
    {
        printf("p:%d\n", *n);
    }
    printf("----------\n");
    d.insert(d.begin(), 1 /*數量*/, 1 /*值*/); // 新增在頭，並新增1個
    d.insert(d.end(), {5, 5});                 // 新增在尾，並新增2個
    int a[] = {3, 3};
    d.insert(next(d.begin(), 4), a, a + size(a)); // 新增在第5個位置，並用陣列新增
    for (auto n = d.cbegin(); n != d.cend(); n++) // 顯示資料
    {
        printf("p:%d\n", *n);
    }
}