// 934. Shortest Bridge
//         You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

//     An island is a 4 -
//     directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

//     You may change 0's to 1's to connect the two islands to form one island.

//     Return the smallest number of 0's you must flip to connect the two islands.

//     Example 1 :

//     Input : grid = [ [ 0, 1 ], [ 1, 0 ] ] Output : 1 Example 2 :

//     Input : grid = [ [ 0, 1, 0 ], [ 0, 0, 0 ], [ 0, 0, 1 ] ] Output : 2 Example 3 :

//     Input : grid = [ [ 1, 1, 1, 1, 1 ], [ 1, 0, 0, 0, 1 ], [ 1, 0, 1, 0, 1 ], [ 1, 0, 0, 0, 1 ], [ 1, 1, 1, 1, 1 ] ] Output : 1
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
    queue<pair<int, int>> markCell(vector<vector<int>> &grid, int i, int j)
    {
        queue<pair<int, int>> q;
        queue<pair<int, int>> temp;
        int n = grid.size();
        grid[i][j] = 2;
        q.push({i, j});
        temp.push({i, j});
        while (!q.empty())
        {
            auto itr = q.front();
            q.pop();
            int x = itr.first;
            int y = itr.second;
            if (x - 1 >= 0 && grid[x - 1][y] == 1)
            {
                q.push({x - 1, y});
                temp.push({x - 1, y});
                grid[x - 1][y] = 2;
            }
            if (x + 1 < n && grid[x + 1][y] == 1)
            {
                q.push({x + 1, y});
                temp.push({x + 1, y});
                grid[x + 1][y] = 2;
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                q.push({x, y - 1});
                temp.push({x, y - 1});
                grid[x][y - 1] = 2;
            }
            if (y + 1 < n && grid[x][y + 1] == 1)
            {
                q.push({x, y + 1});
                temp.push({x, y + 1});
                grid[x][y + 1] = 2;
            }
        }
        return temp;
    }
    int shortestBridge(vector<vector<int>> &grid, queue<pair<int, int>> &q, int i, int j)
    {
        int n = grid.size();
        while (!q.empty())
        {
            auto itr = q.front();
            q.pop();
            int x = itr.first;
            int y = itr.second;
            if (x - 1 >= 0)
            {
                if (grid[x - 1][y] == 1)
                {
                    return grid[x][y] - 2;
                }
                if (grid[x - 1][y] == 0)
                {
                    grid[x - 1][y] = grid[x][y] + 1;
                    q.push({x - 1, y});
                }
            }
            if (x + 1 < n)
            {
                if (grid[x + 1][y] == 1)
                {
                    return grid[x][y] - 2;
                }
                if (grid[x + 1][y] == 0)
                {
                    q.push({x + 1, y});
                    grid[x + 1][y] = grid[x][y] + 1;
                }
            }
            if (y - 1 >= 0)
            {
                if (grid[x][y - 1] == 1)
                {
                    return grid[x][y] - 2;
                }
                if (grid[x][y - 1] == 0)
                {
                    q.push({x, y - 1});
                    grid[x][y - 1] = grid[x][y] + 1;
                }
            }
            if (y + 1 < n)
            {
                if (grid[x][y + 1] == 1)
                {
                    return grid[x][y] - 2;
                }
                if (grid[x][y + 1] == 0)
                {
                    q.push({x, y + 1});
                    grid[x][y + 1] = grid[x][y] + 1;
                }
            }
        }
        return -1;
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    // grid[i][j] = 2;
                    queue<pair<int, int>> q;
                    q = markCell(grid, i, j);
                    return shortestBridge(grid, q, i, j);
                }
            }
        }
        return -1;
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
        int N;
        cin >> N;
        vvi grid(N);
        FOR(i, N)
            FOR(j, N)
                cin >> grid[i][j];
        Solution S;
        cout << S.shortestBridge(grid) << endl;
    }
    return 0;
}
