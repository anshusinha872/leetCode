#include<bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int> &nums){
    map<int, int> mp1;
    map<int, int> mp2;
    for (int i = 0; i < nums.size();i++){
        if(nums[i]>=0){
            mp1.insert({i,nums[i]});
        }
        else{
            mp2.insert({i,nums[i]});
        }
    }
    int i = 0;
    for(auto itr:mp1){
        nums[i] = itr.second;
        i += 2;
    }
    i = 1;
    for(auto itr:mp2){
        nums[i] = itr.second;
        i += 2;
    }
        return nums;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    nums = rearrangeArray(nums);
    for(int x:nums){
        cout << x << " ";
    }
    return 0;
}