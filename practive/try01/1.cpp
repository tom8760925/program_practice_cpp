#include "2.hpp"

int main()
{
    try
    {
        int n = 0;
        if (n == 0)
        {
            throw outerr::NotExitException(1, "n=0", "main");
        }
    }
    catch (outerr::NotExitException &e)
    {
        // 顯示錯誤訊息
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    try
    {
        int n = 0;
        if (n == 0)
        {
            throw outerr::ErrException(1, "n=0", "main");
        }
    }
    catch (outerr::ErrException &e)
    {
        // 顯示錯誤訊息
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return 0;
}