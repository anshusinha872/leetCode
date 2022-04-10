// 438. Find All Anagrams in a String
//     Given two strings s and p,
//     return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

//            An Anagram is a word or
//            phrase formed by rearranging the letters of a different word or phrase,
//     typically using all the original letters exactly once.

//     Example 1 :

//     Input : s = "cbaebabacd",
//             p = "abc" Output : [ 0, 6 ] Explanation : The substring with start index = 0 is "cba", which is an anagram of "abc".The substring with start index = 6 is "bac", which is an anagram of "abc".Example 2 :

//     Input : s = "abab",
//             p = "ab" Output : [ 0, 1, 2 ] Explanation : The substring with start index = 0 is "ab", which is an anagram of "ab".The substring with start index = 1 is "ba", which is an anagram of "ab".The substring with start index = 2 is "ab", which is an anagram of "ab".
#include<bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p){
    unordered_map<char, int> smap;
    unordered_map<char, int> pmap;
    vector<int> vect;
    for (int i = 0; i < p.length();i++){
        pmap[p[i]]++;
    }
    for (int i = 0; i < p.length();i++){
        smap[s[i]]++;
    }
    int j = 0;
    int i = p.length();
    while(i<s.length()){
        if(pmap==smap){
            vect.push_back(j);
        }
        smap[s[i]]++;
        if(smap[s[j]]==1){
            smap.erase(s[j]);
        }
        else{
            smap[s[j]]--;
        }
        i++;
        j++;
    }
    if(smap==pmap){
        vect.push_back(j);
    }
    return vect;
}
int main(){
    string s, p;
    cin >> s >> p;
    vector<int> vect = findAnagrams(s, p);
    for(auto x:vect){
        cout << x << " ";
    }
    return 0;

}