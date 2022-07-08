// 695. Max Area of Island
//         You are given an m x n binary matrix grid.An island is a group of 1's(representing land)connected 4 -
//     directionally(horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

//     The area of an island is the number of cells with a value 1 in the island.

//     Return the maximum area of an island in grid.If there is no island,
//     return 0.

//            Example 1 :

//     Input : grid = [ [ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 ], [ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ], [ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ], [ 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 ], [ 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 ], [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ], [ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 ], [ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 ] ] Output : 6 Explanation : The answer is not 11,
//             because the island must be connected 4 - directionally.Example 2 :

//     Input : grid = [[ 0, 0, 0, 0, 0, 0, 0, 0 ]] Output : 0

//                    Constraints :

//     m
//     == grid.length n
//     == grid[i].length 1 <= m,
//             n <= 50 grid[i][j] is either 0 or 1.

#include<bits/stdc++.h>
using namespace std;
int maxAreaOfIsland_util(vector<vector<int>> &grid,int i,int j){
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    queue<pair<int,int>> q;
    grid[i][j] = 2;
    q.push({i,j});
    while(q.empty()==false){
        auto itr = q.front();
        count++;
        q.pop();
        int x = itr.first;
        int y = itr.second;
        cout << x<<" " << y<<" " << endl;
        // grid[x][y] = 2;
        if((y>=1 && y<=cols) && (x>=0 && x<rows)){
            if(grid[x][y-1]==1){
                grid[x][y - 1] = 2;
                q.push({x, y - 1});
            }
        }
        if ((y >= -1 && y <= cols - 2 )&& (x >= 0 && x < rows))
        {
            if(grid[x][y+1]==1){
                grid[x][y + 1] = 2;
                q.push({x, y + 1});
            }
        }
        if((x>=1 && x<=rows) && (y>=0 && y<cols)){
            if(grid[x-1][y]==1){
                grid[x - 1][y] = 2;
                q.push({x - 1, y});
            }
        }
        if(x>=-1 && x<=rows-2 && (y>=0 && y<cols)){
            if(grid[x+1][y]==1){
                grid[x + 1][y] = 2;
                q.push({x + 1, y});
            }
        }
    }
    return count;
}
int maxAreaOfIsland(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            if(grid[i][j]==1){
                ans=max(ans,maxAreaOfIsland_util(grid, i, j));
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
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
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}