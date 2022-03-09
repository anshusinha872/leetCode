// 49. Group Anagrams
//     Given an array of strings strs,
//     group the anagrams together.You can return the answer in any order.

//         An Anagram is a word or
//         phrase formed by rearranging the letters of a different word or phrase,
//     typically using all the original letters exactly once.

//     Example 1 :

//     Input : strs = [ "eat", "tea", "tan", "ate", "nat", "bat" ] Output : [ ["bat"], [ "nat", "tan" ], [ "ate", "eat", "tea" ] ] Example 2 :

//     Input : strs = [""] Output : [[""]] Example 3 :

//     Input : strs = ["a"] Output : [["a"]]

#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs){
    map<string, vector<string>> mp;
    for (int i = 0; i < strs.size();i++){
        string str = strs[i];
        string temp = str;
        sort(temp.begin(), temp.end());
        mp[temp].push_back(str);
    }
    vector<vector<string>> vect;
    for(auto itr:mp){
        vector<string> v;
        for(auto x:itr.second){
            v.push_back(x);
        }
        vect.push_back(v);
    }
    return vect;
}
int main(){
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n;i++){
        string str;
        cin >> str;
        strs.push_back(str);
    }
    vector<vector<string>> vect = groupAnagrams(strs);
    for(auto itr:vect){
        for(auto x:itr){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}