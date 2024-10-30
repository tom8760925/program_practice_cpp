#include <iostream>
#include <string>

// function 指標不輸出值
void func1(std::string s, int i)
{
    std::cout << s << ":" << i << '\n';
}
void (*funcp1)(std::string, int);
void (*funcp2)(std::string, int) = &func1;

// function 指標輸出值

int func2(int i)
{
    return i;
}
int (*funcp3)(int);
int (*funcp4)(int) = &func2;

// function array

void func3(std::string s, int i)
{
    std::cout << s << ":" << i << '\n';
}
void func4(std::string s, int i)
{
    std::cout << s << ":" << i << '\n';
}
void func5(std::string s, int i)
{
    std::cout << s << ":" << i << '\n';
}
void (*funca1[])(std::string s, int i) = {&func3, &func4, &func5};

int main()
{
    int a = 1;
    int ar[10] = {1, 2, 3, 4};
    // 指標
    int *b = &a;
    // 指標的指標
    int **c = &b;
    // 存儲10個指標的陣列
    int *d[10];
    // 存儲陣列指標
    int(*e)[10];

    std::cout << "b:" << *b << '\n';
    std::cout << "-------\n";
    std::cout << "c:" << **c << '\n';
    std::cout << "-------\n";
    d[0] = &a;
    std::cout << "d:" << *d[0] << '\n';
    std::cout << "-------\n";
    e = &ar;
    std::cout << "e:" << **e << '\n';
    std::cout << "e:" << *(*e + 1) << '\n';
    std::cout << "e:" << e[0][0] << '\n';
    std::cout << "e:" << e[0][1] << '\n';
    std::cout << "-------\n";

    std::cout << "\n";
    std::cout << "function 指標不輸出值\n";
    func1("func1", 1);
    std::cout << "-------\n";
    funcp1 = &func1;
    funcp1("funcp1", 1);
    std::cout << "-------\n";
    funcp2("funcp2", 1);

    std::cout << "\n";
    std::cout << "function 指標輸出值\n";
    std::cout << "func2:" << func2(1) << '\n';
    std::cout << "-------\n";
    funcp3 = &func2;
    std::cout << "funcp3:" << funcp3(1) << '\n';
    std::cout << "-------\n";
    std::cout << "funcp4:" << funcp4(1) << '\n';

    std::cout << "\n";
    std::cout << "function array\n";
    funca1[0]("func3", 1);
    std::cout << "-------\n";
    funca1[1]("func4", 1);
    std::cout << "-------\n";
    funca1[2]("func5", 1);

    std::cout << std::endl;

    return 0;
}