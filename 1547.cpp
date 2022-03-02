#include<bits/stdc++.h>
using namespace std;
int minCost(int n,vector<int> cuts){
    sort(cuts.begin(), cuts.end());
    vector<int> cuts_arr(n,-1);
    for (int i = 0; i < cuts.size();i++){
        cuts_arr[cuts[i]] = cuts[i];
    }
    for(auto x:cuts_arr)
        cout << x << " ";
    int si = 0, ei = n;
    vector<int> price(n, 0);
    for (int i = si; i < ei; i++)
    {
        if(cuts_arr[i]==1){
            price[i] = ei - si;
            si = i;
        }
    }
    cout <<" price "<< endl;
    for(int x:price)
        cout << x << " ";
    
    cout << endl;
    int max_len = n;
    int dp[max_len + 1][n + 1];
    for (int i = 0; i <= n;i++)
        dp[i][0] = INT_MAX;
    for (int i = 0; i <= max_len;i++)
        dp[0][i] = INT_MAX;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= max_len;j++){
            if(max_len>=i&& cuts_arr[i]!=-1){
                dp[i][j] = min(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= max_len;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        return dp[n][n];
}
int main(){
    int n;
    cin >> n;
    vector<int> cuts{1, 3, 4, 5};
    // int cuts[1, 3, 4, 5];
    cout << minCost(n, cuts) << endl;
    return 0;
}