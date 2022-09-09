// 1996. The Number of Weak Characters in the Game
//     You are playing a game that contains multiple characters,
//     and each of the characters has two main properties : attack and defense.You are given a 2D integer array properties where properties[i] = [ attacki, defensei ] represents the properties of the ith character in the game.

//                                                                                                                                               A character is said to be weak if any other character has both attack and defense levels strictly greater than this character's attack and defense levels. More formally, a character i is said to be weak if there exists another character j where attackj > attacki and defensej > defensei.

//                                                                                                                                               Return the number of weak characters.

//                                                                                                                                               Example 1 :

//     Input : properties = [ [ 5, 5 ], [ 6, 3 ], [ 3, 6 ] ] Output : 0 Explanation : No character has strictly greater attack and defense than the other.Example 2 :

//     Input : properties = [ [ 2, 2 ], [ 3, 3 ] ] Output : 1 Explanation : The first character is weak because the second character has a strictly greater attack and defense.Example 3 :

//     Input : properties = [ [ 1, 5 ], [ 10, 4 ], [ 4, 3 ] ] Output : 1 Explanation : The third character is weak because the second character has a strictly greater attack and defense.
#include <bits/stdc++.h>
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
    bool static myCmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[1] < b[1])
            return true;
        return false;
    }
    bool static myCmp1(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] < b[0])
            return true;
        return false;
    }
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        map<pair<int, int>, int> mp1;
        map<pair<int, int>, int> mp2;
        sort(properties.begin(), properties.end(), myCmp);
        int m = properties.size();
        stack<int> st;
        st.push(properties[m - 1][0]);
        for (int i = m - 2;i>=0;i--){
            while(!st.empty() && st.top()<=properties[i][0] ){
                st.pop();
            }
            if(st.size()!=0){
                mp1[{properties[i][0], properties[i][1]}]++;
            }
            st.push(properties[i][0]);
        }
        sort(properties.begin(), properties.end(), myCmp1);
        stack<int> st1;
        st1.push(properties[m - 1][1]);
        for (int i = m - 2; i >= 0; i--)
        {
            while (!st1.empty() && st1.top() <= properties[i][1])
            {
                st1.pop();
            }
            if (st1.size() != 0)
            {
                mp2[{properties[i][0], properties[i][1]}]++;
            }
            st1.push(properties[i][1]);
        }
        int count = 0;
        for(auto itr:mp1){
            if(mp2.find(itr.first)!=mp2.end()){
                count += min(itr.second, mp2[itr.first]);
            }
        }
        return count;
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
        vvi vect(N);
        FOR(i, N){
            vi temp(2);
            FOR(j,2){
                cin >> temp[j];
            }
            vect[i]=temp;
        }
        Solution s;
        cout << s.numberOfWeakCharacters(vect) << endl;
    }
    return 0;
}
