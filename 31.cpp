// 31. Next Permutation
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

#include<bits/stdc++.h>
    using namespace std;
void reverse(int i,int j,vector<int> &nums){
    int start = i, end = j;
    while(start<=end){
        int temp;
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
void nextPermutation(vector<int> &nums){
    bool flag = false;
    int n = nums.size();
    int k, l;
    for (k = n - 2; k >= 0;k--){
        if(nums[k]<nums[k+1]){
            flag = true;
            break;
        }
    }
    if(!flag){
        reverse(0,n-1,nums);
    }
    else{
        for (l = n - 1; l >= 0;l--){
            if(nums[l]>nums[k]){
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(k + 1, n - 1, nums);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    nextPermutation(nums);
    cout << "Next permutation : ";
    for(auto itr:nums){
        cout << itr << " ";
    }
    return 0;
}