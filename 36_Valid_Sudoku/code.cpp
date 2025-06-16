#include<iostream>
#include<vector>
#include<unordered_set>


class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) 
    {
        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> grid[9];

        for (uint8_t r = 0; r < 9; r++)
        {
            for (uint8_t c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                    continue;

                int grid_index = (r / 3) * 3 + (c / 3);

                for (auto &&i : grid[grid_index])
                {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
                

                if(rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || grid[grid_index].count(board[r][c]))
                    return false;

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                grid[grid_index].insert(board[r][c]);
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    char board[9][9] = 
[['5','3','.'','.','7','.','.',.,'.']
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

    s.isValidSudoku(board);

    return 0;
}