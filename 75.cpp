// 75. Sort Colors
//     Medium

//     8942

//     389

//     Add to List

//         Share
//             Given an array nums with n objects colored red,
//     white, or blue, sort them in - place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

//                                                                                                                                       We will use the integers 0,
//     1, and2 to represent the color red, white, and blue, respectively.

//                                                          You must solve this problem without using the library's sort function.

//                                                          Example 1 :

//     Input : nums = [ 2, 0, 2, 1, 1, 0 ] Output : [ 0, 0, 1, 1, 2, 2 ] Example 2 :

//     Input : nums = [ 2, 0, 1 ] Output : [ 0, 1, 2 ]

#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &nums){
    int low = 0, mid = 0, high = nums.size() - 1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1)
            mid++;
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
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
    sortColors(nums);
    for(auto x:nums)
        cout << x << " ";
    return 0;
}