class Solution
{
public:
    void addEdge(vector<vector<int>> &graph, int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            addEdge(graph, u, v);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(source);
        vis[source] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == destination)
                return true;
            for (int v : graph[u])
            {
                if (vis[v] == false)
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};