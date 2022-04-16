// 498. Diagonal Traverse
//     Given an m x n matrix mat,
//     return an array of all the elements of the array in a diagonal order.

//            Example 1 :

//     Input : mat = [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ] ] Output : [ 1, 2, 4, 7, 5, 3, 6, 8, 9 ] Example 2 :

//     Input : mat = [ [ 1, 2 ], [ 3, 4 ] ] Output : [ 1, 2, 3, 4 ]

//                                                   Constraints :

//     m == mat.length n == mat[i].length 1 <= m,
//             n <= 104 1 <= m *n <= 104 - 105 <= mat[i][j] <= 105
#include<bits/stdc++.h>
                using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>> &mat){
    int m = mat.size();
    int n=mat[0].size();
    if(m==0){
        return {};
    }
    vector<int> vect;
    for (int s = 0; s <= m + n - 2;s++){
        for (int x = 0; x <= s;x++){
            int i = x;
            int j = s - i;
            if(s%2==0){
                swap(i, j);
            }
            if(i>=m ||j>=n){
                continue;
            }
            vect.push_back(mat[i][j]);
        }
    }
    return vect;
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
    vector<int> res;
    res = findDiagonalOrder(matrix);
    cout << endl;
    cout << "VECTOR" << endl;
    for(auto x:res){
        cout << x << " ";
    }
    return 0;
}