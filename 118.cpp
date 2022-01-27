// 118. Pascal's Triangle
// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]
 

// Constraints:

// 1 <= numRows <= 30
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows){
    vector<vector<int>> vect(numRows);
    int col = 1;
    for (int i = 0; i < numRows;i++){
        for (int j = 0; j < col;j++){
            vect[i].push_back(1);
        }
        col++;
    }
    for (int i = 0; i < numRows;i++){
        for (int j = 0; j < i;j++){
            if(i!=j && j!=0){
                vect[i][j] = vect[i-1][j-1] + vect[i-1][j];
            }
        }
    }
    return vect;
}
int main(){
    int numRows;
    cin >> numRows;
    vector<vector<int>> vect= generate(numRows);
    for (auto itr : vect)
    {
        vector<int> v = itr;
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}