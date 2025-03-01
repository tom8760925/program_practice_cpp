#include <memory_resource>
#include <array>

int main()
{
    // 當資料大小超過時，不會搬會報錯
    std::array<int, 1000> _ar1;
    std::pmr::monotonic_buffer_resource _pmr1(_ar1.data(), _ar1.size(), std::pmr::null_memory_resource());
    // 當資料大小超過時會搬
    std::array<int, 1000> _ar2;
    std::pmr::monotonic_buffer_resource _pmr2(_ar2.data(), _ar2.size(), std::pmr::new_delete_resource());

    return 0;
}