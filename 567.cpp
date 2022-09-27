class Solution
{
    void BFS(vector<vector<int>> &graph, int src, vector<bool> &visited)
    {
        visited[src] = true;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : graph[u])
            {
                if (visited[v] == false)
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int v = isConnected.size();
        vector<vector<int>> graph(v);
        for (int i = 0; i < v; i++)
        {
            for (int j = i; j < v; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<bool> visited(v, false);
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == false)
            {
                count++;
                BFS(graph, i, visited);
            }
        }
        return count;
    }
};