// 153. Find Minimum in Rotated Sorted Array
//         Suppose an array of length n sorted in ascending order is rotated between 1 and
//     n times.For example,
//     the array nums = [ 0, 1, 2, 4, 5, 6, 7 ] might become :

//     [ 4, 5, 6, 7, 0, 1, 2 ] if it was rotated 4 times.
//         [0, 1, 2, 4, 5, 6, 7] if it was rotated 7 times.Notice that rotating an array[a[0], a[1], a[2], ..., a[n - 1]] 1 time results in the array[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]]
//             .

//     Given the sorted rotated array nums of unique elements,
//               return the minimum element of this array.

//                      You must write an algorithm that runs in
//                      O(log n) time.

//                      Example 1 :

//     Input : nums = [ 3, 4, 5, 1, 2 ] Output : 1 Explanation : The original array was[1, 2, 3, 4, 5] rotated 3 times.Example 2 :

//     Input : nums = [ 4, 5, 6, 7, 0, 1, 2 ] Output : 0 Explanation : The original array was[0, 1, 2, 4, 5, 6, 7] and it was rotated 4 times.Example 3 :

//     Input : nums = [ 11, 13, 15, 17 ] Output : 11 Explanation : The original array was[11, 13, 15, 17] and it was rotated 4 times.
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
    int binarySearch(vector<int> &nums, int i, int j)
    {
        if (i > j)
            return INT_MAX;
        if (i == j)
            return nums[i];
        if (i + 1 == j)
            return min(nums[i], nums[j]);
        while (i < j)
        {
            int mid = (i + j) >> 1;
            if (nums[i] < nums[mid])
            {
                return min(nums[i], binarySearch(nums, mid + 1, j));
            }
            else
                return min(nums[mid], binarySearch(nums, i, mid - 1));
        }
        return INT_MAX;
    }
    int findMin(vector<int> &nums)
    {
        return binarySearch(nums, 0, nums.size() - 1);
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
        int N;
        cin >> N;
        vi nums(N);
        FOR(i, N)
        cin >> nums[i];
    }
    return 0;
}
