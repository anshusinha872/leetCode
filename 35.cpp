// 35. Search Insert Position
//     Given a sorted array of distinct integers and a target value,
//     return the index if the target is found.If not, return the index where it would be if it were inserted in order.

//                                                            You must write an algorithm with
//                                                            O(log n) runtime complexity.

//                                                            Example 1 :

//     Input : nums = [ 1, 3, 5, 6 ],
//             target = 5 Output : 2 Example 2 :

//     Input : nums = [ 1, 3, 5, 6 ],
//             target = 2 Output : 1 Example 3 :

//     Input : nums = [ 1, 3, 5, 6 ],
//             target = 7 Output : 4
#include<bits/stdc++.h>
            using namespace std;
int searchInsert(vector<int> &nums, int target){
    if (nums.size() == 1 && nums[0] >= target)
    {
        return 0;
    }
    if (nums.size() == 1 && nums[0] < target)
    {
        return 1;
    }
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (i == 0 && nums[i] > target)
        {
            return 0;
        }
        else if (nums[i] == target)
        {
            return i;
        }
        else if (nums[i] < target && nums[i + 1] >= target)
        {
            return i + 1;
        }
        else if (nums[i + 1] < target && i == nums.size() - 2)
        {
            return nums.size();
        }
    }
    return -1;
}
int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << searchInsert(nums, target) << endl;
    return 0;
}