#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        int dr = entrance[0];
        int dc = entrance[1];
        maze[dr][dc] = '+';
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && maze[i][j] == '.')
                {
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<int> ans;

        while (!q.empty())
        {
            auto itr = q.front();
            q.pop();
            int r = itr.first.first;
            int c = itr.first.second;
            int d = itr.second;
            int drow[] = {+1, 0, -1, 0};
            int dcol[] = {0, +1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if (nr == dr && nc == dc)
                {
                    ans.push_back(d + 1);
                }
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && maze[nr][nc] == '.')
                {
                    q.push({{nr, nc}, d + 1});
                    vis[nr][nc] = true;
                }
            }
        }
        sort(ans.begin(), ans.end());
        // for(auto itr:ans){
        //     cout<<itr<<' ';
        // }
        return ans.size() == 0 ? -1 : ans[0];
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int m,n;
        cin >> m >> n;
        vvi maze(m, vi(n));
        FOR(i,m){
            FOR(j,n){
                cin >> maze[i][j];
            }
        }
    }
    return 0;
}
