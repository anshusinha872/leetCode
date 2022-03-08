// 409. Longest Palindrome
// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:

// Input: s = "a"
// Output: 1
// Example 3:

// Input: s = "bb"
// Output: 2

#include<bits/stdc++.h>
    using namespace std;
bool myCmp(pair<char,int> p1,pair<char,int> p2){
    return p1.second > p1.second;
}
int longestPalindrome(string s){
    map<char, int> mp;
    for (int i = 0; i < s.length();i++){
        mp[s[i]]++;
    }
    int count = 0;
    int odd_count = 0;
    for(auto itr:mp){
        count += itr.second / 2;
        odd_count += itr.second % 2;
    }
    // cout << "pair count : " << count;
    // cout << "odd count : " << odd_count;
    int length = 0;
    if(count>=1){
        length = count * 2;
    }
    if(odd_count>=1){
        length += 1;
    }
    return length;
}
int main(){
    string str;
    cin >> str;
    cout << longestPalindrome(str) << endl;
    return 0;
}