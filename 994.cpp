#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }
        int time = 0;
        while (!q.empty())
        {
            auto itr = q.front();
            q.pop();
            int r = itr.first.first;
            int c = itr.first.second;
            int t = itr.second;
            time = max(time, t);
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] != 2)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> grid[i][j];
        }
    }
    Solution s;
    cout << s.orangesRotting(grid) << '\n';
    return 0;
}