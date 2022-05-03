// 581. Shortest Unsorted Continuous Subarray
//     Given an integer array nums,
//     you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

//                                                                                                      Return the shortest such subarray and output its length.

//                                                                                                      Example 1 :

//     Input : nums = [ 2, 6, 4, 8, 10, 9, 15 ] Output : 5 Explanation : You need to sort[6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.Example 2 :

//     Input : nums = [ 1, 2, 3, 4 ] Output : 0 Example 3 :

//     Input : nums = [1] Output : 0

#include<bits/stdc++.h>
            using namespace std;
int findUnsortedSubarray(vector<int> &nums){
    int end = -1;
    int max = nums[0];
    for (int i = 1; i < nums.size();i++){
        if(nums[i]<max){
            end = i;
        }
        else{
            max = nums[i];
        }
    }
    int start = 0;
    int min = nums[nums.size() - 1];
    for (int i = nums.size() - 1; i >= 0;i--){
        if(nums[i]>min){
            start = i;
        }
        else{
            min = nums[i];
        }
    }
    return end - start + 1;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << findUnsortedSubarray(nums) << endl;
    return 0;
}