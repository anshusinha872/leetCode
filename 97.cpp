// 97. Interleaving String
//     Given strings s1,
//     s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

//                     An interleaving of two strings s and t is a configuration where they are divided into non -
//                     empty substrings such that :

//     s = s1 + s2 + ... + sn t = t1 + t2 + ... + tm | n - m | <= 1 The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ... Note : a + b is the concatenation of strings a and b.

//                                                                                                                                                                        Example 1 :

//     Input : s1 = "aabcc",
//     s2 = "dbbca", s3 = "aadbbcbcac" Output : true Example 2 :

//     Input : s1 = "aabcc",
//     s2 = "dbbca", s3 = "aadbbbaccc" Output : false Example 3 :

//     Input : s1 = "",
//     s2 = "", s3 = "" Output : true

#include<bits/stdc++.h>
using namespace std;
bool isInterleave_util(string &s1,string &s2,string &s3,int n1,int n2,int n3,int ptr1,int ptr2,int ptr3,unordered_map<string,bool> &mp){
    if(ptr3==n3)
        return (ptr1 == n1 && ptr2 == n2) ? true : false;
    string key = to_string(ptr1) + "*" + to_string(ptr2) + "*" + to_string(ptr3);
    if(mp.find(key)!=mp.end())
        return mp[key];
    if(ptr1==n1)
        return mp[key] = s2[ptr2] == s3[ptr3] ? isInterleave_util(s1, s2, s3, n1, n2, n3, ptr1, ptr2 + 1, ptr3 + 1,mp) : false;
    if(ptr2==n2)
        return mp[key] = s1[ptr1] == s3[ptr3] ? isInterleave_util(s1, s2, s3, n1, n2, n3, ptr1 + 1, ptr2, ptr3 + 1,mp):false;
    bool one = false, two = false;
    if(s1[ptr1]==s3[ptr3]){
        one = isInterleave_util(s1, s2, s3, n1, n2, n3, ptr1 + 1, ptr2, ptr3 + 1,mp);
    }
    if(s2[ptr2]==s3[ptr3]){
        two = isInterleave_util(s1, s2, s3, n1, n2, n3, ptr1, ptr2 + 1, ptr3 + 1,mp);
    }

    return mp[key] = one || two;
}
bool isInterleave(string s1, string s2, string s3){
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();
    unordered_map<string, bool> mp;
    if(n3!=n1+n2)
        return false;
    return isInterleave_util(s1, s2, s3, n1, n2, n3, 0, 0, 0,mp);
}
int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << isInterleave(s1, s2, s3) << endl;
    return 0;
}