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
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (n == 2)
            return nums[0] > nums[1] ? 0 : 1;
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if ((mid == 0 || (nums[mid] > nums[mid - 1])) && (mid == n - 1 || (nums[mid] > nums[mid + 1])))
                return mid;
            if (mid > 0 && nums[mid - 1] > nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
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
        vi vect(N);
        FOR(i, N)
        cin >> vect[i];
        Solution s;
        cout << s.findPeakElement(vect) << endl;
        return 0;
    }
    return 0;
}
