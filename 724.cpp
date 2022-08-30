// 724. Find Pivot Index
//     Given an array of integers nums,
//     calculate the pivot index of this array.

//     The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

//     If the index is on the left edge of the array,
//     then the left sum is 0 because there are no elements to the left.This also applies to the right edge of the array.

//     Return the leftmost pivot index.If no such index exists,
//     return -1.
#include<bits/stdc++.h>
    using namespace std;
int pivotIndex(vector<int> &nums)
{
    vector<int> prefixSum(nums.size() + 1);
    prefixSum[0] = 0;
    for (int i = 1; i <= nums.size(); i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int leftSum = prefixSum[i];
        int rightSum = prefixSum[nums.size()] - prefixSum[i] - nums[i];
        if (leftSum == rightSum)
            return i;
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << pivotIndex(nums) << endl;
    return 0;
}