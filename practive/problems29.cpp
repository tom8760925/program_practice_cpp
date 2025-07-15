#include <iostream>
#include <vector>
#include <string>

class Solution
{
private:
    std::vector<std::vector<int>> rcadd = {{1, -1, 0, 0}, {0, 0, 1, -1}};
    // 判斷
    bool existbool(std::vector<std::vector<char>> &board, std::string word, int n, int r, int c)
    {
        // 判斷是否相同
        if (n == int(word.size()))
        {
            return true;
        }
        // 判斷是否在範圍內和是否相等
        if (int(board.size()) <= r || r < 0 || int(board[0].size()) <= c || c < 0 || board[r][c] != word[n])
        {
            return false;
        }

        char t = board[r][c];
        // 替換
        board[r][c] = '!';
        // 檢查上下左右
        for (int i = 0; i < 4; i++)
        {
            if (existbool(board, word, n + 1, r + rcadd[0][i], c + rcadd[1][i]))
            {
                return true;
            }
        }
        // 換回
        board[r][c] = t;

        return false;
    }

public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        std::set<std::string> strmap = {};
        // 巡迴每個開頭
        for (int n = 0; n < int(board.size()); n++)
        {
            for (int nn = 0; nn < int(board[0].size()); nn++)
            {
                if (existbool(board, word, 0, n, nn))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::cout << s.exist(board, "ABCC") << std::endl;
    return 0;
}