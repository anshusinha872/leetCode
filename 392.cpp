#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t)
{
    int n = s.length();
    int m = t.length();
    int dp[n + 1][m + 1];
    // memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n;i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m;j++)
        dp[0][j] = 0;
    
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= m;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        if (dp[n][m] == s.length())
            return true;
    return false;
}
int main(){
    string s, t;
    cin >> s >> t;
    cout << isSubsequence(s, t) << endl;
    return 0;
}