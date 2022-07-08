// 1254. Number of Closed Islands
//         Given a 2D grid consists of 0s(land) and
//     1s(water).An island is a maximal 4 - directionally connected group of 0s and a closed island is an island totally(all left, top, right, bottom)
// surrounded by 1s.

//     Return the number of closed islands.

//     Example 1 :

//     Input : grid = [ [ 1, 1, 1, 1, 1, 1, 1, 0 ], [ 1, 0, 0, 0, 0, 1, 1, 0 ], [ 1, 0, 1, 0, 1, 1, 1, 0 ], [ 1, 0, 0, 0, 0, 1, 0, 1 ], [ 1, 1, 1, 1, 1, 1, 1, 0 ] ] Output : 2 Explanation : Islands in gray are closed because they are completely surrounded by water(group of 1s).Example 2 :

//     Input : grid = [ [ 0, 0, 1, 0, 0 ], [ 0, 1, 0, 1, 0 ], [ 0, 1, 1, 1, 0 ] ] Output : 1 Example 3 :

//     Input : grid = [ [ 1, 1, 1, 1, 1, 1, 1 ],
//                      [ 1, 0, 0, 0, 0, 0, 1 ],
//                      [ 1, 0, 1, 1, 1, 0, 1 ],
//                      [ 1, 0, 1, 0, 1, 0, 1 ],
//                      [ 1, 0, 1, 1, 1, 0, 1 ],
//                      [ 1, 0, 0, 0, 0, 0, 1 ],
//                      [ 1, 1, 1, 1, 1, 1, 1 ] ] Output : 2

//                    Constraints :

//                    1 <= grid.length,
//             grid[0].length <= 100 0 <= grid[i][j] <= 1
#include<bits/stdc++.h>
                using namespace std;
void count_island(vector<vector<int>> &grid,int i,int j){
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();
        int x = itr.first;
        int y = itr.second;
        if (y - 1 >= 0 && y - 1 < n && grid[x][y - 1] == 0)
        {
            grid[x][y - 1] = 3;
            q.push({x, y - 1});
        }
        if (y + 1 >= 0 && y + 1 < n && grid[x][y + 1] == 0)
        {
            grid[x][y + 1] = 3;
            q.push({x, y + 1});
        }
        if (x - 1 >= 0 && x - 1 < m && grid[x - 1][y] == 0)
        {
            grid[x - 1][y] = 3;
            q.push({x - 1, y});
        }
        if (x + 1 >= 0 && x + 1 < m && grid[x + 1][y] == 0)
        {
            grid[x + 1][y] = 3;
            q.push({x + 1, y});
        }
    }
}
void closedIsland_util(vector<vector<int>> &grid,int i,int j){
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();
        int x = itr.first;
        int y = itr.second;
        if (y - 1 >= 0 && y - 1 < n && grid[x][y - 1] == 0)
        {
            grid[x][y - 1] = 2;
            q.push({x, y - 1});
        }
        if (y + 1 >= 0 && y + 1 < n && grid[x][y + 1] == 0)
        {
            grid[x][y + 1] = 2;
            q.push({x, y + 1});
        }
        if (x - 1 >= 0 && x - 1 < m && grid[x - 1][y] == 0)
        {
            grid[x - 1][y] = 2;
            q.push({x - 1, y});
        }
        if (x + 1 >= 0 && x + 1 < m && grid[x + 1][y] == 0)
        {
            grid[x + 1][y] = 2;
            q.push({x + 1, y});
        }
    }
}
int closedIsland(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    for (int j = 0; j < n; j++)
    {
        if (grid[0][j] == 0)
        {
            grid[0][j] = 2;
            closedIsland_util(grid, 0, j);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[i][0] == 0)
        {
            grid[i][0] = 2;
            closedIsland_util(grid, i, 0);
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (grid[m - 1][j] == 0)
        {
            grid[m - 1][j] = 2;
            closedIsland_util(grid, m - 1, j);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[i][n - 1] == 0)
        {
            grid[i][n - 1] = 2;
            closedIsland_util(grid, i, n - 1);
        }
    }
    int count = 0;
    for (int i = 1; i <= m - 2;i++){
        for (int j = 1; j <= n - 2;j++){
            if(grid[i][j]==0){
                count++;
                grid[i][j] = 3;
                count_island(grid, i, j);
            }
        }
    }
    return count;
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> grid[i][j];
        }
    }
    cout << closedIsland(grid) << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}