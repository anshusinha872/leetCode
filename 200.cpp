// 200. Number of Islands
//         Given an m x n 2D binary grid grid which represents a map of '1' s(land) and
//     '0' s(water),
//     return the number of islands.

//                An island is surrounded by water and is formed by connecting adjacent lands horizontally
//                or vertically.You may assume all four edges of the grid are all surrounded by water.

//                   Example 1 :

//     Input : grid = [
//         [ "1", "1", "1", "1", "0" ],
//         [ "1", "1", "0", "1", "0" ],
//         [ "1", "1", "0", "0", "0" ],
//         [ "0", "0", "0", "0", "0" ]
//     ] Output : 1 Example 2 :

//     Input : grid = [
//         [ "1", "1", "0", "0", "0" ],
//         [ "1", "1", "0", "0", "0" ],
//         [ "0", "0", "1", "0", "0" ],
//         [ "0", "0", "0", "1", "1" ]
//     ] Output : 3

//                    Constraints :

//     m
//     == grid.length n
//     == grid[i].length 1 <= m,
//             n <= 300 grid[i][j] is '0' or '1'.
#include<bits/stdc++.h>
using namespace std;
void numIslands_util(vector<vector<char>> &grid,int i,int j){
    if(i<0 ||i>=grid.size()||j<0 || j>=grid[0].size())
        return;
    if(grid[i][j]=='2'||grid[i][j]=='0')
        return;
    int m = grid.size();
    int n = grid[0].size();
    grid[i][j] = '2';
    numIslands_util(grid, i - 1, j);
    numIslands_util(grid, i + 1, j);
    numIslands_util(grid, i, j - 1);
    numIslands_util(grid, i, j + 1);
}
int numIslands(vector<vector<char>> &grid){
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            if(grid[i][j]=='1'){
                count++;
                numIslands_util(grid, i, j);
            }
        }
    }
    return count;
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> grid[i][j];
        }
    }
    cout << numIslands(grid) << endl;
    return 0;
}