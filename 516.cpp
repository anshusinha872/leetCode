// 516. Longest Palindromic Subsequence
//     Given a string s,
//     find the longest palindromic subsequence's length in s.

//         A subsequence is a sequence that can be derived from another sequence by deleting some or
//         no elements without changing the order of the remaining elements.

//         Example 1 :

//     Input : s = "bbbab" Output : 4 Explanation : One possible longest palindromic subsequence is "bbbb".Example 2 :

//     Input : s = "cbbd" Output : 2 Explanation : One possible longest palindromic subsequence is "bb".

#include<bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string str1){
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    int n = str1.length();
    int m = str1.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= m;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            }
            else if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
} 
int main()
{
    string str1;
    cin >> str1;
    cout << longestPalindromeSubseq(str1) << endl;
    return 0;
}