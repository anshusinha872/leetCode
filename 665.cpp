// 665. Non - decreasing Array
// Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

// Example 1:

// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
// Example 2:

// Input: nums = [4,2,1]
// Output: false
// Explanation: You can't get a non-decreasing array by modify at most one element.

#include<bits/stdc++.h>
    using namespace std;
bool checkPossibility(vector<int> &nums){

    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count++;
            if (count >= 2)
            {
                return false;
            }
            if (i - 1 >= 0 && nums[i - 1] <= nums[i + 1])
            {
                nums[i] = nums[i + 1];
            }
            else if (i - 1 >= 0 && nums[i - 1] > nums[i + 1])
            {
                nums[i + 1] = nums[i];
            }
            else
            {
                nums[i] = nums[i + 1];
            }
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << checkPossibility(nums) << endl;
    return 0;
}