// 238. Product of Array Except Self
//     Given an integer array nums,
//     return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

//            The product of any prefix or
//            suffix of nums is guaranteed to fit in a 32 - bit integer.

//                                                          You must write an algorithm that runs in
//                                                          O(n)
// time and without using the division operation.

//     Example 1 :

//     Input : nums = [ 1, 2, 3, 4 ] Output : [ 24, 12, 8, 6 ] Example 2 :

//     Input : nums = [ -1, 1, 0, -3, 3 ] Output : [ 0, 0, 9, 0, 0 ]

#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
    vector<int> prefix(n), suffix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n;i++){
        prefix[i] = prefix[i - 1] * nums[i];
    }
    suffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0;i--){
        suffix[i] = suffix[i + 1] * nums[i];
    }
    vector<int> answer;

    for (int i = 0; i < n;i++){
        if(i==0){
            answer.push_back(suffix[i + 1]);
        }
        else if(i==n-1){
            answer.push_back(prefix[i - 1]);
        }
        else{
            answer.push_back(prefix[i - 1] * suffix[i + 1]);
        }
    }
    return answer;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    vector<int> ans = productExceptSelf(nums);
    for(auto itr:ans)
        cout << itr << " ";
    return 0;
}