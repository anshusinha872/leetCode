// 885. Spiral Matrix III
//     You start at the
//     cell(rStart, cStart)
// of an rows x cols grid facing east.The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

//                                                                                                         You will walk in a clockwise spiral shape to visit every position in this grid.Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

//                                                                                                         Return an array of coordinates representing the positions of the grid in the order you visited them.

//                                                                                                         Example 1 :

//     Input : rows = 1,
//             cols = 4, rStart = 0, cStart = 0 Output : [ [ 0, 0 ], [ 0, 1 ], [ 0, 2 ], [ 0, 3 ] ] Example 2 :

//     Input : rows = 5,
//             cols = 6, rStart = 1, cStart = 4 Output : [ [ 1, 4 ], [ 1, 5 ], [ 2, 5 ], [ 2, 4 ], [ 2, 3 ], [ 1, 3 ], [ 0, 3 ], [ 0, 4 ], [ 0, 5 ], [ 3, 5 ], [ 3, 4 ], [ 3, 3 ], [ 3, 2 ], [ 2, 2 ], [ 1, 2 ], [ 0, 2 ], [ 4, 5 ], [ 4, 4 ], [ 4, 3 ], [ 4, 2 ], [ 4, 1 ], [ 3, 1 ], [ 2, 1 ], [ 1, 1 ], [ 0, 1 ], [ 4, 0 ], [ 3, 0 ], [ 2, 0 ], [ 1, 0 ], [ 0, 0 ] ]

//                                                       Constraints :

//                                                       1 <= rows,
//             cols <= 100 0 <= rStart < rows 0 <= cStart < cols

#include<bits/stdc++.h>
                using namespace std;
void util(vector<vector<int>> &vect,int M,int N,int row,int col,int &size){
    if(row<0 ||row>=M || col<0 ||col>=N){
        return;
    }
    size++;
    vect.push_back({row, col});
}
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart){
    vector<vector<int>> res;
    int M = rows;
    int N = cols;
    int distance = 1;
    int size = 0;
    size++;
    res.push_back({rStart, cStart});
    while(size<rows*cols){
        for (int i = 1; i <= distance;i++){
            cStart++;
            util(res, M, N, rStart, cStart,size);
        }
        for (int i = 1; i <= distance;i++){
            rStart++;
            util(res, M, N, rStart, cStart,size);
        }
        distance++;
        for (int i = 1; i <= distance;i++){
            cStart--;
            util(res, M, N, rStart, cStart, size);
        }
        for (int i = 1; i <= distance;i++){
            rStart--;
            util(res, M, N, rStart, cStart, size);
        }
        distance++;
    }
    return res;
}
int main(){
    int rows, cols, rStart, cStart;
    cin >> rows >> cols >> rStart >> cStart;
    // vector<vector<int>> vect;
    vector<vector<int>> vect(rows * cols, vector<int>(2));
    vect=spiralMatrixIII(rows, cols, rStart, cStart);
    for(auto itr:vect){
        cout << '[';
        for(auto x:itr){
            cout << x <<',';
        }
        cout << ']'<<" ,\t";
    }
    return 0;
}