#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::vector<std::vector<int>> v = {};
        int start = intervals[0][0];
        int end = intervals[0][1];
        std::sort(intervals.begin(), intervals.end());
        for (int n = 0; n < int(intervals.size()) - 1; n++)
        {
            if (end >= intervals[n + 1][0])
            {
                end = std::max(end, intervals[n + 1][1]);
            }
            else
            {
                std::vector<int> vv = {start, end};
                v.push_back(vv);
                start = intervals[n + 1][0];
                end = intervals[n + 1][1];
            }
        }
        v.push_back({start, end});
        return v;
    }
};
int main()
{
    Solution s;
    std::vector<std::vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    for (auto &au : s.merge(v))
    {
        for (auto &aut : au)
        {
            std::cout << aut << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}