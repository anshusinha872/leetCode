// 322. Coin Change
//     You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

//     Return the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any combination of the coins,
//     return -1.

//             You may assume that you have an infinite number of each kind of coin.

//             Example 1 :

//     Input : coins = [ 1, 2, 5 ],
//             amount = 11 Output : 3 Explanation : 11 = 5 + 5 + 1 Example 2 :

//     Input : coins = [2],
//             amount = 3 Output : -1 Example 3 :

//     Input : coins = [1],
//             amount = 0 Output : 0

#include<bits/stdc++.h>
using namespace std;
// int coinChange(int sum,int n,int coins[]){
//     if(sum==0)
//         return 0;
//     int ans = INT_MAX;
//     for (int i = 0; i < n;i++){
//         if(coins[i]<=sum){
//             int min_ans = coinChange(sum - coins[i], n, coins);
//             if(min_ans!=INT_MAX && min_ans+1<ans)
//                 ans = min_ans + 1;
//         }
//     }
//     return ans;
// }
int coinChange(int sum,int n,vector<int> coins){
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= sum;i++)
        dp[0][i] = 1e5;
    for (int i = 0; i <= n;i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= sum;j++){
            if(coins[i-1]<=j){
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum]>1e4?-1:dp[n][sum];
}
int main(){
    // int coins[] = {2,5,10,1};
    vector<int> coins{186,419,83,408};
    int n = 4;
    int sum = 6249;
    cout << coinChange(sum, n, coins) << endl;
    return 0;
}