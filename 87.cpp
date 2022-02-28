// 87. Scramble String
//     We can scramble a string s to get a string t using the following algorithm :

//     If the length of the string is 1,
//     stop.If the length of the string is > 1,
//     do the following : Split the string into two non - empty substrings at a random index,
//     i.e.,
//     if the string is s,
//     divide it to x and y where s = x + y.Randomly decide to swap the two substrings or to keep them in the same order.i.e.,
//                                after this step,
//                                s may become s = x + y or s = y + x.Apply step 1 recursively on each of the two substrings x and y.Given two strings s1 and s2 of the same length,
//                                return true if s2 is a scrambled string of s1,
//                                otherwise,
//                                return false.

//                                       Example 1 :

//     Input : s1 = "great",
//                                s2 = "rgeat" Output : true Explanation : One possible scenario applied on s1 is : "great" -- > "gr/eat"                                                                                           // divide at random index.
//                                                                                                                               "gr/eat" -- > "gr/eat"                                                                             // random decision is not to swap the two substrings and keep them in order.
//                                                                                                                                             "gr/eat" -- > "g/r / e/at"                                                           // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
//                                                                                                                                                           "g/r / e/at" -- > "r/g / e/at"                                         // random decision was to swap the first substring and to keep the second substring in the same order.
//                                                                                                                                                                             "r/g / e/at" -- > "r/g / e/ a/t"                     // again apply the algorithm recursively, divide "at" to "a/t".
//                                                                                                                                                                                               "r/g / e/ a/t" -- > "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
//                                                                                                                                                                                                                   The algorithm stops now and the result string is "rgeat" which is s2.As there is one possible scenario that led s1 to be scrambled to s2,
//                                we return true.Example 2 :

//     Input : s1 = "abcde",
//                                s2 = "caebd" Output : false Example 3 :

//     Input : s1 = "a",
//                                s2 = "a" Output : true

#include<bits/stdc++.h>
using namespace std;
bool isScramble_util(string s1,string s2,unordered_map<string,bool> &mp){
    if(s1.compare(s2)==0)
        return true;
    if(s1.length()<=1)
        return false;
    string key = s1;
    key.push_back(' ');
    key.append(s2);
    if(mp.find(key)!=mp.end()){
        return mp[key];
    }
    bool flag = false;
    int n = s1.length();
    for (int i = 1; i <= n - 1;i++){
        bool cond1, cond2;
        cond1 = cond2 = false;
        if(isScramble_util(s1.substr(0,i),s2.substr(0,i),mp)==true && isScramble_util(s1.substr(i,n-i),s2.substr(i,n-i),mp)==true)
            cond1 = true;
        if(isScramble_util(s1.substr(0,i),s2.substr(n-i,i),mp)==true && isScramble_util(s1.substr(i,n-i),s2.substr(0,n-i),mp)==true)
            cond2 = true;
        if(cond1||cond2){
            flag = true;
            break;
        }
    }
    mp[key] = flag;
    return flag;
}
bool isScramble(string s1, string s2){
    unordered_map<string, bool> mp;
    return isScramble_util(s1, s2, mp);
} 
int main()
{
    string a, b;
    cin >> a >> b;
    if(a.length()!=b.length())
        return false;
    if(a.length()==0 && b.length()==0)
        return true;
    cout << isScramble(a, b) << endl;
    return 0;
}