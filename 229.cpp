class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        vector<int> vect;
        for (auto itr : mp)
        {
            if (itr.second * 3 > nums.size())
            {
                vect.push_back(itr.first);
            }
        }
        return vect;
    }
};