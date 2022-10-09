class Solution
{
public:
    bool dfs(int src, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &pathvis, vector<bool> &check)
    {
        vis[src] = true;
        pathvis[src] = true;
        for (int v : graph[src])
        {
            if (vis[v] == false)
            {
                if (dfs(v, graph, vis, pathvis, check) == true)
                    return true;
            }
            else if (pathvis[v] == true)
                return true;
        }
        pathvis[src] = false;
        check[src] = true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int v = graph.size();
        vector<bool> vis(v, false);
        vector<bool> pathvis(v, false);
        vector<bool> check(v, false);
        for (int i = 0; i < v; i++)
        {
            dfs(i, graph, vis, pathvis, check);
        }
        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            if (check[i] == true)
                ans.push_back(i);
        }
        return ans;
    }
};