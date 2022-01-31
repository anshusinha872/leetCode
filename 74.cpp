// 74. Search a 2D Matrix
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

#include <bits/stdc++.h>
    using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m, n;
    m = matrix.size();
    // cout<<" M : "<<m<<endl;
    n = matrix[(m - 1)].size();
    // cout<<"n : "<<n<<endl;
    int i = 0, j = n - 1;
    while (i < m && j >= 0)
    {
        if (matrix[i][j] < target)
        {
            i++;
        }
        else if (matrix[i][j] > target)
        {
            j--;
        }
        else if (matrix[i][j] == target)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    // int x,y;
    // cin>>x>>y;
    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // for(int i=0;i<x;i++){
    //     for(int j=0;j<y;j++){
    //         int temp;
    //         cin>>temp;
    //         matrix[i].push_back(temp);
    //     }
    // }
    int target;
    cin >> target;
    cout << searchMatrix(matrix, target);
    return 0;
}