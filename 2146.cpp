#include<bits/stdc++.h>
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
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<pair<pair<int, int>, pair<int, int>>> vect;
        queue<pair<pair<int, int>, int>> q;
        q.push({{start[0], start[1]}, 0});
        map<pair<int, int>, bool> visited;
        // visited[{start[0], start[1]}] = false;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto itr = q.front();
                q.pop();
                pair<int, int> index = itr.first;
                int x = index.first;
                int y = index.second;
                int dist = itr.second;
                if (!visited[{x, y}] && grid[x][y] != 0)
                {
                    if (grid[x][y] <= pricing[1] && grid[x][y] >= pricing[0])
                    {
                        vect.push_back({{dist, grid[x][y]}, {x, y}});
                    }
                    visited[{x, y}] = true;
                }
                if ((x - 1 >= 0 && !visited[{x - 1, y}]) && grid[x - 1][y] != 0)
                {
                    if (grid[x - 1][y] <= pricing[1] && grid[x - 1][y] >= pricing[0])
                    {
                        vect.push_back({{dist + 1, grid[x - 1][y]}, {x - 1, y}});
                    }
                    visited[{x - 1, y}] = true;
                    q.push({{x - 1, y}, dist + 1});
                }
                if ((x + 1 < row && !visited[{x + 1, y}]) && grid[x + 1][y] != 0)
                {
                    if (grid[x + 1][y] <= pricing[1] && grid[x + 1][y] >= pricing[0])
                    {
                        vect.push_back({{dist + 1, grid[x + 1][y]}, {x + 1, y}});
                    }
                    visited[{x + 1, y}] = true;
                    q.push({{x + 1, y}, dist + 1});
                }
                if ((y - 1 >= 0 && !visited[{x, y - 1}]) && grid[x][y - 1] != 0)
                {
                    if (grid[x][y - 1] <= pricing[1] && grid[x][y - 1] >= pricing[0])
                    {
                        vect.push_back({{dist + 1, grid[x][y - 1]}, {x, y - 1}});
                    }
                    visited[{x, y - 1}] = true;
                    q.push({{x, y - 1}, dist + 1});
                }
                if ((y + 1 < col && !visited[{x, y + 1}]) && grid[x][y + 1] != 0)
                {
                    if (grid[x][y + 1] <= pricing[1] && grid[x][y + 1] >= pricing[0])
                    {
                        vect.push_back({{dist + 1, grid[x][y + 1]}, {x, y + 1}});
                    }
                    visited[{x, y + 1}] = true;
                    q.push({{x, y + 1}, dist + 1});
                }
            }
        }
        sort(vect.begin(), vect.end());
        vector<vector<int>> ans;
        for (int i = 0; i < min(int(k), int(vect.size())); i++)
        {
            ans.push_back({vect[i].second.first, vect[i].second.second});
        }
        return ans;
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
        int M,N;
        cin >> M>>N;
        vvi grid(M, vi(N));
        FOR(i, M)
        {
            FOR(j, N)
            {
                cin >> grid[i][j];
            }
        }
        vi pricing(2);
        FOR(i, 2)
        {
            cin >> pricing[i];
        }
        vi start(2);
        FOR(i, 2)
        {
            cin >> start[i];
        }
        Solution S;
        vvi ans = S.highestRankedKItems(grid, pricing, start, 2);
    }
    return 0;
}
