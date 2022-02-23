// 312. Burst Balloons
//     You are given n balloons,
//     indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums.You are asked to burst all the balloons.

//                           If you burst the ith balloon,
//     you will get nums[i - 1] * nums[i] * nums[i + 1] coins.If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

//                                                                                                               Return the maximum coins you can collect by bursting the balloons wisely.

//                                                                                                               Example 1 :

//     Input : nums = [ 3, 1, 5, 8 ] Output : 167 Explanation : nums = [ 3, 1, 5, 8 ]-- > [ 3, 5, 8 ]-- > [ 3, 8 ]-- > [8]-- > [] coins = 3 * 1 * 5 + 3 * 5 * 8 + 1 * 3 * 8 + 1 * 8 * 1 = 167 Example 2 :

//     Input : nums = [ 1, 5 ] Output : 10

#include<bits/stdc++.h>
            using namespace std;
int maxCoins(int arr[],int n){
    vector<int> vect;
    vect.push_back(1);
    for (int i = 0; i < n;i++)
        vect.push_back(arr[i]);
    vect.push_back(1);
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n;i++)
        dp[i][i] = vect[i - 1] * vect[i] * vect[i + 1];
    for (int l = 2; l <= n;l++){
        for (int i = 1; i + l - 1 <= n;i++){
            int j = i + l - 1;
            for (int k = i; k <= j;k++){
                int left = ((i == k )? 0 : dp[i][k - 1]);
                int right = ((j == k) ? 0 : dp[k + 1][j]);
                int ans = vect[i - 1] * vect[k] * vect[j + 1];
                dp[i][j] = max(dp[i][j], left + right + ans);
            }
        }
    }
    return dp[1][n];
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    cout << maxCoins(arr, n) << endl;
    return 0;
}