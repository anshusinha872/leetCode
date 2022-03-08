// 290. Word Pattern
// Given a pattern and a string s, find if s follows the same pattern.

//                                 Here follow means a full match,
//     such that there is a bijection between a letter in pattern and a non - empty word in s.

//                                                                            Example 1 :

//     Input : pattern = "abba",
//             s = "dog cat cat dog" Output : true Example 2 :

//     Input : pattern = "abba",
//             s = "dog cat cat fish" Output : false Example 3 :

//     Input : pattern = "aaaa",
//             s = "dog cat cat dog" Output : false

#include<bits/stdc++.h>
using namespace std;
bool wordPattern(string pattern,string s){
    map<char, int> mp_p;
    map<string, int> mp_s;
    string str1,str2;
    for (int i = 0; i < pattern.length();i++){
        if(mp_p.find(pattern[i])==mp_p.end()){
            mp_p[pattern[i]] = i;
            str1.push_back(i+'0');
        }
        else{
            str1.push_back(mp_p[pattern[i]]+'0');
        }
    }
    vector<string> vect;
    int k = 0;
    string temp;
    for (int i = 0; i < s.length();){
        if(s[i]==' '|| i==s.length()-1){
            if(i==s.length()-1){
                temp.push_back(s[i]);
                vect.push_back(temp);
                break;
            }
            vect.push_back(temp);
            i++;
            temp = "";
        }
        else{
            temp.push_back(s[i]);
            i++;
        }
    }
    for (int i = 0; i < vect.size();i++){
        string str_temp = vect[i];
        if(mp_s.find(str_temp)==mp_s.end()){
            mp_s[str_temp] = i;
            str2.push_back(i + '0');
        }
        else{
            str2.push_back(mp_s[str_temp]+'0');
        }
    }
    // for(auto itr:mp_s){
    //     cout << itr.first << " " << itr.second << endl;
    // }
    // for(auto itr:vect){
    //     cout << itr << endl;
    // }
    // cout << str1 << endl;
    // cout << str2 << endl;
    return str1 == str2;
}
int main(){
    string pattern, s;
    cin >> pattern;
    getchar();
    getline(cin,s);
    cout << wordPattern(pattern, s) << endl;
    return 0;
}