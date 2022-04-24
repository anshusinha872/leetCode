#include<bits/stdc++.h>
using  namespace std;
int countLatticePoints(vector<vector<int>> &circles){
    set<pair<int, int>> st;
    int m = circles.size();
    for (int i = 0; i < m;i++){
        int x = circles[i][0];
        int y = circles[i][1];
        int r = circles[i][2];
        for (int i = x - r; i <= x + r;i++){
            for (int j = y - r; j <= y + r;j++){
                if((x-i)*(x-i)+(y-j)*(y-j)<=r*r){
                    st.insert(make_pair(i, j));
                }
            }
        }
    }
    return st.size();
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> vect(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> vect[i][j];
        }
    }
    cout << countLatticePoints(vect) << endl;
    return 0;
}