// 2164. Sort Even and Odd Indices Independently
//         You are given a 0 -
//     indexed integer array nums.Rearrange the values of nums according to the following rules :

//     Sort the values at odd indices of nums in non -
//     increasing order.For example,
//     if nums = [ 4, 1, 2, 3 ] before this step, it becomes[4, 3, 2, 1] after.The values at odd indices 1 and 3 are sorted in non - increasing order.Sort the values at even indices of nums in non - decreasing order.For example, if nums = [ 4, 1, 2, 3 ] before this step, it becomes[2, 1, 4, 3] after.The values at even indices 0 and 2 are sorted in non - decreasing order.Return the array formed after rearranging the values of nums.

//                                                                                                                                                                                                                                                                                                                                                                  Example 1 :

//     Input : nums = [ 4, 1, 2, 3 ] Output : [ 2, 3, 4, 1 ] Explanation : First,
//        we sort the values present at odd indices(1 and 3) in non - increasing order.So, nums changes from[4, 1, 2, 3] to[4, 3, 2, 1].Next, we sort the values present at even indices(0 and 2) in non - decreasing order.So, nums changes from[4, 1, 2, 3] to[2, 3, 4, 1].Thus, the array formed after rearranging the values is[2, 3, 4, 1].Example 2 :

//     Input : nums = [ 2, 1 ] Output : [ 2, 1 ] Explanation : Since there is exactly one odd index and one even index,
//        no rearrangement of values takes place.The resultant array formed is[2, 1], which is the same as the initial array.
#include<bits/stdc++.h>
using namespace std;
vector<int> sortEvenOdd(vector<int> &nums){
    priority_queue<int> p_max;
    priority_queue<int, vector<int>,greater<int>> p_min;
    for (int i = 0; i < nums.size();i+=2){
        p_min.push(nums[i]);
    }
    for (int i = 1; i < nums.size();i+=2){
        p_max.push(nums[i]);
    }
    for (int i = 0; i < nums.size();i+=2){
        nums[i] = p_min.top();
        p_min.pop();
    }
    for (int i = 1; i < nums.size(); i += 2)
    {
        nums[i] = p_max.top();
        p_max.pop();
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
    nums = sortEvenOdd(nums);
    for(int x:nums){
        cout << x << " ";
    }
    return 0;
}