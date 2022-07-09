// 1020. Number of Enclaves
// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

// Example 1:


// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
// Example 2:


// Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// Output: 0
// Explanation: All 1s are either on the boundary or can reach the boundary.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] is either 0 or 1.
#include<bits/stdc++.h>
using namespace std;
void land_to_water(vector<vector<int>> &grid,int i,int j){
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        auto itr = q.front();
        q.pop();
        int x = itr.first;
        int y = itr.second;
        // left cell
        if(x-1>=0 && grid[x-1][y]==1){
            grid[x - 1][y] = 0;
            q.push({x - 1, y});
        }
        // right cell
        if(x+1<m && grid[x+1][y]==1){
            grid[x + 1][y] = 0;
            q.push({x + 1, y});
        }
        // Top cell
        if(y-1>=0 && grid[x][y-1]==1){
            grid[x][y - 1] = 0;
            q.push({x, y - 1});
        }
        // Bottom cell
        if(y+1<n && grid[x][y+1]==1){
            grid[x][y + 1] = 0;
            q.push({x, y + 1});
        }
    }
}
int numEnclaves(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    // Left_Most + right_most column
    for (int i = 0; i < m;i++){
        if(grid[i][0]==1){
            grid[i][0] = 0;
            land_to_water(grid, i, 0);
        }
        if(grid[i][n-1]==1){
            grid[i][n - 1] = 0;
            land_to_water(grid, i, n - 1);
        }
    }
    // Top + bottom Row
    for (int j = 0; j < n;j++){
        if(grid[0][j]==1){
            grid[0][j] = 0;
            land_to_water(grid, 0, j);
        }
        if(grid[m-1][j]==1){
            grid[m - 1][j] = 0;
            land_to_water(grid, m - 1, j);
        }
    }
    int count = 0;
    for (int i = 1; i <= m - 2;i++){
        for (int j = 1; j <= n - 2;j++){
            if(grid[i][j]==1){
                count++;
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
    cout << numEnclaves(grid) << endl;
    // for (int i = 0; i < m;i++){
    //     for (int j = 0; j < n;j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}