// 283. Move Zeroes
//     Given an integer array nums,
//     move all 0's to the end of it while maintaining the relative order of the non - zero elements.

//                                                                                     Note that you must do this in -
//         place without making a copy of the array.

//         Example 1 :

//     Input : nums = [ 0, 1, 0, 3, 12 ] Output : [ 1, 3, 12, 0, 0 ] Example 2 :

//     Input : nums = [0] Output : [0]

#include<bits/stdc++.h>
                                using namespace std;
void moveZeroes(vector<int> &nums){
    int j = -1;
    for (int i = 0; i < nums.size();i++){
        if(nums[i]!=0){
            swap(nums[++j], nums[i]);
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    moveZeroes(nums);
    return 0;
}