#include<bits/stdc++.h>
using namespace std;
bool util(string str1,string str2){
    if(str1.length()>str2.length()){
        return false;
    }
    int n = str1.length() < str2.length() ? str1.length() : str2.length();
    for (int i = 0; i < n;i++){
        if(str1[i]!=str2[i]){
            return false;
        }
    }
    return true;
}
int countPrefixes(vector<string> &words, string s){
    int n = words.size();
    int count = 0;
    for (int i = 0; i < n;i++){
        string str = words[i];
        if(util(str,s)){
            cout << str << " " << s << endl;
            count++;
        }
    }
    return count;
}
int main(){
    // int n;
    // cin >> n;
    string s;
    cin >> s;
    vector<string> words={"feh","w","w","lwd","c","s","vk","zwlv","n","w","sw","qrd","w","w","mqe","w","w","w","gb","w","qy","xs","br","w","rypg","wh","g","w","w","fh","w","w","sccy"};
    // for (int i = 0; i < n;i++){
    //     cin >> words[i];
    // }
    cout << countPrefixes(words, s) << endl;
    return 0;
}