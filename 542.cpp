#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            auto itr = q.front();
            q.pop();
            int r = itr.first.first;
            int c = itr.first.second;
            int d = itr.second;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, -1, 0, 1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && mat[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, d + 1});
                    ans[nrow][ncol] = d + 1;
                    mat[nrow][ncol] = 0;
                }
            }
        }
        return ans;
    }
};
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> vect(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> vect[i][j];
        }
    }
    Solution s;
    vect=s.updateMatrix(vect);
    for(auto itr:vect){
        for(int x:itr){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}