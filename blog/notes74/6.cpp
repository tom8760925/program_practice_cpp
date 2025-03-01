#include <memory_resource>
#include <list>

class a : public std::pmr::memory_resource
{
private:
    // 分配記憶體
    void *do_allocate(std::size_t bytes, std::size_t alignment) override {}
    // 將記憶體返回到池中
    void do_deallocate(void *p, std::size_t bytes, std::size_t alignment) override {}
    // 判斷是否相等
    bool do_is_equal(const std::pmr::memory_resource &other) const noexcept override {}
};

int main()
{
    a _a;
    //設定memory_resource
    std::pmr::set_default_resource(&_a);
    std::pmr::list<int> _list(&_a);

    return 0;
}