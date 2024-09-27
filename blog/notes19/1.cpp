#include <stack>

using namespace std;

void stack1();

int main()
{
    stack1();
    return 0;
}
void stack1()
{
    stack<int> s; // 宣告
    s.push(1);    // 從頭加入
    if (!s.empty())
    {
        printf("p:%d\n", s.top()); // 顯示頭的值
    }
    s.push(2);
    if (!s.empty())
    {
        printf("p:%d\n", s.top());
    }
    s.push(3);
    if (!s.empty())
    {
        printf("p:%d\n", s.top());
    }
    printf("------------\n");
    printf("p:%d\n", int(s.size())); // 大小
    printf("------------\n");
    if (!s.empty()) // 是否為空
    {
        s.pop(); // 從頭移出
    }
    printf("p:%d\n", int(s.size()));
    if (!s.empty())
    {
        s.pop();
    }
    printf("p:%d\n", int(s.size()));
}