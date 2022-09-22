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
    static bool myCmp(const pair<int, pair<int, int>> &p1, const pair<int, pair<int, int>> &p2)
    {
        if (p1.first < p2.first)
            return true;
        return false;
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<pair<int, pair<int, int>>> vect;
        for (auto itr : points)
        {
            int x = itr[0];
            int y = itr[1];
            int dist = pow(x, 2) + pow(y, 2);
            vect.push_back({dist, {x, y}});
        }
        sort(vect.begin(), vect.end(), myCmp);
        vector<vector<int>> ans;
        for (int i = 0; i < k && i < vect.size(); i++)
        {
            ans.push_back({vect[i].second.first, vect[i].second.second});
        }
        return ans;
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
        vvi points(N);
        FOR(i,N){
            FOR(j,2){
                cin >> points[i][j];
            }
        }
    }
    return 0;
}
