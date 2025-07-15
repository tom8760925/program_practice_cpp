#include <iostream>
#include <vector>
#include <string>

class Solution
{
private:
    std::vector<std::vector<std::string>> strarr;
    std::vector<std::vector<char>> chararr;
    // 判斷條件
    bool nqueensbool(int r, int c, int n)
    {
        // 判斷是否同一行有q
        for (int i = r - 1; i >= 0; i--)
        {
            if (chararr[i][c] == 'Q')
            {
                return false;
            }
        }
        // 判斷是否同一列有q
        for (int i = r - 1, ii = c - 1; i >= 0 && ii >= 0; i--, ii--)
        {
            if (chararr[i][ii] == 'Q')
            {
                return false;
            }
        }
        // 判斷是否右上角有q
        for (int i = r - 1, ii = c + 1; i >= 0 && ii < n; i--, ii++)
        {
            if (chararr[i][ii] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    // 處理q
    void nqueensswap(int r, int n)
    {
        // 判斷是否到底了
        if (r == n)
        {
            std::vector<std::string> strarr1 = {};
            for (int i = 0; i < n; i++)
            {
                std::string str = "";
                for (int ii = 0; ii < n; ii++)
                {
                    str += chararr[i][ii];
                }
                strarr1.push_back(str);
            }
            strarr.push_back(strarr1);
            return;
        }
        // 處理列
        for (int c = 0; c < n; c++)
        {

            chararr[r][c] = 'Q';
            nqueensswap(r + 1, n);
            chararr[r][c] = '.';

            /*
            // 判斷條件
            if (nqueensbool(r, c, n))
            {
                chararr[r][c] = 'Q';
                nqueensswap(r + 1, n);
                chararr[r][c] = '.';
            }
                */
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        // 初始陣列
        chararr.resize(n, std::vector<char>(n, '.'));
        // 開始
        nqueensswap(0, n);
        return strarr;
    }
};
int main()
{
    Solution s;
    for (auto au : s.solveNQueens(3))
    {
        for (auto aut : au)
        {
            std::cout << aut << ",";
        }
        std::cout << std::endl;
    }
    return 0;
}