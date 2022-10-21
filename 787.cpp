class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++)
        {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> price(n, 1e9);
        price[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while (!q.empty())
        {
            auto it = q.front();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();
            for (auto v : adj[node])
            {
                int adjNode = v.first;
                int edgeWeight = v.second;
                if (price[adjNode] > cost + edgeWeight && stop <= k)
                {
                    price[adjNode] = cost + edgeWeight;
                    q.push({stop + 1, {adjNode, price[adjNode]}});
                }
            }
        }
        if (price[dst] == 1e9)
            return -1;
        return price[dst];
    }
};