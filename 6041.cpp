#include<bits/stdc++.h>
using namespace std;
vector<int> inserection_of_two_array(vector<vector<int>> &vect){
    int m = vect.size();
    // int n = vect[0].size();
    map<int, int> mp;
    for(auto itr:vect){
        for(int x:itr){
            mp[x]++;
        }
    }
    vector<int> res;
    for(auto itr:mp){
        if(itr.second>=m){
            res.push_back(itr.first);
        }
    }
    return res;
}
int main(){
    // int m, n;
    // cin >> m >> n;
    // vector<vector<int>> vect(m, vector<int>(n));
    // for (int i = 0; i < m;i++){
    //     for (int j = 0; j < n;j++){
    //         cin >> vect[i][j];
    //     }
    // }
    vector<vector<int>> vect = {{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}};
    vector<int> ans;
   
   ans = inserection_of_two_array(vect);
    for(int x:ans){
        cout << x << " ";
    }
    return 0;
}