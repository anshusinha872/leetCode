// 125. Valid Palindrome
//     A phrase is a palindrome if,
//     after converting all uppercase letters into lowercase letters and removing all non - alphanumeric characters, it reads the same forward and backward.Alphanumeric characters include letters and numbers.

//                                                                                                                   Given a string s,
//     return true if it is a palindrome, or false otherwise.

//                                            Example 1 :

//     Input : s = "A man, a plan, a canal: Panama" Output : true Explanation : "amanaplanacanalpanama" is a palindrome.Example 2 :

//     Input : s = "race a car" Output : false Explanation : "raceacar" is not a palindrome.Example 3 :

//     Input : s = " " Output : true Explanation : s is an empty string "" after removing non - alphanumeric characters.Since an empty string reads the same forward and backward,
//             it is a palindrome.

#include<bits/stdc++.h>
            using namespace std;
bool isPalindrome(string s){
    string str;
    for (int i = 0; i < s.length();i++){
        if(s[i]<='z' && s[i]>='a'){
            str.push_back(s[i]);
        }
        else if(s[i]<='Z' &&s[i]>='A'){
            str.push_back(s[i] + 32);
        }
        else if(s[i]<='9' &&s[i]>='0')
            str.push_back(s[i]);
    }
    int begin = 0, end = str.length() - 1;
    while(begin<end){
        if(str[begin]!=str[end]){
            return false;
        }
        begin++;
        end--;
    }
    return true;
}
int main(){
    string s;
    getline(cin, s);
    cout << isPalindrome(s) << endl;
    return 0;
}