// 130. Surrounded Regions
//         Given an m x n matrix board containing 'X' and
//     'O',
//     capture all regions that are 4 - directionally surrounded by 'X'.

//                                      A region is captured by flipping all 'O' s into 'X' s in that surrounded region.

//                                      Example 1 :

//     Input : board = [ [ "X", "X", "X", "X" ], [ "X", "O", "O", "X" ], [ "X", "X", "O", "X" ], [ "X", "O", "X", "X" ] ] Output : [ [ "X", "X", "X", "X" ], [ "X", "X", "X", "X" ], [ "X", "X", "X", "X" ], [ "X", "O", "X", "X" ] ] Explanation : Surrounded regions should not be on the border,
//             which means that any 'O' on the border of the board are not flipped to 'X'.Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.Two cells are connected if they are adjacent cells connected horizontally or vertically.
#include<bits/stdc++.h>
using namespace std;
void solve_util(vector<vector<char>> &board,int i,int j){
    int m = board.size();
    int n = board[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();
        int x = itr.first;
        int y = itr.second;
        if (y - 1 >= 0 && y - 1 < n && board[x][y - 1] == 'O')
        {
            board[x][y - 1] = '1';
            q.push({x, y - 1});
        }
        if (y + 1 >= 0 && y + 1 < n && board[x][y + 1] == 'O')
        {
            board[x][y + 1] = '1';
            q.push({x, y + 1});
        }
        if (x - 1 >= 0 && x - 1 < m && board[x - 1][y] == 'O')
        {
            board[x - 1][y] = '1';
            q.push({x - 1, y});
        }
        if (x + 1 >= 0 && x + 1 < m && board[x + 1][y] == 'O')
        {
            board[x + 1][y] = '1';
            q.push({x + 1, y});
        }
    }
}
void solve(vector<vector<char>> &board){
    int row = board.size();
    int col = board[0].size();
    for (int j = 0; j < col; j++)
    {
        if (board[0][j] == 'O')
        {
            board[0][j] = '1';
            solve_util(board, 0, j);
        }
    }
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == 'O')
        {
            board[i][0] = '1';
            solve_util(board, i, 0);
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (board[row - 1][j] == 'O')
        {
            board[row - 1][j] = '1';
            solve_util(board, row - 1, j);
        }
    }
    for (int i = 0; i < row; i++)
    {
        if (board[i][col - 1] == 'O')
        {
            board[i][col - 1] = '1';
            solve_util(board, i, col - 1);
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == '1')
            {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> board[i][j];
        }
    }
    solve(board);
    return 0;
}