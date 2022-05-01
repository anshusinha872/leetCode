// 66. Plus One
//     You are given a large integer represented as an integer array digits,
//     where each digits[i] is the ith digit of the integer.The digits are ordered from most significant to least significant in left - to - right order.The large integer does not contain any leading 0's.

//                                                                                                                                           Increment the large integer by one and return the resulting array of digits.

//                                                                                                                                           Example 1 :

//     Input : digits = [ 1, 2, 3 ] Output : [ 1, 2, 4 ] Explanation : The array represents the integer 123. Incrementing by one gives 123 + 1 = 124. Thus,
//             the result should be[1, 2, 4].Example 2 :

//     Input : digits = [ 4, 3, 2, 1 ] Output : [ 4, 3, 2, 2 ] Explanation : The array represents the integer 4321. Incrementing by one gives 4321 + 1 = 4322. Thus,
//             the result should be[4, 3, 2, 2].Example 3 :

//     Input : digits = [9] Output : [ 1, 0 ] Explanation : The array represents the integer 9. Incrementing by one gives 9 + 1 = 10. Thus,
//             the result should be[1, 0].
#include<bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> &digits){
    int num = 0;
    int n = digits.size();
    digits[n-1] = digits[n-1] + 1;

    int carry = (digits[n - 1]) / 10;

    digits[n - 1] = digits[n - 1] % 10;

    for (int i = n - 2; i >= 0 && carry!=0;i--){
        digits[i] = digits[i] + carry ;
        carry = digits[i] / 10;
        digits[i] = digits[i] % 10;
    }
    if(carry){
        vector<int> vect;
        vect.push_back(carry);
        for(int x:digits){
            vect.push_back(x);
        }
        return vect;
    }
    return digits;
}
int main(){
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n;i++){
        cin >> digits[i];
    }
    digits = plusOne(digits);
    for(int x:digits){
        cout << x << " ";
    }
    return 0;
}