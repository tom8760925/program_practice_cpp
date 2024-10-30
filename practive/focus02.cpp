int main()
{
    const int a = 1; // 值不能改
    int const b = 2; // 值不能改
    int aa = 1;
    const int *c = &aa;       // 不能改值，能改指數
    int *const d = &aa;       // 能改值，不能改指數
    const int *const e = &aa; // 不能改值，不能改指數
    return 0;
}