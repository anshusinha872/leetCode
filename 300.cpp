#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS_util(vector<int> &nums,int ind,int prev,vector<vector<int>> &dp){
    if(ind==nums.size())
        return 0;
    if(dp[ind][prev+1]!=-1)
        return dp[ind][prev + 1];
    int len = 0 + lengthOfLIS_util(nums, ind+1, prev,dp);
    if(prev == -1 || nums[ind]>nums[prev]){
        len = max(len, 1 + lengthOfLIS_util(nums, ind+1, ind,dp));
    }
    return dp[ind][prev + 1] = len;
}
int lengthOfLIS(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return lengthOfLIS_util(nums, 0, -1,dp);
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << lengthOfLIS(nums) << endl;
    return 0;
}