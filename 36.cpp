#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cstring>
#include <memory>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int hang[9][9];
        int lie[9][9];
        int gong[3][3][9];
        memset(hang, 0, sizeof(hang));
        memset(lie, 0, sizeof(lie));
        memset(gong, 0, sizeof(gong));
        for (int i = 0; i<9;i++)
        {
            for (int j = 0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(hang[i][board[i][j]-'1'] || lie[j][board[i][j]-'1'] || gong[i/3][j/3][board[i][j] - '0'])
                    {
                        return false;
                    }
                    else
                    {
                        hang[i][board[i][j] - '1']++;
                        lie[j][board[i][j] - '1']++;
                        gong[i/3][j/3][board[i][j] - '1']++;
                    }
                }
            }
        }
        return true;

    }
};