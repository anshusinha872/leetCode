#include<bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char> &letters, char target){
    auto it = upper_bound(letters.begin(), letters.end(), target);
    return it == letters.end() ? letters[0] : *it;
}
int main(){
    // int n;
    // cin >> n;
    vector<string> vect={"c","f","j"};
    // for (int i = 0; i < n;i++){
    //     cin >> vect[i];
    // }
    char target;
    cin >> target;
    cout<<nextGreatestLetter(vect, target) << endl;
    return 0;
}