#include <iostream>
#include <vector>

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<int> v(n, 1);
        for (int i = 1; i < m; i++)
        {
            std::vector<int> vv(n, 1);
            for (int ii = 1; ii < n; ii++)
            {
                vv[ii] = vv[ii - 1] + v[ii];
            }
            v = vv;
        }
        return v[n - 1];
    }
};
int main()
{
    Solution s;
    std::cout << s.uniquePaths(3, 2) << std::endl;
    return 0;
}