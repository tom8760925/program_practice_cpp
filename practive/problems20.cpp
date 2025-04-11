#include <iostream>
#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int matrixsize = matrix.size();
        int n = 0;
        while (n < matrixsize)
        {
            for (int i = n + 1; i <= matrixsize - 1; i++)
            {
                std::swap(matrix[n][i], matrix[i][n]);
            }
            n++;
        }
        for (int i = 0; i < matrixsize; i++)
        {
            for (int ii = 0; ii < int(matrix[i].size()) / 2; ii++)
            {
                std::swap(matrix[i][ii], matrix[i][(matrix[i].size() - 1) - ii]);
            }
        }
    }
};
int main()
{
    Solution s;
    std::vector<std::vector<int>> v = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    s.rotate(v);
    for (auto &au : v)
    {
        for (auto &aut : au)
        {
            std::cout << aut << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}