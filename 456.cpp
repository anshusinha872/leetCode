#include<bits/stdc++.h>
using namespace std;
// bool myCmp(pair<int,int> s1,pair<int,int> s2){
//     return s1.second < s2.second;
// }
bool find132pattern(vector<int> &nums){
    int n = nums.size();
    for (int i = 0; i < n-2; i++){
        for (int j = i + 1; j < n-1;j++){
            for (int k = j + 1; k < n;k++){
                if(nums[i]<nums[k] && nums[k]<nums[j] ){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n;i++){
            cin>>nums[i];
        }
        cout << find132pattern(nums) << endl;
    }
    return 0;

}