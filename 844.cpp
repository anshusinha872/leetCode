// 844. Backspace String Compare
//     Given two strings s and t,
//     return true if they are equal when both are typed into empty text editors.'#' means a backspace character.

//     Note that after backspacing an empty text,
//     the text will continue empty.

//     Example 1 :

//     Input : s = "ab#c",
//             t = "ad#c" Output : true Explanation : Both s and t become "ac".Example 2 :

//     Input : s = "ab##",
//             t = "c#d#" Output : true Explanation : Both s and t become "".Example 3 :

//     Input : s = "a#c",
//             t = "b" Output : false Explanation : s becomes "c" while t becomes "b".

#include<bits/stdc++.h>
                                                 using namespace std;
bool backspaceCompare(string s, string t){
    // stack<char> st1, st2;
    // for (int i = 0; i < s.length();i++){
    //     if (s[i] == '#'&& !st1.empty()) {
    //         st1.pop();
    //     }
    //     else if(s[i]!='#'){
    //         st1.push(s[i]);
    //     }
    // }
    // for (int i = 0; i < t.length();i++){
    //     if(t[i]=='#' && !st2.empty()){
    //         st2.pop();
    //     }
    //     else if(t[i]!='#'){
    //         st2.push(t[i]);
    //     }
    // }
    // s.clear();
    // while(st1.empty()==false){
    //     s.push_back(st1.top());
    //     st1.pop();
    // }
    // t.clear();
    // while(st2.empty()==false){
    //     t.push_back(st2.top());
    //     st2.pop();
    // }
    // bool flag=s==t?true:false;
    // return flag;
    int k = 0, p = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='#'){
            k--;
            k = max(0, k);
        }
        else{
            s[k] = s[i];
            k++;
        }
    }
    for (int i = 0; i < t.length();i++){
        if(t[i]=='#'){
            p--;
            p = max(0, p);
        }
        else{
            s[p] = s[i];
            p++;
        }
    }
    if(k!=p){
        return false;
    }
    else{
        for (int i = 0; i < k;i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    string s, t;
    cin >> s >> t;
    cout << backspaceCompare(s, t) << endl;
    return 0;
}