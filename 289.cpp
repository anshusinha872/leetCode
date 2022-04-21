// 289. Game of Life
//     According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

//     The board is made up of an m x n grid of cells,
//     where each cell has an initial state : live(represented by a 1) or dead(represented by a 0).Each cell interacts with its eight neighbors(horizontal, vertical, diagonal) using the following four rules(taken from the above Wikipedia article) :

//                                                                                                                                                                                                                                                       Any live cell with fewer than two live neighbors dies as if caused by under
//                                                                            - population.Any live cell with two
//                                            or
//                                            three live neighbors lives on to the next generation.Any live cell with more than three live neighbors dies,
// as if by over - population.Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.Given the current state of the m x n grid board, return the next state.

//                                                                                                                                                                                                                                                                                                                                     Example 1 :

//     Input : board = [ [ 0, 1, 0 ], [ 0, 0, 1 ], [ 1, 1, 1 ], [ 0, 0, 0 ] ] Output : [ [ 0, 0, 0 ], [ 1, 0, 1 ], [ 0, 1, 1 ], [ 0, 1, 0 ] ] Example 2 :

//     Input : board = [ [ 1, 1 ], [ 1, 0 ] ] Output : [ [ 1, 1 ], [ 1, 1 ] ]

//                                                     Constraints :

//     m
//     == board.length n
//     == board[i].length 1 <= m,
//             n <= 25 board[i][j] is 0 or 1.

//                                             Follow up :

//     Could you solve it in
//     -
//     place
//                 ? Remember that the board needs to be updated simultaneously
//                 : You cannot update some cells first and then use their updated values to update other cells.In this question,
//             we represent the board using a 2D array.In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array(i.e., live cells reach the border).How would you address these problems ?

#include<bits/stdc++.h>
                                                                                                                                                                                                                                                         using namespace std;
int util(vector<vector<int>> &vect,int row,int col){
    int m = vect.size()-1;
    int n = vect[0].size()-1;
    if(row<0 || row>m || col<0 || col>n || vect[row][col]==0){
        return 0;
    }
    return 1;
}
void gameOfLife(vector<vector<int>> &board){

    int m = board.size();
    int n = board[0].size();
    cout << "M : " << m << " N : " << n << endl;
    vector<vector<int>> vect(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            int live = util(board, i - 1, j - 1) + util(board, i - 1, j) + util(board, i - 1, j + 1) + util(board, i, j + 1) + util(board, i + 1, j + 1) + util(board, i + 1, j) + util(board, i + 1, j - 1) + util(board, i, j - 1);
            // cout << live << " ";
            if(board[i][j]==1){
                if(live<2){
                    vect[i][j] = 0;
                }
                else if(live==2||live==3){
                    vect[i][j] = 1;
                }
                else if(live>3){
                    vect[i][j] = 0;
                }
            }
            else{
                if(live==3){
                    vect[i][j] = 1;
                }
            }
        }
        // cout << endl;
    }
    // cout << endl;
    // cout << "VECTOR" << endl;
    // for (int i = 0; i < m;i++){
    //     for (int j = 0; j < n;j++){
    //         cout << vect[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    board = vect;
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> board[i][j];
        }
    }
    gameOfLife(board);
    return 0;
}