// 383. Ransom Note
//     Given two strings ransomNote and magazine,
//     return true if ransomNote can be constructed from magazine and false otherwise.

//            Each letter in magazine can only be used once in ransomNote.

//            Example 1 :

//     Input : ransomNote = "a",
//             magazine = "b" Output : false Example 2 :

//     Input : ransomNote = "aa",
//             magazine = "ab" Output : false Example 3 :

//     Input : ransomNote = "aa",
//             magazine = "aab" Output : true


#include<bits/stdc++.h>
using namespace std;
bool canConstruct(string ransomNote, string magazine){
    vector<int> vect(27, 0);
    for (int i = 0; i < magazine.length();i++){
        vect[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.length();i++){
        if(vect[ransomNote[i]-'a']==0)
            return false;
        else if(vect[ransomNote[i]-'a']!=0)
            vect[ransomNote[i] -'a']--;
    }
    return true;
}
int main()
{
    string ransomNote, magazine;
    cin >> ransomNote >> magazine;
    cout << canConstruct(ransomNote,magazine);
    return 0;
}