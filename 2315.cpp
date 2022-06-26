// 2315. Count Asterisks
//     ou are given a string s,
//     where every two consecutive vertical bars '|' are grouped into a pair.In other words, the 1st and 2nd '|' make a pair, the 3rd and 4th '|' make a pair, and so forth.

//                                                                                                                                                                 Return the number of '*' in s,
//     excluding the '*' between each pair of '|'.

//     Note that each '|' will belong to exactly one pair.
#include<bits/stdc++.h>
    using namespace std;
int countAsterisks(string s){
    int res=0,count=0;
    for (int i = 0; i < s.length();){
        if(s[i]=='|'){
            i++;
            count = 0;
            while(i<s.length() && s[i]!='|'){
                if(s[i]=='*'){
                    count++;
                }
                i++;
            }
            if(i<=s.length()){
                count = 0;
                i++;
                continue;
            }
            else{
                res += count;
                i++;
                count = 0;
                continue;
            }
        }
        else if(s[i]=='*'){
            res++;
            i++;
        }
        else{
            i++;
        }
    }
    return res;
}
int main(){
    string s;
    cin >> s;
    cout << countAsterisks(s) << endl;
    return 0;
}