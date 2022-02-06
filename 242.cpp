// 242. Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

//                                                                     An Anagram is a word or
//                                                                     phrase formed by rearranging the letters of a different word or phrase,
//     typically using all the original letters exactly once.

//     Example 1 :

//     Input : s = "anagram",
//             t = "nagaram" Output : true Example 2 :

//     Input : s = "rat",
//             t = "car" Output : false

#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s,string t){
    if(s.length()!=t.length())
        return false;
    vector<int> vect(26, 0);
    for (int i = 0; i < s.length();i++){
        vect[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length();i++){
        if(vect[t[i]-'a']!=0){
            vect[t[i] - 'a']--;
        }
        else
            return false;
    }
    return true;
}
int main(){
    string s, t;
    cin >> s >> t;
    cout << isAnagram(s, t);
}