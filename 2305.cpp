// 2305. Fair Distribution of Cookies
//     You are given an integer array cookies,
//     where cookies[i] denotes the number of cookies in the ith bag.You are also given an integer k that denotes the number of children to distribute all the bags of cookies to.All the cookies in the same bag must go to the same child and cannot be split up.

//     The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

//     Return the minimum unfairness of all distributions.

//     Example 1 :

//     Input : cookies = [ 8, 15, 10, 20, 8 ],
//             k = 2 Output : 31 Explanation : One optimal distribution is[8, 15, 8] and [ 10, 20 ] - The 1st child receives[8, 15, 8] which has a total of 8 + 15 + 8 = 31 cookies.- The 2nd child receives[10, 20] which has a total of 10 + 20 = 30 cookies.The unfairness of the distribution is max(31, 30) = 31. It can be shown that there is no distribution with an unfairness less than 31. Example 2 :

//     Input : cookies = [ 6, 1, 3, 2, 2, 4, 1, 2 ],
//             k = 3 Output : 7 Explanation : One optimal distribution is[6, 1], [ 3, 2, 2 ], and[ 4, 1, 2 ] - The 1st child receives[6, 1] which has a total of 6 + 1 = 7 cookies.- The 2nd child receives[3, 2, 2] which has a total of 3 + 2 + 2 = 7 cookies.- The 3rd child receives[4, 1, 2] which has a total of 4 + 1 + 2 = 7 cookies.The unfairness of the distribution is max(7, 7, 7) = 7. It can be shown that there is no distribution with an unfairness less than 7.

#include<bits/stdc++.h>
                                                                                           using namespace std;
int ans = INT_MAX;
void solve(vector<int> &vect,int start,vector<int> &cookies,int k){
    if(start==cookies.size()){
        int res = INT_MIN;
        for(int x:vect){
            res = max(res, x);
        }
        ans = min(res, ans);
        return;
    }
    for (int i = 0; i < k;i++){
        vect[i] += cookies[start];
        solve(vect, start + 1, cookies, k);
        vect[i] -= cookies[start];
        if(vect[i]==0)
            break;
    }
}
int distributeCookies(vector<int> &cookies, int k){
    int n = cookies.size();
    vector<int> vect(k, 0);
    solve(vect, 0, cookies, k);
    return ans;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> cookies(n);
    for (int i = 0; i < n;i++){
        cin >> cookies[i];
    }
    cout << distributeCookies(cookies, k) << endl;
    return 0;
}