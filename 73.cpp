// 73. Set Matrix Zeroes
//     Given an m x n integer matrix matrix,
//     if an element is 0, set its entire row and column to 0's.

//                         You must do it in place.

//                         Example 1 :

//     Input : matrix = [ [ 1, 1, 1 ], [ 1, 0, 1 ], [ 1, 1, 1 ] ] Output : [ [ 1, 0, 1 ], [ 0, 0, 0 ], [ 1, 0, 1 ] ] Example 2 :

//     Input : matrix = [ [ 0, 1, 2, 0 ], [ 3, 4, 5, 2 ], [ 1, 3, 1, 5 ] ] Output : [ [ 0, 0, 0, 0 ], [ 0, 4, 5, 0 ], [ 0, 3, 1, 0 ] ]

//                                                                                  Constraints :

//     m == matrix.length n == matrix[0].length 1 <= m,
//             n <= 200 - 231 <= matrix[i][j] <= 231 - 1

#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    bool row_zero = false;
    bool column_zero = false;
    for (int i = 0; i < m;i++){
        if(matrix[i][0]==0){
            column_zero = true;
        }
    }
    for (int i = 0; i < n;i++){
        if(matrix[0][i]==0){
            row_zero = true;
        }
    }
    for (int i = 1; i < m;i++){
        for (int j = 1; j < n;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < m;i++){
        if(matrix[i][0]==0){
            for (int j = 1; j < n;j++){
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 1; j < n;j++){
        if(matrix[0][j]==0){
            for (int i = 1; i < m;i++){
                matrix[i][j] = 0;

            }
        }
    }
    if(row_zero){
        for (int i = 0; i < n;i++){
            matrix[0][i] = 0;
        }
    }
    if(column_zero){
        for (int j = 0; j < m;j++){
            matrix[j][0] = 0;
        }
    }
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> matrix[i][j];
        }
    }
    setZeroes(matrix);
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}