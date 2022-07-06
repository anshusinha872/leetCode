// 410. Split Array Largest Sum
//         Given an array nums which consists of non -
//     negative integers and an integer m,
//     you can split the array into m non - empty continuous subarrays.

//                                          Write an algorithm to minimize the largest sum among these m subarrays.

//                                          Example 1 :

//     Input : nums = [ 7, 2, 5, 10, 8 ],
//             m = 2 Output : 18 Explanation : There are four ways to split nums into two subarrays.The best way is to split it into[7, 2, 5] and [ 10, 8 ],
//             where the largest sum among the two subarrays is only 18. Example 2 :

//     Input : nums = [ 1, 2, 3, 4, 5 ],
//             m = 2 Output : 9 Example 3 :

//     Input : nums = [ 1, 4, 4 ],
//             m = 3 Output : 4

//                 Constraints :

//                 1 <= nums.length <= 1000 0 <= nums[i] <= 106 1 <= m <= min(50, nums.length)
#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &nums,int m,int mid){

    int sum = 0;
    int res = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > mid)
        {
            res++;
            sum = nums[i];
        }
    }
    if (res <= m)
        return true;
    return false;
}
int splitArray(vector<int> &nums, int m){
    int lo = INT_MIN;
    int max_value = INT_MIN;
    int hi = 0;
    for (int x : nums)
    {
        lo = max(lo, x);
        hi += x;
        max_value = max(max_value, x);
    }
    if (m == 1)
    {
        return hi;
    }
    // hi =hi-lo;

    if (nums.size() == m)
    {
        return max_value;
    }
    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (isPossible(nums, m, mid) == true)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << splitArray(nums, m) << endl;
    return 0;
}