#include <memory_resource>

int main()
{
    // 記憶體池安全的版本
    std::pmr::synchronized_pool_resource _pmr;
    // 記憶體池不安全的版本
    std::pmr::unsynchronized_pool_resource _pmru;

    return 0;
}