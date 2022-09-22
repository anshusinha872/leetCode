#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }
        while (pq.size() >= 2)
        {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if (s1 != s2)
            {
                pq.push(abs(s1 - s2));
            }
        }
        if (pq.size() == 2)
        {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            return abs(s1 - s2);
        }
        if (pq.empty())
            return 0;
        return pq.top();
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n;i++){
        cin >> vect[i];
    }
    Solution s;
    cout << s.lastStoneWeight(vect) << '\n';
    return 0;
}