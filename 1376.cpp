#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int time = 0;
    // int maxTime=0;
    void bfs(vector<vector<int>> &graph, int src, vector<bool> &vis, vector<int> &informTime)
    {
        vis[src] = true;
        queue<int> q;
        q.push(src);
        map<int, int> mp;
        mp[src] = 0;
        while (!q.empty())
        {
            int u = q.front();
            int s = graph[u].size();
            for (int i = 0; i < s; i++)
            {
                q.push(graph[u][i]);
                mp[graph[u][i]] = mp[u] + informTime[u];
                time = max(time, mp[graph[u][i]]);
            }
            q.pop();
        }
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
        {
            if (headID == i)
            {
                continue;
            }
            // graph[i].push_back(manager[i]);
            graph[manager[i]].push_back(i);
        }
        vector<bool> vis(n, false);
        bfs(graph, headID, vis, informTime);
        return time;
    }
};
int main()
{
    int headId;
    cin >> headId;
    int n;
    cin >> n;
    vector<int> manager(n);
    for (int i = 0; i < n; i++)
    {
        cin >> manager[i];
    }
    vector<int> informTime(n);
    for (int i = 0; i < n; i++)
    {
        cin >> informTime[i];
    }
    Solution s;
    cout << s.numOfMinutes(n, headId, manager, informTime) << '\n';
    return 0;
}