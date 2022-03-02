#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums,int val)
{
    sort(nums.begin(), nums.end());
    set<int> set;
    for (int x : nums)
    {
        if (set.find(x) == set.end() && x!=val)
        {
            set.insert(x);
        }
    }
    int i = 0;
    // nums.clear();
    while(val>0){
        if(nums[i]!=val){
            cout << nums[i] << " ";
            val--;
        }
        i++;
    }
    return set.size();
}
int main()
{
    int n;
    cin >> n;
    int val;
    cin >> val;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << removeDuplicates(nums,val) << endl;
    return 0;
}