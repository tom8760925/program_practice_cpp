#ifndef TEST_H // 判斷有沒有重複載入
#define TEST_H

int a();

class test_class
{
public:
    int test_a;
    int test_b;
    int test_c();

private:
    int test_d = 3;
};

namespace test_namespace
{
    class test_class
    {
    public:
        int test_a;
        int test_b;
        int test_c();

    private:
        int test_d = 3;
    };
    int test_e();
}
#endif