class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        map<int, int> inDegree;
        for (int i = 0; i < n; i++)
        {
            for (int v : graph[i])
            {
                inDegree[v]++;
            }
        }
        // for(auto itr:inDegree){
        //     cout<<itr.first<<' '<<itr.second<<'\n';
        // }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};