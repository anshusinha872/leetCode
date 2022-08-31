// 1162. As Far from Land as Possible
//         Given an n x n grid containing only values 0 and
//     1,
//     where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance.If no land or water exists in the grid, return -1.

//                                                                                                                                                                                                            The distance used in this problem is the Manhattan distance : the distance between two cells(x0, y0) and
//                                                                                                                                                                                                            (x1, y1) is | x0 - x1 | + | y0 - y1 |.
#include<bits/stdc++.h>
using namespace std;

int maxDistanceUtil(vector<vector<int>> &grid,queue<pair<pair<int, int>, int>> &q){
    int maxDist = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    while(!q.empty()){
        auto itr = q.front();
        q.pop();
        int currDist = itr.second;
        maxDist = max(maxDist, itr.second);
        int x = itr.first.first;
        int y = itr.first.second;
        if(x-1>=0 && grid[x-1][y]==0){
            grid[x - 1][y] = 1;
            q.push({{x - 1, y}, currDist + 1});
        }
        if(x+1<rows && grid[x+1][y]==0){
            grid[x + 1][y] = 1;
            q.push({{x + 1, y}, currDist + 1});
        }
        if(y-1>=0 && grid[x][y-1]==0){
            grid[x][y - 1] = 1;
            q.push({{x, y - 1}, currDist + 1});
        }
        if(y+1<cols && grid[x][y+1]==0){
            grid[x][y + 1] = 1;
            q.push({{x, y + 1}, currDist + 1});
        }
    }
    return maxDist;
}
int maxDistance(vector<vector<int>> &grid){
    int row = grid.size();
    int cols = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    bool flag1 = false;
    bool flag2 = false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                flag1 = true;
                q.push({{i, j}, 0});
            }
            else if (grid[i][j] == 0)
            {
                flag2 = true;
            }
        }
    }
    if (!flag1 || !flag2)
        return -1;
    return maxDistanceUtil(grid, q);
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
    cout << maxDistance(grid) << endl;
    return 0;
}