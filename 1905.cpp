// 1905. Count Sub Islands
//         You are given two m x n binary matrices grid1 and grid2 containing only 0's(representing water) and
//     1's(representing land).An island is a group of 1's connected 4 - directionally(horizontal or vertical).Any cells outside of the grid are considered water cells.

//                                                                      An island in grid2 is considered a sub
//         - island if there is an island in grid1 that contains all the cells that make up this island in grid2.

//           Return the number of islands in grid2 that are considered sub
//         - islands.
#include<bits/stdc++.h>
          using namespace std;
set<pair<int,int>> island_maker(vector<vector<int>> &grid,int i,int j){
    set<pair<int, int>> st;
    int r = grid.size();
    int c = grid[0].size();
    st.insert({i, j});
    grid[i][j] = 2;
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        auto itr = q.front();
        int x = itr.first;
        int y = itr.second;
        q.pop();
        if(x-1>=0 && grid[x-1][y]==1){
            grid[x - 1][y] = 2;
            st.insert({x - 1, y});
            q.push({x - 1, y});
        }
        if(x+1<r && grid[x+1][y]==1){
            grid[x + 1][y] = 2;
            st.insert({x + 1, y});
            q.push({x + 1, y});
        }
        if(y+1<c && grid[x][y+1]==1){
            grid[x][y + 1] = 2;
            st.insert({x, y + 1});
            q.push({x, y + 1});
        }
        if(y-1>=0 && grid[x][y-1]==1){
            grid[x][y - 1] = 2;
            st.insert({x, y - 1});
            q.push({x, y - 1});
        }
    }
    return st;
}
void island_util(vector<vector<int>> &grid,int i,int j,set<pair<int,int>> &st){
    int r = grid.size();
    int c = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    st.insert({i, j});
    grid[i][j] = 2;
    while(!q.empty()){
        auto itr = q.front();
        q.pop();
        int x = itr.first;
        int y = itr.second;
        if(x-1>=0 && grid[x-1][y]==1){
            grid[x - 1][y] = 2;
            q.push({x - 1, y});
            st.insert({x - 1, y});
        }
        if(x+1<r && grid[x+1][y]==1){
            grid[x + 1][y] = 2;
            q.push({x + 1, y});
            st.insert({x + 1, y});
        }
        if(y-1>=0 && grid[x][y-1]==1){
            grid[x][y - 1] = 2;
            q.push({x, y - 1});
            st.insert({x, y - 1});
        }
        if(y+1<c && grid[x][y+1]){
            grid[x][y + 1] = 2;
            q.push({x, y + 1});
            st.insert({x, y + 1});
        }
    }
}
void island(vector<vector<int>> &grid,set<pair<int,int>> &st){
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 0;i<r;i++){
        for (int j = 0; j < c;j++){
            if(grid[i][j]==1){
                island_util(grid, i, j, st);
            }
        }
    }
    
}
int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int r = grid1.size();
    int c = grid1[0].size();
    set<pair<int, int>> st1;
    island(grid1, st1);
    // for (auto itr : st1)
    // {
    //     cout << itr.first << " " << itr.second << endl;
    // }
    set<pair<int, int>> st2;
    int count = 0;
    for (int i = 0; i < r;i++){
        for (int j = 0; j < c;j++){
            if(grid2[i][j]==1){
                st2=island_maker(grid2, i, j);
                bool flag = true;
                for(auto itr:st2){
                    if(st1.find(itr)==st1.end()){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    count++;
                st2.clear();
            }
        }
    }
    return count;
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid1(m, vector<int>(n));
    vector<vector<int>> grid2(m, vector<int>(n));
    for (int i = 0; i < m;i++)
        for (int j = 0; j < n;j++)
            cin >> grid1[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid2[i][j];
    cout << countSubIslands(grid1, grid2) << endl;
    return 0;
}