// 922. Sort Array By Parity II
//     Given an array of integers nums,
//     half of the integers in nums are odd, and the other half are even.

//                                               Sort the array so that whenever nums[i] is odd,
//     i is odd, and whenever nums[i] is even, i is even.

//                                             Return any answer array that satisfies this condition.

//                                             Example 1 :

//     Input : nums = [ 4, 2, 5, 7 ] Output : [ 4, 5, 2, 7 ] Explanation : [ 4, 7, 2, 5 ],
//             [ 2, 5, 4, 7 ], [ 2, 7, 4, 5 ] would also have been accepted.Example 2 :

//     Input : nums = [ 2, 3 ] Output : [ 2, 3 ]
#include<bits/stdc++.h>
                                     using namespace std;
vector<int> sortArrayByParityII(vector<int> &nums){
    for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2)
    {
        while (i < nums.size() && nums[i] % 2 == 0)
        {
            i += 2;
        }
        while (j < nums.size() && nums[j] % 2 == 1)
        {
            j += 2;
        }
        if (i < nums.size())
        {
            swap(nums[i], nums[j]);
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
    nums = sortArrayByParityII(nums);
    for(int x:nums){
        cout << x << " ";
    }
    return 0;
}