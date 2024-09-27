#include "test.h"

// a()

int a()
{
    return 2;
}

// test_class

int test_class::test_c()
{
    return this->test_a + this->test_b + this->test_d;
};

// test_namespace

int test_namespace::test_class::test_c()
{
    return this->test_a + this->test_b + this->test_d;
}
int test_namespace::test_e()
{
    return 3;
}
