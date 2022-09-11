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
    int mostWordsFound(vector<string> &sentences)
    {
        int res = INT_MIN;
        for (auto itr : sentences)
        {
            string str = itr;
            // cout<<str<<endl;
            int count = 0;
            for (int i = 0; i < str.length(); i++)
            {
                int j = i;
                while (j < str.length() && str[j] != ' ')
                {
                    // cout<<j<<" ";
                    j++;
                }
                i = j;
                count++;
            }
            res = max(res, count);
        }
        return res;
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
        vector<string> vect(N);
        FOR(i, N)
        cin >> vect[i];
        Solution s;
        cout << s.mostWordsFound(vect) << endl;
    }
    return 0;
}
