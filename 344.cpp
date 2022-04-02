// 344. Reverse String
//         Write a function that reverses a string.The input string is given as an array of characters s.

//     You must do this by modifying the input array in -
//     place with O(1) extra memory.Example 1 :

//     Input : s = [ "h", "e", "l", "l", "o" ] Output : [ "o", "l", "l", "e", "h" ] Example 2 :

//     Input : s = [ "H", "a", "n", "n", "a", "h" ] Output : [ "h", "a", "n", "n", "a", "H" ]

//  Constraints :

//                                                           1 <= s.length
//                                                           <= 105 s[i] is a printable ascii character.

#include<bits/stdc++.h>
using namespace std;
void reverseString(vector<char> &s){
    int n = s.size();
    int i = 0, j = n - 1;
    while(i<=j){
        swap(s[i], s[j]);
        i++;
        j--;
    }
    for(auto itr:s){
        cout << itr << " ";
    }
}
int main(){
    int n;
    cin >> n;
    // vector<char> s{'h','e','l','l','o'};
    vector<char> s(n);
    for (int i = 0; i < n;i++){
        cin >> s[i];
    }
    reverseString(s);
    return 0;
}