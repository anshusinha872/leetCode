// 887. Super Egg Drop
//         You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

//     You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break,
//     and any egg dropped at or below floor f will not break.

//                               Each move,
//     you may take an unbroken egg and drop it from any floor x(where 1 <= x <= n).If the egg breaks, you can no longer use it.However, if the egg does not break, you may reuse it in future moves.

//                                                                                                                                                                  Return the minimum number of moves that you need to determine with certainty what the value of f is.

//                                                                                                                                                                  Example 1 :

//     Input : k = 1,
//             n = 2 Output : 2 Explanation : Drop the egg from floor 1. If it breaks, we know that f = 0. Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1. If it does not break, then we know f = 2. Hence, we need at minimum 2 moves to determine with certainty what the value of f is.Example 2 :

//     Input : k = 2,
//             n = 6 Output : 3 Example 3 :

//     Input : k = 3,
//             n = 14 Output : 4

#include<bits/stdc++.h>
using namespace std;
static int dp[101][10000+1];
int superEggDrop(int k,int n){
    if(n==0 ||n==1){
        dp[k][n] = n;
        return n;
    }
    if(k==1){
        dp[k][n] = n;
        return dp[k][n];
    }
    if(dp[k][n]!=-1){
        return dp[k][n];
    }
    else{
        int l = 1, h = n;
        int min_ans = INT_MAX;
        int left, right;
        while(l<=h){
            int mid = l + (h - l) / 2;
            if(dp[k-1][mid-1]!=-1){
                left = dp[k - 1][mid - 1];
            }
            else
                left = superEggDrop(k - 1, mid - 1);
            if(dp[k][n-mid]!=-1){
                right = dp[k][n - mid];
            }
            else{
                right = superEggDrop(k, n - mid);
            }
            int temp = 1 + max(left, right);
            min_ans = min(min_ans, temp);
            if(left>right){
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        dp[k][n] = min_ans;
    }
    return dp[k][n];
}
//most optimized

// int superEggDrop(int K, int N)
// {
//     vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
//     int m = 0;
//     while (dp[m][K] < N)
//     {
//         m++;
//         for (int k = 1; k <= K; ++k)
//             dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
//     }
//     return m;
// }
int main(){
    int k, n;
    cin >> k >> n;
    memset(dp, -1, sizeof(dp));
    cout << superEggDrop(k, n) << endl;
    return 0;
}