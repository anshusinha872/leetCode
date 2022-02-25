// 1512. Number of Good Pairs
//     Given an array of integers nums,
//     return the number of good pairs.

//     A
//     pair(i, j)
// is called good if nums[i] == nums[j] and i < j.

//                                              Example 1 :

//     Input : nums = [ 1, 2, 3, 1, 1, 3 ] Output : 4 Explanation : There are 4 good pairs(0, 3),
//             (0, 4), (3, 4), (2, 5)0 - indexed.Example 2 :

//     Input : nums = [ 1, 1, 1, 1 ] Output : 6 Explanation : Each pair in the array are good.Example 3 :

//     Input : nums = [ 1, 2, 3 ] Output : 0
#include<bits/stdc++.h>
using namespace std;
int numIdenticalPairs(int arr[],int n){
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    int n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    cout << numIdenticalPairs(arr, n);
    return 0;
}