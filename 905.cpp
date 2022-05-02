// 905. Sort Array By Parity
//     Given an integer array nums,
//     move all the even integers at the beginning of the array followed by all the odd integers.

//     Return any array that satisfies this condition.

//     Example 1 :

//     Input : nums = [ 3, 1, 2, 4 ] Output : [ 2, 4, 3, 1 ] Explanation : The outputs[4, 2, 3, 1],
//             [ 2, 4, 1, 3 ], and[ 4, 2, 1, 3 ] would also be accepted.Example 2 :

//     Input : nums = [0] Output : [0]
#include<bits/stdc++.h>
                                using namespace std;
vector<int> sortArrayByParity(vector<int> &nums){
    int i = 0;
    int j = nums.size() - 1;
    while(i<=j){
        if(nums[i]%2!=0){
            swap(nums[i], nums[j]);
            j--;
        }
        if(nums[i]%2==0){
            i++;
        }
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
    nums = sortArrayByParity(nums);
    for(int x:nums){
        cout << x << " ";
    }
    return 0;
}