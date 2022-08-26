// 869. Reordered Power of 2 You are given an integer n.We reorder the digits in any order(including the original order) such that the leading digit is not zero.

//     Return true if and only if we can do this so that the resulting number is a power of two.

//     Example 1 :

//     Input : n = 1 Output : true Example 2 :

//     Input : n = 10 Output : false

#include<bits/stdc++.h>
                            using namespace std;
vector<int> countDigit(int n){
    vector<int> vect(10);
    while(n>0){
        vect[n % 10]++;
        n = n / 10;
    }
    return vect;
}
bool reorderedPowerOf2(int N){
    vector<int> count = countDigit(N);
    int num = 1;
    for (int i = 0; i < 31;i++){
        if(count==countDigit(num)){
            return true;
        }
        num = num << 1;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    cout << reorderedPowerOf2(n) << endl;
}