// 128. Longest Consecutive Sequence
//     Given an unsorted array of integers nums,
//     return the length of the longest consecutive elements sequence.

//            You must write an algorithm that runs in O(n) time.

//            Example 1 :

//     Input : nums = [ 100, 4, 200, 1, 3, 2 ] Output : 4 Explanation : The longest consecutive elements sequence is[1, 2, 3, 4].Therefore its length is 4. Example 2 :

//     Input : nums = [ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 ] Output : 9

//                    Constraints :

//                    0 <= nums.length <= 105 - 109 <=
//                    nums[i] <= 109

#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums){
    set<int> st;
    for (int i = 0; i < nums.size();i++){
        st.insert(nums[i]);
    }
    int count = 0;
    int curr = 1;
    for(int x:st){
        
        if(st.find(x+1)!=st.end()){
            curr++;
            // x = x + 1;
            // continue;
        }
        else{
            count = max(count, curr);
            curr = 1;
        }
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
    cout << longestConsecutive(nums) << endl;
    return 0;
}