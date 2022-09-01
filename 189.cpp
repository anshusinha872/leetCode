#include<bits/stdc++.h>
using namespace std;
void reverseUtil(vector<int> &nums,int i,int j){
    while(i<=j){
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}
void rotate(vector<int> &nums, int k){
    int n = nums.size();
    k = k % n;
    reverseUtil(nums, n - k, n - 1);
    reverseUtil(nums, 0, n - k - 1);
    reverseUtil(nums, 0, n - 1);
}
int main(){
    int n,k;
    cin >> n>>k;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    rotate(nums,k);
    cout << endl;
    for(int x:nums)
        cout << x << " ";
    return 0;
}