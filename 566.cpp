// 566. Reshape the Matrix
//     In MATLAB,
//     there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

//         You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

//         The reshaped matrix should be filled with all the elements of the original matrix in the same row -
//         traversing order as they were.

//         If the reshape operation with given parameters is possible and legal,
//     output the new reshaped matrix;
// Otherwise, output the original matrix.

//            Example 1 :

//     Input : mat = [ [ 1, 2 ], [ 3, 4 ] ],
//             r = 1, c = 4 Output : [[ 1, 2, 3, 4 ]] Example 2 :

//     Input : mat = [ [ 1, 2 ], [ 3, 4 ] ],
//             r = 2, c = 4 Output : [ [ 1, 2 ], [ 3, 4 ] ]

//                                   Constraints :

//     m == mat.length n == mat[i].length 1 <= m,
//             n <= 100 - 1000 <= mat[i][j] <= 1000 1 <= r, c <= 300
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c){
    if(mat.size()*mat[0].size()!=r*c)
        return mat;
    int i = 0;
    vector<vector<int>> vect(r);
    int size = 0;
    for (int x = 0; x < mat.size(); x++)
    {
        for (int y = 0; y < mat[x].size(); y++)
        {
            vect[i].push_back(mat[x][y]);
            size++;
            if(size==c){
                i++;
                size = 0;
            }
        }
    }
    return vect;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m);
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            int temp;
            cin >> temp;
            mat[i].push_back(temp);
        }
    }
    cout << "Original array " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int r, c;
    cin >> r >> c;
    vector<vector<int>> vect = matrixReshape(mat, r, c);
    cout << "Reshaped vector " << endl;
    for(auto itr:vect){
        vector<int> v = itr;
        for(auto i:v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}