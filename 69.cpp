// 69. Sqrt(x)
//         Given a non
//     - negative integer x,
//     compute and return the square root of x.

//     Since the return type is an integer,
//     the decimal digits are truncated, and only the integer part of the result is returned.

//                                               Note : You are not allowed to use any built
//                                               - in exponent function
//                                           or operator,
//     such as pow(x, 0.5) or x ** 0.5.

//         Example 1 :

//     Input : x = 4 Output : 2 Example 2 :

//     Input : x = 8 Output : 2 Explanation : The square root of 8 is 2.82842...,
//             and since the decimal part is truncated, 2 is returned.

#include<bits/stdc++.h>
using namespace std;
int mySqrt(int x){
    int l = 0, r = x;
    if(x==0||x==1){
        return x;
    }
    int ans = 0;
    while(l<=r){
        int mid = (l + r) / 2;
        if(mid==x/mid){
            return mid;
        }
        else if(mid<x/mid){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;
}
int main(){
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;
    return 0;
}