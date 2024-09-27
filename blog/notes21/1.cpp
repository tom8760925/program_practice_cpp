#include <queue>

using namespace std;

void queue1();

int main()
{
    queue1();
    return 0;
}
void queue1()
{
    queue<int> q; // 宣告
    q.push(1);    // 新增
    q.push(2);
    q.push(3);
    printf("p:%d\n", q.front());     // 頭的值
    printf("p:%d\n", q.back());      // 尾的值
    printf("p:%d\n", int(q.size())); // 大小
    printf("-------\n");
    q.pop(); // 從頭移除
    printf("p:%d\n", int(q.size()));
    printf("p:%d\n", q.front());
    printf("p:%d\n", q.back());
}