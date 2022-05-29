#include<bits/stdc++.h>
using namespace std;

int minimumAverageDifference(vector<int> &nums){
    int n = nums.size();
    if(n==0){
        return 0;
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= n;i++){
        dp[i] = (((i - 1) * dp[i - 1] + nums[i-1]) / (i));
    }
    cout << endl;
    int res = INT_MAX;
    int index = 0;
    for (int i = 1; i < n-1;i++){
        int avg1 = dp[i + 1];
        int avg2 = (dp[n] * n - (i + 1) * dp[i + 1]) /(n-i-1);
        int temp= abs(int(avg1) -int(avg2));
        if(temp<res){
            res=temp;
            index = i;
        }
    }
    dp[n] < res ? index = n - 1 : index;
    return index;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << minimumAverageDifference(nums) << endl;
}