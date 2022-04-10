// 12. Integer to Roman
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.

 

// Example 1:

// Input: num = 3
// Output: "III"
// Explanation: 3 is represented as 3 ones.
// Example 2:

// Input: num = 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
// Example 3:

// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

// Constraints:

// 1 <= num <= 3999

#include<bits/stdc++.h>
    using namespace std;
string intToRoman(int num){
    string str;
    int count = 0;
    string str_num = to_string(num);
    unordered_map<int, string> mp;
    mp.insert({1, "I"});
    mp.insert({2, "II"});
    mp.insert({3, "III"});
    mp.insert({4, "IV"});
    mp.insert({5, "V"});
    mp.insert({6, "VI"});
    mp.insert({7, "VII"});
    mp.insert({8, "VIII"});
    mp.insert({9, "IX"});
    mp.insert({10, "X"});
    mp.insert({20, "XX"});
    mp.insert({30, "XXX"});
    mp.insert({40, "XL"});
    mp.insert({50, "L"});
    mp.insert({60, "LX"});
    mp.insert({70, "LXX"});
    mp.insert({80, "LXXX"});
    mp.insert({90, "XC"});
    mp.insert({100, "C"});
    mp.insert({200, "CC"});
    mp.insert({300, "CCC"});
    mp.insert({400, "CD"});
    mp.insert({500, "D"});
    mp.insert({600, "DC"});
    mp.insert({700, "DCC"});
    mp.insert({800, "DCCC"});
    mp.insert({900, "CM"});
    mp.insert({1000, "M"});
    mp.insert({2000, "MM"});
    mp.insert({3000, "MMM"});
    if(num>=1 && num<=9){
        count = 1;
    }
    else if(num>=10 && num<=99){
        count = 2;
    }
    else if(num>=100 && num<=999){
        count = 3;
    }
    else{
        count = 4;
    }
    for (int i = 0; i < str_num.length();i++){
        int res = (str_num[i]-'0');
        int temp = count - 1;
        while(temp--){
            res = res * 10;
        }
        count--;
        str = str + mp[res];
    }
    return str;
}
int main(){
    int n;
    cin >> n;
    cout << intToRoman(n) << endl;
    return 0;
}