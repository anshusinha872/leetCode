// 15. 3Sum 
// Given an integer array nums, return all the triplets[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

//                                                                                                                                                                   Notice that the solution set must not contain duplicate triplets.

//                                                                                                                                                                   Example 1 :

//     Input : nums = [ -1, 0, 1, 2, -1, -4 ] Output : [ [ -1, -1, 2 ], [ -1, 0, 1 ] ] Example 2 :

//     Input : nums = [] Output : [] Example 3 :

//     Input : nums = [0] Output : []

//                                 Constraints :

//                                 0 <= nums.length <= 3000 - 105 <=
//                                 nums[i] <= 105

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> vect;
    int n = nums.size();
    for (int i = 0; i < n - 2;i++){
        if(i==0 ||(i>0 && nums[i]!=nums[i-1])){
            int low = i + 1, h = n - 1, sum = 0 - nums[i];
            while(low<h){
                if(nums[low]+nums[h]==sum){
                    vect.push_back({nums[i], nums[low], nums[h]});
                    while(low<h && nums[low]==nums[low+1])
                        low++;
                    while(low<h && nums[h]==nums[h-1])
                        h--;
                    low++;
                    h--;
                }
                else if (nums[low] + nums[h] < sum){
                    low++;
                }
                else h--;
            }
        }
        

    }
    return vect;
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
    vector<vector<int>> vect = threeSum(nums);
    for(auto x:vect){
        vector<int> vect = x;
        for(int i:vect){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}