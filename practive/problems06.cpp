#include <iostream>
#include <vector>
#include <assert.h>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> r = {{1}};
        assert(numRows >= 1 && numRows <= 30);
        for (int n = 1; n < numRows; n++)
        {
            std::vector<int> rr;
            rr.push_back(1);
            for (int nn = 0; nn <= n - 2; nn++)
            {
                rr.push_back(r[n - 1][nn] + r[n - 1][nn + 1]);
            }
            rr.push_back(1);
            r.push_back(rr);
        }
        return r;
    }
};
int main()
{
    Solution s;
    for (auto &au : s.generate(5))
    {
        for (auto &aut : au)
        {
            std::cout << aut << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}