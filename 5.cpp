// 5. Longest Palindromic Substring
//     Given a string s,
//     return the longest palindromic substring in s.

//            Example 1 :

//     Input : s = "babad" Output : "bab" Explanation : "aba" is also a valid answer.Example 2 :

//     Input : s = "cbbd" Output : "bb"

//                                 Constraints :

//                                 1 <= s.length <= 1000 s consist of only digits and
//                 English letters.

#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s){
    int n = s.length();
    bool dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    int start = 0;
    int max_len = 1;
    for (int i = 0; i <= n;i++){
        dp[i][i] = true;
    }
    for (int i = 0; i < n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i + 1] = true;
        }
    }
    for (int k = 3; k <= n;k++){
        for (int i = 0; i + k - 1 < n;i++){
            int j = i + k - 1;
            if(s[i]==s[j]&& dp[i+1][j-1]==true){
                dp[i][j] = true;
                if(k>max_len){
                    max_len = k;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, max_len);
}
int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}