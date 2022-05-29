#include<bits/stdc++.h>
using namespace std;

void subarraysWithKDistinct_util(int start, vector<int> &nums, int k, map<vector<pair<int, int>>, int> &st, int end)
{
    map<int, int> mp;
    int count = 0;
    int i = 0, j = 0;
    vector<pair<int,int>> temp;
    while(j<nums.size()){
        mp[nums[j]]++;
        if(mp.size()<k){
            j++;
        }
        else if(mp.size()==k){
            temp.clear();
            for (int x = i; x <=j;x++){
                temp.push_back({nums[x], x+start});
            }
            cout << endl;
            for (auto itr : temp)
            {
                cout << itr.first << " " << itr.second << endl;
            }
            cout << endl;
            st[temp]++;
            temp.clear();
            j++;
        }
        else if(mp.size()>k){
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            if(mp.size()==k){
                for (int x = i; x <=j; x++)
                {
                    temp.push_back({nums[x], x+start});
                }
                cout << endl;
                for(auto itr:temp){
                    cout << itr.first << " " << itr.second << endl;
                }
                cout << endl;
                st[temp]++;
                temp.clear();
            }
            j++;
        }
    }
}
int subarraysWithKDistinct(vector<int> &nums, int k){
    int n=nums.size();
    map<vector<pair<int,int>>,int> st;
    for (int i = 0; i<= n-k;i++){
        vector<int> res;
        for (int j = i; j < n;j++){
            res.push_back(nums[j]);
        }
        subarraysWithKDistinct_util(i, res, k, st, n);
        // for(auto x:res){
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    return st.size();
}
int main(){
    int n,k;
    cin >> n>>k;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }
    cout << subarraysWithKDistinct(nums, k) << endl;
    return 0;
}