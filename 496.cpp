// 496. Next Greater Element I
// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        map<int, int> mp;
        mp[nums2[nums2.size()-1]] = -1;
        stack<int> s;
        s.push(nums2[nums2.size() - 1]);
        for (int i = nums2.size() - 2; i >= 0;i--){
            while(!s.empty() && s.top()<nums2[i]){
                s.pop();
            }
            if(s.empty()==true){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for(auto itr:mp){
            cout << itr.first << " " << itr.second << endl;
        }
        vector<int> vect(nums1.size());
        for (int i = 0; i < nums1.size();i++){
            vect[i] = mp[nums1[i]];
        }
        return vect;
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
        int N,M;
        cin >> N>>M;
        vi nums1(N);
        vi nums2(M);
        FOR(i, N)
        cin >> nums1[i];
        FOR(i,M)
        cin >> nums2[i];
        Solution s;
        vi vect = s.nextGreaterElement(nums1, nums2);
        for(int x:vect)
            cout << x << " ";
        return 0;
    }
    return 0;
}
