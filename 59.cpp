// 59. Spiral Matrix II
//     Given a positive integer n,
//     generate an n x n matrix filled with elements from 1 to n2 in spiral order.

//     Example 1 :

//     Input : n = 3 Output : [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ] Example 2 :

//     Input : n = 1 Output : [[1]]

//                            Constraints :

//                            1 <= n <= 20

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generateMatrix(int n){
    // int arr[n][n];
    vector<vector<int>> vect(n, vector<int>(n));
    int k = 1;
    int row_start = 0, row_end = n - 1, col_start = 0, col_end = n - 1;
    while(row_start<=row_end && col_start<=col_end){
        for (int j = col_start; j <= col_end;j++){
            vect[row_start][j] = k;
            k++;
        }
        row_start++;
        for (int i = row_start; i <= row_end;i++){
            vect[i][col_end] = k;
            k++;
        }
        col_end--;

        for (int j = col_end; j >= col_start;j--){
            vect[row_end][j] = k;
            k++;
        }
        row_end--;
        for (int i = row_end; i >= row_start;i--){
            vect[i][col_start] = k;
            k++;
        }
        col_start++;
    }
    return vect;
}
int main(){
    int n;
    cin >> n;
    generateMatrix(n);
    return 0;

}