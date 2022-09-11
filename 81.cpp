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
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 1 && nums[0] == target)
            return true;
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {

            while (low < high && nums[low] == nums[low + 1])
            {
                low = low + 1;
            }
            while (low < high && nums[high] == nums[high - 1])
                high = high - 1;
            int mid = (low + high) >> 1;
            if (nums[mid] == target)
                return true;
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
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
            cin >>vect[i];
        Solution s;
        cout<<s.search(vect, target) << endl;
    }
    return 0;
}
