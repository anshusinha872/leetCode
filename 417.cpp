#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int, int>> pacific;
        set<pair<int,int>> atlantic;
        vector<vector<int>> vect;
        int m=heights.size();
        int n = heights[0].size();
        int i = 0, j = 0;
        for (j = 0; j < n;j++)
        {
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()){
                auto itr = q.front();
                q.pop();
                int x = itr.first;
                int y = itr.second;
                if(pacific.find({x,y})==pacific.end()){
                    pacific.insert({x, y});
                }
                if(x-1>=0 && (heights[x-1][y]>=heights[x][y])){
                    if(pacific.find({x-1,y})==pacific.end()){
                        pacific.insert({x - 1, y});
                        q.push({x - 1, y});
                    }
                }
                if(x+1<m && (heights[x+1][y]>=heights[x][y])){
                    if(pacific.find({x+1,y})==pacific.end()){
                        pacific.insert({x + 1, y});
                        q.push({x + 1, y});
                    }
                }
                if(y+1<n && (heights[x][y+1]>=heights[x][y])){
                    if(pacific.find({x,y+1})==pacific.end()){
                        pacific.insert({x, y + 1});
                        q.push({x, y + 1});
                    }
                }
                if(y-1>=0 && (heights[x][y-1]>=heights[x][y])){
                    if(pacific.find({x,y-1})==pacific.end()){
                        pacific.insert({x, y - 1});
                        q.push({x, y - 1});
                    }
                }
            }
        }
        i = 0,j = 0;
        for (i = 0; i < m; i++)
        {
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty())
            {
                auto itr = q.front();
                q.pop();
                int x = itr.first;
                int y = itr.second;
                if (pacific.find({x, y}) == pacific.end())
                {
                    pacific.insert({x, y});
                }
                if (x - 1 >= 0 && (heights[x - 1][y] >= heights[x][y]))
                {
                    if (pacific.find({x - 1, y}) == pacific.end())
                    {
                        pacific.insert({x - 1, y});
                        q.push({x - 1, y});
                    }
                }
                if (x + 1 < m && (heights[x + 1][y] >= heights[x][y]))
                {
                    if (pacific.find({x + 1, y}) == pacific.end())
                    {
                        pacific.insert({x + 1, y});
                        q.push({x + 1, y});
                    }
                }
                if (y + 1 < n && (heights[x][y + 1] >= heights[x][y]))
                {
                    if (pacific.find({x, y + 1}) == pacific.end())
                    {
                        pacific.insert({x, y + 1});
                        q.push({x, y + 1});
                    }
                }
                if (y - 1 >= 0 && (heights[x][y - 1] >= heights[x][y]))
                {
                    if (pacific.find({x, y - 1}) == pacific.end())
                    {
                        pacific.insert({x, y - 1});
                        q.push({x, y - 1});
                    }
                }
            }
        }
        i = m - 1, j = 0;
        for (j = 0; j < n; j++)
        {
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty())
            {
                auto itr = q.front();
                q.pop();
                int x = itr.first;
                int y = itr.second;
                if (atlantic.find({x, y}) == atlantic.end())
                {
                    atlantic.insert({x, y});
                }
                if (x - 1 >= 0 && (heights[x - 1][y] >= heights[x][y]))
                {
                    if (atlantic.find({x - 1, y}) == atlantic.end())
                    {
                        atlantic.insert({x - 1, y});
                        q.push({x - 1, y});
                    }
                }
                if (x + 1 < m && (heights[x + 1][y] >= heights[x][y]))
                {
                    if (atlantic.find({x + 1, y}) == atlantic.end())
                    {
                        atlantic.insert({x + 1, y});
                        q.push({x + 1, y});
                    }
                }
                if (y + 1 < n && (heights[x][y + 1] >= heights[x][y]))
                {
                    if (atlantic.find({x, y + 1}) == atlantic.end())
                    {
                        atlantic.insert({x, y + 1});
                        q.push({x, y + 1});
                    }
                }
                if (y - 1 >= 0 && (heights[x][y - 1] >= heights[x][y]))
                {
                    if (atlantic.find({x, y - 1}) == atlantic.end())
                    {
                        atlantic.insert({x, y - 1});
                        q.push({x, y - 1});
                    }
                }
            }
        }
        i = 0, j = n - 1;
        for (i = 0; i < m; i++)
        {
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty())
            {
                auto itr = q.front();
                q.pop();
                int x = itr.first;
                int y = itr.second;
                if (atlantic.find({x, y}) == atlantic.end())
                {
                    atlantic.insert({x, y});
                }
                if (x - 1 >= 0 && (heights[x - 1][y] >= heights[x][y]))
                {
                    if (atlantic.find({x - 1, y}) == atlantic.end())
                    {
                        atlantic.insert({x - 1, y});
                        q.push({x - 1, y});
                    }
                }
                if (x + 1 < m && (heights[x + 1][y] >= heights[x][y]))
                {
                    if (atlantic.find({x + 1, y}) == atlantic.end())
                    {
                        atlantic.insert({x + 1, y});
                        q.push({x + 1, y});
                    }
                }
                if (y + 1 < n && (heights[x][y + 1] >= heights[x][y]))
                {
                    if (atlantic.find({x, y + 1}) == atlantic.end())
                    {
                        atlantic.insert({x, y + 1});
                        q.push({x, y + 1});
                    }
                }
                if (y - 1 >= 0 && (heights[x][y - 1] >= heights[x][y]))
                {
                    if (atlantic.find({x, y - 1}) == atlantic.end())
                    {
                        atlantic.insert({x, y - 1});
                        q.push({x, y - 1});
                    }
                }
            }
        }
        i = 0;
        set<pair<int,int>> intersect;
        set_intersection(pacific.begin(), pacific.end(), atlantic.begin(), atlantic.end(),std::inserter(intersect, intersect.begin()));
        for(auto itr:intersect){
            // cout << itr.first << " " << itr.second << endl;
            vector<int> temp;
            temp.push_back(itr.first);
            temp.push_back(itr.second);
            vect.push_back(temp);
        }
        return vect;
    }
};
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> heights(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> heights[i][j];
        }
    }
    vector<vector<int>> vect;
    Solution s;
    vect=s.pacificAtlantic(heights);
    // cout << vect.size() << endl;
    for(auto itr:vect){
        for(int x:itr){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}