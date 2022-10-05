class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int src)
    {
        vis[src] = true;
        for (int i : graph[src])
            if (!vis[i])
                dfs(graph, vis, i);
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;
        vector<vector<int>> graph(n);
        for (int i = 0; i < connections.size(); i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> vis(n, false);
        int component = 0;
        for (int i = 0; i < n; i++)
            if (!vis[i])
            {
                dfs(graph, vis, i);
                component++;
            }
        return component - 1;
    }
};