// 560. Subarray Sum Equals K
//     Given an array of integers nums and an integer k,
//     return the total number of subarrays whose sum equals to k.

//            Example 1 :

//     Input : nums = [ 1, 1, 1 ],
//             k = 2 Output : 2 Example 2 :

//     Input : nums = [ 1, 2, 3 ],
//             k = 3 Output : 2

//                 Constraints :

//                 1 <= nums.length <= 2 * 104 - 1000 <=
//                 nums[i] <= 1000 - 107 <= k <= 107
#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k){
    unordered_map<int, int> mp;
    vector<int> prefix(nums.size());
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size();i++){
        prefix[i] = nums[i] + prefix[i - 1];
    }
    int count = 0;
    for (int i = 0; i < nums.size();i++){
        if(prefix[i]==k){
            count++;
        }
        if(mp.find(prefix[i]-k)!=mp.end()){
            count += mp[prefix[i] - k];
        }
        mp[prefix[i]]++;
    }
    return count;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << subarraySum(nums, k) << endl;
    return 0;
}