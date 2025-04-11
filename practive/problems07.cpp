#include <vector>
#include <iostream>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int r = 0;
        int s = prices.size();
        for (int n = 0; n < s - 1; n++)
        {
            for (int nn = n; nn < s; nn++)
            {
                if (prices[nn] - prices[n] > r)
                {
                    r = prices[nn] - prices[n];
                }
            }
        }
        return r;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {7, 1, 5, 3, 6, 4};
    std::cout << s.maxProfit(v) << std::endl;
    return 0;
}