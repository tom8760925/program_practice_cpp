#include <memory_resource>

int main()
{
    std::pmr::pool_options options;
    // 一個塊的最大數量，設為0為沒有限制。
    options.max_blocks_per_chunk = 0;
    // 能處理塊的最大數量，設為0為沒有限制。
    options.largest_required_pool_block = 0;
    std::pmr::synchronized_pool_resource _pmr(options);

    return 0;
}