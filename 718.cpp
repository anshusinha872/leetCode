// 718. Maximum Length of Repeated Subarray
//     Given two integer arrays nums1 and nums2,
//     return the maximum length of a subarray that appears in both arrays.

//            Example 1 :

//     Input : nums1 = [ 1, 2, 3, 2, 1 ],
//             nums2 = [ 3, 2, 1, 4, 7 ] Output : 3 Explanation : The repeated subarray with maximum length is[3, 2, 1].Example 2 :

//     Input : nums1 = [ 0, 0, 0, 0, 0 ],
//             nums2 = [ 0, 0, 0, 0, 0 ] Output : 5

#include<bits/stdc++.h>
            using namespace std;
int findLength(vector<int> &nums1, vector<int> &nums2){
    int n = nums1.size();
    int m = nums2.size();
    int length = 0;
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= m;j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(nums1[i-1]==nums2[j-1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                length = max(length, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return length;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums1, nums2;
    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        nums1.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums2.push_back(temp);
    }
    cout << findLength(nums1, nums2) << endl;
    return 0;
}