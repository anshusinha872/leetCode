#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int k = nums.size() - 1; k > 1; k--)
        {
            for (int i = 0, j = k - 1; i < j;)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    count += j - i;
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return count;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
        cin >> nums[i];
    }

}