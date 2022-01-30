// 2155. All Divisions With the Highest Score of a Binary Array
//             You are given a 0 -
//         indexed binary array nums of length n.nums can be divided at index i(where 0 <= i <= n) into two arrays(possibly empty) numsleft and numsright :

//     numsleft has all the elements of nums between index 0 and
//     i - 1(inclusive),
//     while numsright has all the elements of nums between index i and n - 1(inclusive).If i == 0, numsleft is empty, while numsright has all the elements of nums.If i == n, numsleft has all the elements of nums, while numsright is empty.The division score of an index i is the sum of the number of 0's in numsleft and the number of 1's in numsright.

//                                                                                                                                                                                                                    Return all distinct indices that have the highest possible division score.You may return the answer in any order.

//                                                                                                                                                                                                                    Example 1 :

//     Input : nums = [ 0, 0, 1, 0 ] Output : [ 2, 4 ] Explanation : Division at index - 0 : numsleft is[].numsright is[0, 0, 1, 0].The score is 0 + 1 = 1. - 1 : numsleft is[0].numsright is[0, 1, 0].The score is 1 + 1 = 2. - 2 : numsleft is[0, 0].numsright is[1, 0].The score is 2 + 1 = 3. - 3 : numsleft is[0, 0, 1].numsright is[0].The score is 2 + 0 = 2. - 4 : numsleft is[0, 0, 1, 0].numsright is[].The score is 3 + 0 = 3. Indices 2 and 4 both have the highest possible division score 3. Note the answer[4, 2] would also be accepted.Example 2 :

//     Input : nums = [ 0, 0, 0 ] Output : [3] Explanation : Division at index - 0 : numsleft is[].numsright is[0, 0, 0].The score is 0 + 0 = 0. - 1 : numsleft is[0].numsright is[0, 0].The score is 1 + 0 = 1. - 2 : numsleft is[0, 0].numsright is[0].The score is 2 + 0 = 2. - 3 : numsleft is[0, 0, 0].numsright is[].The score is 3 + 0 = 3. Only index 3 has the highest possible division score 3. Example 3 :

//     Input : nums = [ 1, 1 ] Output : [0] Explanation : Division at index - 0 : numsleft is[].numsright is[1, 1].The score is 0 + 2 = 2. - 1 : numsleft is[1].numsright is[1].The score is 0 + 1 = 1. - 2 : numsleft is[1, 1].numsright is[].The score is 0 + 0 = 0. Only index 0 has the highest possible division score 2.

//                                                                                                                                                                                                                                                                      Constraints :

//     n
//     == nums.length 1 <= n <= 105 nums[i] is either 0 or 1.

#include <bits/stdc++.h>
using namespace std;
vector<int> maxScoreIndices(vector<int> &nums)
{
    // map<int, int> left,right;
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    int n = nums.size();
    vector<int> left(n + 1), right(n + 1);
    left[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (nums[i - 1] == 0)
        {
            left[i] = left[i - 1] + 1;
        }
        else
        {
            left[i] = left[i - 1];
        }
    }
    vector<int> vect;
    for (int i = 0; i <= n; i++)
    {
        right[i] = (n - i) - (left[n] - left[i]);
        pq.push(make_pair(left[i] + right[i], i));
    }
    int max_num = pq.top().first;
    vect.push_back(pq.top().second);
    pq.pop();
    while (pq.empty() == false)
    {
        auto itr = pq.top();
        if (itr.first == max_num)
        {
            vect.push_back(itr.second);
            pq.pop();
        }
        else if (itr.first < max_num)
            break;
    }
    return vect;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    vector<int> vect = maxScoreIndices(nums);
    // cout << "vector" << endl;
    for (auto x : vect)
    {
        cout << x << " ";
    }
    return 0;
}