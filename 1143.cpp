// 1143. Longest Common Subsequence
//     Given two strings text1 and text2,
//     return the length of their longest common subsequence.If there is no common subsequence, return 0.

//     A subsequence of a string is a new string generated from the original string with some
//     characters(can be none) deleted without changing the relative order of the remaining characters.

//     For example,
//     "ace" is a subsequence of "abcde".A common subsequence of two strings is a subsequence that is common to both strings.

//     Example 1 :

//     Input : text1 = "abcde",
//             text2 = "ace" Output : 3 Explanation : The longest common subsequence is "ace" and its length is 3. Example 2 :

//     Input : text1 = "abc",
//             text2 = "abc" Output : 3 Explanation : The longest common subsequence is "abc" and its length is 3. Example 3 :

//     Input : text1 = "abc",
//             text2 = "def" Output : 0 Explanation : There is no such common subsequence, so the result is 0.

#include<bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2){
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> vect(m+1, vector<int>(n+1));
    for (int i = 0; i <= m;i++)
        vect[i][0] = 0;
    for (int j = 0; j <= n;j++)
        vect[0][j] = 0;
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            if(text1[i-1]==text2[j-1])
                vect[i][j] = 1 + vect[i - 1][j - 1];
            else
                vect[i][j] = max(vect[i - 1][j], vect[i][j - 1]);
        }
    }
    return vect[m][n];
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    cout<<longestCommonSubsequence(str1, str2);
    return 0;
}