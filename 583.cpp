// 583. Delete Operation for Two Strings
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

 

// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4

#include<bits/stdc++.h>
using namespace std;
int minDistance(string str1,string str2){
    int n = str1.length();
    int m = str2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= m;j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int lcs_len = dp[n][m];
    cout << "Number of deletion opertion : " << n - lcs_len << endl;
    cout << "Number of Insertion operation : " << m - lcs_len << endl;
    return n - lcs_len + m - lcs_len;
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    cout << minDistance(str1, str2) << endl;
    return 0;
}