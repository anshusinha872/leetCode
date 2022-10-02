#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        long long res = INT_MAX;
        long long sum = 0;
        deque<pair<long long, long long>> dq;
        for (long long i = 0; i < nums.size();i++){
            sum += nums[i];
            if(sum>=k){
                res = min(res, i + 1);
            }
            pair<long long, long long> curr = {INT_MIN, INT_MIN};
            while(!dq.empty() && sum-dq.front().first>=k){
                curr = dq.front();
                dq.pop_front();
            }
            if(curr.second!=INT_MIN){
                res = min(res, i - curr.second);
            }
            while(!dq.empty() && dq.back().second>=sum){
                dq.pop_back();
            }
            dq.push_back({sum, i});
        }
        return res == INT_MAX ? -1 : res;
    }
};
int main()
{
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    Solution S;
    cout << S.shortestSubarray(nums, k) << '\n';
    return 0;
}