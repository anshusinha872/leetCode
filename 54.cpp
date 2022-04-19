// 54. Spiral Matrix
//     Given an m x n matrix,
//     return all elements of the matrix in spiral order.

//            Example 1 :

//     Input : matrix = [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ] ] Output : [ 1, 2, 3, 6, 9, 8, 7, 4, 5 ] Example 2 :

//     Input : matrix = [ [ 1, 2, 3, 4 ], [ 5, 6, 7, 8 ], [ 9, 10, 11, 12 ] ] Output : [ 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 ]

//                                                                                     Constraints :

//     m == matrix.length n == matrix[i].length 1 <= m,
//             n <= 10 - 100 <= matrix[i][j] <= 100

#include<bits/stdc++.h>
                using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector < vector<bool>>check(m, vector<bool>(n, false));
    vector<int> vect;
    int row_start = 0, row_end = m - 1, col_start = 0, col_end = n - 1;
    while (row_start <= row_end && col_start <= col_end)
    {
        for (int j = col_start; j <= col_end; j++)
        {
            if(!check[row_start][j]){
                vect.push_back(matrix[row_start][j]);
                check[row_start][j] = true;
            }
        }
        row_start++;
        for (int i = row_start; i <= row_end; i++)
        {
            if(!check[i][col_end]){
                vect.push_back(matrix[i][col_end]);
                check[i][col_end] = true;
            }
        }
        col_end--;

        for (int j = col_end; j >= col_start; j--)
        {
            if(!check[row_end][j]){

            vect.push_back(matrix[row_end][j]);
            check[row_end][j] = true;
            }
        }
        row_end--;
        for (int i = row_end; i >= row_start; i--)
        {
            if(!check[i][col_start]){

            vect.push_back(matrix[i][col_start]);
            check[i][col_start] = true;
            }
        }
        col_start++;
    }
    return vect;
}
int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> vect = spiralOrder(matrix);
    for(auto x:vect){
        cout << x << " ";
    }
    return 0;
}