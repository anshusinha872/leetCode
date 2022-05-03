// 239. Sliding Window Maximum
//     You are given an array of integers nums,
//     there is a sliding window of size k which is moving from the very left of the array to the very right.You can only see the k numbers in the window.Each time the sliding window moves right by one position.

//     Return the max sliding window.

//     Example 1 :

//     Input : nums = [ 1, 3, -1, -3, 5, 3, 6, 7 ],
//             k = 3 Output : [ 3, 3, 5, 5, 6, 7 ] Explanation : Window position Max-- -- -- -- -- -- -- - -- -- -
//                                                               [1 3 - 1] -
//                                                               3 5 3 6 7 3 1 [3 - 1 - 3] 5 3 6 7 3 1 3 [-1 - 3 5] 3 6 7 5 1 3 - 1 [-3 5 3] 6 7 5 1 3 - 1 - 3 [5 3 6] 7 6 1 3 - 1 - 3 5 [3 6 7] 7 Example 2 :

//     Input : nums = [1],
//             k = 1 Output : [1]

//                            Constraints :

//                            1 <= nums.length <= 105 - 104 <=
//                            nums[i] <= 104 1 <= k <= nums.length

#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> res;
    if(k>n){
        return {};
    }
    map<int, int,greater<int>> mp;
    for (int i = 0; i < k;i++){
        mp[nums[i]]++;
    }
    auto it = mp.begin();
    res.push_back(it->first);
    for (int i = k; i < n;i++){
        mp[nums[i - k]]--;
        auto itr = mp.find(nums[i - k]);
        if(itr->second==0){
            mp.erase(nums[i - k]);
        }
        mp[nums[i]]++;
        it = mp.begin();
        res.push_back(it->first);
    }
    return res;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    nums = maxSlidingWindow(nums, k);
    for(int x:nums){
        cout << x << " ";
    }
    return 0;
}