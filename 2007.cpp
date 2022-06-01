// 2007. Find Original Array From Doubled Array
//     An integer array original is transformed into a doubled array changed by appending twice the value of every element in original,
//     and then randomly shuffling the resulting array.

//         Given an array changed,
//     return original if changed is a doubled array.If changed is not a doubled array, return an empty array.The elements in original may be returned in any order.

//                                                                                             Example 1 :

//     Input : changed = [ 1, 3, 4, 2, 6, 8 ] Output : [ 1, 3, 4 ] Explanation : One possible original array could be[1, 3, 4] : -Twice the value of 1 is 1 * 2 = 2. - Twice the value of 3 is 3 * 2 = 6. - Twice the value of 4 is 4 * 2 = 8. Other original arrays could be[4, 3, 1] or [ 3, 1, 4 ].Example 2 :

//     Input : changed = [ 6, 3, 0, 1 ] Output : [] Explanation : changed is not a doubled array.Example 3 :

//     Input : changed = [1] Output : [] Explanation : changed is not a doubled array.

//                                                     Constraints :

//                                                     1 <= changed.length <= 105 0 <= changed[i] <= 105

#include<bits/stdc++.h>
using namespace std;
vector<int> findOriginalArray(vector<int> &changed){
    vector<int> vect;
    unordered_map<int,int> mp;
    if(changed.size()%2!=0){
        return {};
    }
    sort(changed.begin(), changed.end());
    for (int x:changed){
        mp[x]++;
    }
    for(int x: changed){
        if(mp[x]){
            mp[x]--;
            vect.push_back(x);
            if(mp[x*2])
                mp[x * 2]--;
            else{
                return {};
            }
        }
    }
    return vect;
}
int main(){
    int n;
    cin >> n;
    vector<int> changed(n);
    for (int i = 0; i < n;i++){
        cin >> changed[i];
    }
    changed = findOriginalArray(changed);
    for(int x:changed){
        cout << x << " ";
    }
    return 0;
}