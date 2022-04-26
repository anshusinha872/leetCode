// 367. Valid Perfect Square
//     Given a positive integer num,
//     write a function which returns True if num is a perfect square else False.

//         Follow up : Do not use any built -
//         in library function such as sqrt.

//         Example 1 :

//     Input : num = 16 Output : true Example 2 :

//     Input : num = 14 Output : false
#include<bits/stdc++.h>
using namespace std;
int mySqrt(int x)
{
    int l = 0, r = x;
    if (x == 0 || x == 1)
    {
        return x;
    }
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (mid == x / mid)
        {
            return mid;
        }
        else if (mid < x / mid)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
bool isPerfectSquare(int num){
    int x = mySqrt(num);
    if(x*x==num){
        return true;
    }
    return false;
}
int main(){
    int x;
    cin >> x;
    cout << isPerfectSquare(x) << endl;
    return 0;
}