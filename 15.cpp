#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> vect;
    set<vector<int>> hs;
    for (int i = 0; i < nums.size();i++){
        int sum = -nums[i];
        set<int> s;
        for (int j = i + 1; j < nums.size();j++){
            if(s.find(sum-nums[j])!=s.end()){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(sum - nums[j]);
                sort(temp.begin(), temp.end());
                if(hs.find(temp)==hs.end()){
                    hs.insert(temp);
                }
            }
            else
                s.insert(nums[j]);
        }
    }
    for(auto itr:hs){
        vect.push_back(itr);
    }
    return vect;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    vector<vector<int>> vect = threeSum(nums);
    for(auto x:vect){
        vector<int> vect = x;
        for(int i:vect){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}