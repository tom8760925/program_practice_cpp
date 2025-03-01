class a
{
public:
    a(int n) {};
    explicit a(const char *c) {};
};

int main()
{
    // 隱式轉換
    a _a1 = 1;
    // a _a2 = "aa"; 不能用
    a _a2("aa");
    return 0;
}