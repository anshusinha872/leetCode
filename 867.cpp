// 867. Transpose Matrix
//     Given a 2D integer array matrix,
//     return the transpose of matrix.

//     The transpose of a matrix is the matrix flipped over its main diagonal,
//     switching the matrix's row and column indices.

//     Example 1 :

//     Input : matrix = [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ] ] Output : [ [ 1, 4, 7 ], [ 2, 5, 8 ], [ 3, 6, 9 ] ] Example 2 :

//     Input : matrix = [ [ 1, 2, 3 ], [ 4, 5, 6 ] ] Output : [ [ 1, 4 ], [ 2, 5 ], [ 3, 6 ] ]

//                                                            Constraints :

//     m == matrix.length n == matrix[i].length 1 <= m,
//             n <= 1000 1 <= m *n <= 105 - 109 <= matrix[i][j] <= 109
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> transpose(vector<vector<int>> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> trans_mat(n, vector<int>(m, 0));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            trans_mat[i][j] = matrix[j][i];
        }
    }
    return trans_mat;
}
int main(){
    int m,n;
    cin >> m>>n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> matrix[i][j];
        }
    }
    matrix=transpose(matrix);
    cout << endl;
    // m = matrix.size();
    // int n = matrix[0].size();
    for (int i = 0; i < n;i++){
        for (int j = 0; j <m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}