// 415. Add Strings
// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"
// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"
// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"

#include<bits/stdc++.h>
    using namespace std;
string addStrings(string num1, string num2){
    string str;
    int n = num1.length();
    int m = num2.length();
    int carry = 0;
    int sum = 0;
    while(n>0 && m>0){
        sum = num1[n - 1] + num2[m - 1] - '0' - '0';
        sum = sum + carry;
        carry = sum / 10;
        sum = sum % 10;
        char temp= sum+'0';
        str.push_back(temp);
        n--;
        m--;
    }
    while(n>0){
        sum = num1[n - 1] - '0';
        sum = sum + carry;
        carry = sum / 10;
        sum = sum % 10;
        char temp = sum + '0';
        str.push_back(temp);
        n--;
    }
    while (m > 0)
    {
        sum = num2[m - 1] - '0';
        sum = sum + carry;
        carry = sum / 10;
        sum = sum % 10;
        char temp = sum + '0';
        str.push_back(temp);
        m--;
    }
    while(carry>0){
        char temp = carry + '0';
        str.push_back(temp);
        carry = carry / 10;
    }
    reverse(str.begin(), str.end());
    return str;
}
int main(){
    string num1, num2;
    cin >> num1 >> num2;
    cout << addStrings(num1, num2) << endl;
    return 0;
}