// 2091. Removing Minimum and Maximum From Array
//             You are given a 0 -
//         indexed array of distinct integers nums.

//         There is an element in nums that has the lowest value and an element that has the highest value.We call them the minimum and maximum respectively.Your goal is to remove both these elements from the array.

//         A deletion is defined as either removing an element from the front of the array or
//     removing an element from the back of the array.

//     Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

//     Example 1 :

//     Input : nums = [ 2, 10, 7, 5, 4, 1, 8, 6 ] Output : 5 Explanation : The minimum element in the array is nums[5],
//             which is 1. The maximum element in the array is nums[1], which is 10. We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.This results in 2 + 3 = 5 deletions, which is the minimum number possible.Example 2 :

//     Input : nums = [ 0, -4, 19, 1, 8, -2, -3, 5 ] Output : 3 Explanation : The minimum element in the array is nums[1],
//             which is - 4. The maximum element in the array is nums[2], which is 19. We can remove both the minimum and maximum by removing 3 elements from the front.This results in only 3 deletions, which is the minimum number possible.Example 3 :

//     Input : nums = [101] Output : 1 Explanation : There is only one element in the array,
//             which makes it both the minimum and maximum element.We can remove it with 1 deletion.
#include<bits/stdc++.h>
using namespace std;
int minimumDeletions(vector<int> &nums){
    cout << nums.size() << endl;
    if(nums.size()<=2){
        return nums.size();
    }
    map<int, int> mp;
    for (int i = 0; i < nums.size();i++){
        mp[nums[i]] = i;
    }
    int res = 0;
    int n = nums.size();
    int var1 = mp.begin()->second;
    int var2 = (mp.rbegin())->second;
    int case1 = 0, case2 = 0, case3 = 0, case4 = 0;
    case1 = var1 + 1 + n - var2;
    case2 = n - var1 + var2 + 1;
    case3 = max(var1 + 1 , var2 + 1);
    case4 = max(n - var1 , n - var2);
    return min(case1,min(case2,min(case3,case4)));
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << minimumDeletions(nums) << endl;
    return 0;
}