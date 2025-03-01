#include <memory_resource>
#include <array>

int main()
{
    // 1
    std::array<int, 1000> _ar1;
    std::pmr::monotonic_buffer_resource _pmr1(_ar1.data(), _ar1.size(), std::pmr::null_memory_resource());
    // 2
    std::pmr::monotonic_buffer_resource _pmr2(1000);
    // 3
    std::pmr::monotonic_buffer_resource _pmr3(1000, std::pmr::new_delete_resource());
    // 4
    std::pmr::monotonic_buffer_resource _pmr4(std::pmr::new_delete_resource());
    // 5
    std::pmr::monotonic_buffer_resource _pmr5;

    return 0;
}