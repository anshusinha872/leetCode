// 169. Majority Element
//     Given an array nums of size n,
//     return the majority element.

//                The majority element is the element that appears more than ⌊n /
//                2⌋ times.You may assume that the majority element always exists in the array.

//                Example 1 :

//     Input : nums = [ 3, 2, 3 ] Output : 3 Example 2 :

//     Input : nums = [ 2, 2, 1, 1, 1, 2, 2 ] Output : 2

#include<bits/stdc++.h>
            using namespace std;
int majorityElement(vector<int> &nums){
    int res = 0;
    int count = 1;
    for (int i = 1; i < nums.size();i++){
        if(nums[i]==nums[res]){
            count++;
        }
        else
            count--;
        if(count==0){
            res = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < nums.size();i++){
        if(nums[i]==nums[res]){
            count++;
        }
        if(count<nums.size()/2){
            return -1;
        }
    }
    return nums[res];
} 
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << majorityElement(nums) << endl;
    return 0;
}