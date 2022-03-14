// 151. Reverse Words in a String
//     Given an input string s,
//     reverse the order of the words.

//             A word is defined as a sequence of non -
//             space characters.The words in s will be separated by at least one space.

//             Return a string of the words in reverse order concatenated by a single space.

//             Note that s may contain leading or
//         trailing spaces or multiple spaces between two words.The returned string should only have a single space separating the words.Do not include any extra spaces.

//                            Example 1 :

//     Input : s = "the sky is blue" Output : "blue is sky the" Example 2 :

//     Input : s = "  hello world  " Output : "world hello" Explanation : Your reversed string should not contain leading or trailing spaces.Example 3 :

//     Input : s = "a good   example" Output : "example good a" Explanation : You need to reduce multiple spaces between two words to a single space in the reversed string.

#include<bits/stdc++.h>
using namespace std;
void reverse_util(string &str,int start,int end){
    while(start<=end){
        swap(str[start], str[end]);
        start++;
        end--;
    }
}
void reverseWords(string &s){
    int start = 0;
    int n = s.length();
    for (int end = 0; end < n;end++){
        if(s[end]==' '){
            reverse_util(s, start, end - 1);
            start = end + 1;
        }
    }
    reverse_util(s, start, n-1);
    reverse_util(s, 0, n-1);
    // return s
}
int main(){
    string str;
    getline(cin, str);
    string s;
    int i = 0;
    while(str[i]==' '){
        i++;
    }
    int j = str.length() - 1;
    while(str[j]==' '){
        j--;
    }
    // cout << str[j] << endl;
    int count = 0;
    bool flag = false;
    cout << "start";
    for (int start = i; start <= j;start++){
        if(str[start]==' '){
            while(str[start]==' '){
                start++;
            }
            start--;
            s.push_back(' ');
        }
        else{
            s.push_back(str[start]);
        }
    }
    cout << "end";
    reverseWords(s);
    cout << s << endl;
    return 0;
}