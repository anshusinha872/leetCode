class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> time(n, INT_MAX);
        time[k - 1] = 0;
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < times.size(); i++)
        {
            graph[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            for (auto it : graph[node])
            {
                int edgeTime = it.second;
                int adjNode = it.first;
                if (t + edgeTime < time[adjNode])
                {
                    time[adjNode] = t + edgeTime;
                    pq.push({time[adjNode], adjNode});
                }
            }
        }
        int minTime = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            minTime = max(minTime, time[i]);
        }
        // for(int x:time){
        //     cout<<x<<' ';
        // }
        return minTime == INT_MAX ? -1 : minTime;
    }
};