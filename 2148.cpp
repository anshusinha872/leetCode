// 2148. Count Elements With Strictly Smaller and Greater Elements
//     Given an integer array nums,
//     return the number of elements that have both a strictly smaller and a strictly greater element appear in nums.

//            Example 1 :

//     Input : nums = [ 11, 7, 2, 15 ] Output : 2 Explanation : The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.Example 2 :

//     Input : nums = [ -3, 3, 3, 90 ] Output : 2 Explanation : The element 3 has the element - 3 strictly smaller than it and the element 90 strictly greater than it.Since there are two elements with the value 3,
//             in total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.

#include<bits/stdc++.h>
            using namespace std;
int countElements(vector<int> &nums){
    map<int, int> mp;
    for(int x:nums){
        mp[x]++;
    }
    int count = 0;
    int size = mp.size();
    int i = 0;
    for(auto itr:mp){
        if(i==0 || i==size-1){
            i++;
            continue;
        }
        count += itr.second;
        i++;
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << countElements(nums) << endl;
    return 0;
}