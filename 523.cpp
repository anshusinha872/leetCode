#include<bits/stdc++.h>
using namespace std;
bool checkSubarraySum(vector<int> &nums, int k){
    int n = nums.size();
    if(k>n){
        return false;
    }
    int sum = 0;
    int i = 0;
    for (; i < k; i++)
    {
        sum += nums[i];
    }
    while(i<n){
        if(sum%k==0){
            return true;
        }
        else if()
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << checkSubarraySum(nums, k) << endl;
    return 0;
}