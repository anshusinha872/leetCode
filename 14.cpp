// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.

//     If there is no common prefix,
//     return an empty string "".

//            Example 1 :

//     Input : strs = [ "flower", "flow", "flight" ] Output : "fl" Example 2 :

//     Input : strs = [ "dog", "racecar", "car" ] Output : "" Explanation : There is no common prefix among the input strings.

//                                                                          Constraints :

//                                                                          1 <= strs.length <= 200 0 <= strs[i].length <= 200 strs[i] consists of only lower - case English letters.
#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs){
    string str = strs[0];
    for (int i = 1; i < strs.size();i++){
        string temp;
        for (int j = 0; j < strs[i].length();j++){
            if(str[j]==strs[i][j]){
                temp.push_back(strs[i][j]);
            }
            else{
                str = temp;
                break;
            }
        }
        str = temp;
    }
    return str;
}
int main(){
    vector<string> strs;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        string temp;
        cin >> temp;
        strs.push_back(temp);
    }
    cout<<longestCommonPrefix(strs) << endl;
    return 0;
}