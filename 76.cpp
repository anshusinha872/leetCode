#include<bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    string ans = "";
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for(auto c:t){
        mp2[c]++;
    }
    int i = 0, j = 0;
    int matched_count = 0;
    int desired_count = t.length();
    while(true){
        bool flag1 = false;
        bool flag2= false;
        // acquire
        while(i<s.length() && matched_count<desired_count){
            mp1[s[i]]++;
            if(mp1[s[i]]<=mp2[s[i]]){
                matched_count++;
            }
            i++;
            flag1 = true;
        }
        // collect answer and release
        while(j<i && matched_count==desired_count){
            string pans = s.substr(j, i - j);
            if (ans.length() == 0 || ans.length() > pans.length()){
                ans = pans;
            }
            if(mp1[s[j]]==0){
                mp1.erase(s[j]);
            }
            else{
                mp1[s[j]]--;
            }
            if(mp1[s[j]]<mp2[s[j]]){
                matched_count--;
            }
            j++;
            flag1 = true;
        }
        if(flag1==false && flag2==false){
            break;
        }
    }
    return ans;
}
int main(){
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}
