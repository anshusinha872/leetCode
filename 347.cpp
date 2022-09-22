#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
class Solution
{
public:
    static bool myCmp(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if (p1.second > p2.second)
            return true;
        return false;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;
        for (int x : nums)
        {
            mp[x]++;
        }
        vector<pair<int, int>> vect;
        for (auto itr : mp)
        {
            vect.push_back({itr.first, itr.second});
        }
        sort(vect.begin(), vect.end(), myCmp);
        vector<int> ans;
        for (int i = 0; i < k && i < vect.size(); i++)
        {
            ans.push_back(vect[i].first);
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n;i++){
            cin >> nums[i];
        }
        int k;
        cin >> k;
        Solution s;
        s.topKFrequent(nums, k);
    }
    return 0;
}
