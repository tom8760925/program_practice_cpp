#include <iostream>
#include <vector>
#include <math.h>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int r = 0;
        int top1 = 0, top2 = 0;
        for (auto &au : height)
        {
            if (au > top1)
            {
                top1 = au;
            }
            else if (au > top2 && au != top1)
            {
                top2 = au;
            }
        }
        if (top2 != 0)
        {
            r = std::pow(std::min(top1, top2), 2);
        }
        else
        {
            r = std::pow(top1, 2);
        }
        return r;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {3, 3};
    std::cout << s.maxArea(v) << std::endl;
    return 0;
}