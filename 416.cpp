// 416. Partition Equal Subset Sum
// Given a non - empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

//                                                                   Example 1 :

//     Input : nums = [ 1, 5, 11, 5 ] Output : true Explanation : The array can be partitioned as[1, 5, 5] and[11].Example 2 :

//     Input : nums = [ 1, 2, 3, 5 ] Output : false Explanation : The array cannot be partitioned into equal sum subsets.

//                                                                Constraints :

//                                                                1 <= nums.length <= 200 1 <= nums[i] <= 100

#include<bits/stdc++.h>
using namespace std;
static bool dp[200][2000];
bool subSet_sum(vector<int> &nums,int n,int sum){
    for (int i = 1; i <= sum;i++)
        dp[0][i] = false;
    for (int i = 0; i <= n;i++)
        dp[i][0] = true;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= sum;j++){
            if(j>=nums[i-1]){
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
bool canPartition(vector<int> &nums){
    int sum = 0;
    for(int itr:nums)
        sum += itr;
    if(sum%2!=0)
        return false;
    sum = sum / 2;
    int n = nums.size();
    return subSet_sum(nums, n, sum);
}
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << canPartition(nums);
    return 0;
}