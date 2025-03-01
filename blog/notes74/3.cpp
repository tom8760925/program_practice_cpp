#include <memory_resource>
#include <array>
#include <list>
#include <iostream>

int main()
{
    std::array<int, 1000> _ar;
    std::pmr::monotonic_buffer_resource _pmr(_ar.data(), _ar.size(), std::pmr::null_memory_resource());
    // 分配記憶體
    std::pmr::polymorphic_allocator _pa(&_pmr);
    // 使用
    std::pmr::list<int> _list({1, 2}, _pa);

    return 0;
}