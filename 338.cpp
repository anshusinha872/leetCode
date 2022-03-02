#include<bits/stdc++.h>
using namespace std;
vector<int> countBits(int n){
    vector<int> vect;
    for (int i = 0; i <= n;i++){
        if(i==0)
        {
            vect.push_back(0);
            continue;
        }    
        else if((i&(i-1))==0){
            vect.push_back(1);
            continue;
        }
        else if(i%2==0)
            {
                vect.push_back(1+vect[(i&(i-1))]);
                continue;
            }
        else if(i%2!=0)
            {vect.push_back(vect[i - 1] + 1);
                continue;
            }
    }
    for(int x:vect){
        cout << x << " ";
    }
    // cout << (4 & 3) << endl ;
    return vect;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    nums = countBits(n);
    return 0;
}