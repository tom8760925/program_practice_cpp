#include <iostream>
#include <vector>

class Solution
{
private:
    void csum(std::vector<std::vector<int>> &v, std::vector<int> &candidates, int target, std::vector<int> vsum, int n, int nsum)
    {
        if (nsum == target)
        {
            v.push_back(vsum);
            return;
        }

        if (nsum > target || n >= int(candidates.size()))
        {
            return;
        }

        vsum.push_back(candidates[n]);
        csum(v, candidates, target, vsum, n, nsum + candidates[n]);
        vsum.pop_back();
        csum(v, candidates, target, vsum, n + 1, nsum);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
    {
        std::vector<std::vector<int>> v;
        csum(v, candidates, target, {}, 0, 0);
        return v;
    }
};
int main()
{
    Solution s;
    std::vector<int> v = {2, 3, 6, 7};
    for (auto &au : s.combinationSum(v, 7))
    {
        for (auto &aut : au)
        {
            std::cout << aut << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}