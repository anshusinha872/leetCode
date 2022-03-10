// 43. Multiply Strings
//         Given two non -
//     negative integers num1 and num2 represented as strings,
//     return the product of num1 and num2, also represented as a string.

//                                                  Note : You must not use any built -
//                                                  in BigInteger library or
//                                              convert the inputs to integer directly.

//                                              Example 1 :

//     Input : num1 = "2",
//             num2 = "3" Output : "6" Example 2 :

//     Input : num1 = "123",
//             num2 = "456" Output : "56088"

#include<bits/stdc++.h>
using namespace std;
string addStrings(string num1, string num2)
{
    string str;
    int n = num1.length();
    int m = num2.length();
    int carry = 0;
    int sum = 0;
    while (n > 0 && m > 0)
    {
        sum = num1[n - 1] + num2[m - 1] - '0' - '0';
        sum = sum + carry;
        carry = sum / 10;
        sum = sum % 10;
        char temp = sum + '0';
        str.push_back(temp);
        n--;
        m--;
    }
    while (n > 0)
    {
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
    while (carry > 0)
    {
        char temp = carry + '0';
        str.push_back(temp);
        carry = carry / 10;
    }
    reverse(str.begin(), str.end());
    return str;
}
string multiply(string str1, string str2)
{
    int carry = 0, sum = 0;
    string res;
    string str;
    int interation = 0;
    if(str1=="0" || str2=="0")
        return "0";
    for (int i = str2.length() - 1; i >= 0; i--)
    {
        for (int j = str1.length() - 1; j >= 0; j--)
        {
            sum = (str2[i] - '0') * (str1[j] - '0');
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            char temp = sum + '0';
            str.push_back(temp);
        }
        if (carry != 0)
            str.push_back(carry + '0');
        carry = 0;
        sum = 0;

        reverse(str.begin(), str.end());
        for (int k = 1; k <= interation; k++)
        {
            str.push_back('0');
        }
        interation++;
        // cout << str << endl;
        res = addStrings(res, str);
        str = "";
    }
    return res;
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    cout << multiply(str1, str2) << endl;
    return 0;
}