class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        effort[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            int e = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            int nrow[] = {-1, 0, +1, 0};
            int ncol[] = {0, +1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int row = r + nrow[i];
                int col = c + ncol[i];
                if (row >= 0 && row < n && col >= 0 && col < m)
                {
                    // effort[row][col]=max();
                    if (effort[row][col] > max(e, abs(heights[row][col] - heights[r][c])))
                    {
                        effort[row][col] = max(e, abs(heights[row][col] - heights[r][c]));
                        pq.push({effort[row][col], {row, col}});
                    }
                }
            }
        }
        return effort[n - 1][m - 1];
    }
};