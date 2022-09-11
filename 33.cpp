// 33. Search in Rotated Sorted Array
//     There is an integer array nums sorted in ascending
//     order(with distinct values)
//         .

//     Prior to being passed to your function,
//     nums is possibly rotated at an unknown pivot index k(1 <= k < nums.length) such that the resulting array is[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]](0 - indexed).For example, [ 0, 1, 2, 4, 5, 6, 7 ] might be rotated at pivot index 3 and become[4, 5, 6, 7, 0, 1, 2].

//                                                                                                                                                                                                                                                                                     Given the array nums after the possible rotation and an integer target,
//     return the index of target if it is in nums, or -1 if it is not in nums.

//                                                      You must write an algorithm with O(log n) runtime complexity.

//                                                      Example 1 :

//     Input : nums = [ 4, 5, 6, 7, 0, 1, 2 ],
//             target = 0 Output : 4 Example 2 :

//     Input : nums = [ 4, 5, 6, 7, 0, 1, 2 ],
//             target = 3 Output : -1 Example 3 :

//     Input : nums = [1],
//             target = 0 Output : -1
#include "bits/stdc++.h"
                                using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
class Solution
{
public:
    int binarySearch(vector<int> &nums,int low,int high,int target){
        while(low<=high){
            int mid = (low + high) / 2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target){
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return -1;
    }
    int pivot(vector<int> &nums,int target){
        int low = 0, high = nums.size() - 1;
        while(low<high){
            int mid = (low + high) / 2;
            if(mid<high && nums[mid]>nums[mid+1])
                return mid;
            if(mid>low && nums[mid]<nums[mid-1])
                return mid - 1;
            if(nums[low]>=nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(low==high)
            return low;
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int index= pivot(nums, target);
        int i = 0, j = nums.size() - 1;
        if(index==-1)
            return binarySearch(nums, i, j, target);
        if(target>=nums[i] && target<=nums[index])
            return binarySearch(nums, i, index, target);
        return binarySearch(nums, index+1, j, target);
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N,target;
        cin >> N>>target;
        vi vect(N);
        FOR(i, N)
        cin >> vect[i];
        Solution s;
        cout<<s.search(vect, target) << endl;
    }
    return 0;
}
