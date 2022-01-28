// 36. Valid Sudoku
//         Determine if a 9 x 9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules :

//     Each row must contain the digits 1 -
//     9 without repetition.Each column must contain the digits 1 - 9 without repetition.Each of the nine 3 x 3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.Note :

//     A Sudoku
//     board(partially filled) could be valid but is not necessarily solvable.Only the filled cells need to be validated according to the mentioned rules.

//     Example 1 :

//     Input : board =
//     [ [ "5", "3", ".", ".", "7", ".", ".", ".", "." ], [ "6", ".", ".", "1", "9", "5", ".", ".", "." ], [ ".", "9", "8", ".", ".", ".", ".", "6", "." ], [ "8", ".", ".", ".", "6", ".", ".", ".", "3" ], [ "4", ".", ".", "8", ".", "3", ".", ".", "1" ], [ "7", ".", ".", ".", "2", ".", ".", ".", "6" ], [ ".", "6", ".", ".", ".", ".", "2", "8", "." ], [ ".", ".", ".", "4", "1", "9", ".", ".", "5" ], [ ".", ".", ".", ".", "8", ".", ".", "7", "9" ] ] Output : true Example 2 :

//     Input : board =
//                 [ [ "8", "3", ".", ".", "7", ".", ".", ".", "." ], [ "6", ".", ".", "1", "9", "5", ".", ".", "." ], [ ".", "9", "8", ".", ".", ".", ".", "6", "." ], [ "8", ".", ".", ".", "6", ".", ".", ".", "3" ], [ "4", ".", ".", "8", ".", "3", ".", ".", "1" ], [ "7", ".", ".", ".", "2", ".", ".", ".", "6" ], [ ".", "6", ".", ".", ".", ".", "2", "8", "." ], [ ".", ".", ".", "4", "1", "9", ".", ".", "5" ], [ ".", ".", ".", ".", "8", ".", ".", "7", "9" ] ] Output : false Explanation : Same as Example 1,
//             except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub - box, it is invalid.
#include<bits/stdc++.h>
using namespace std;
bool is_valid_row(int row, vector<vector<char>> &board){
    set<char> st;
    for (int col = 0; col < 9;col++){
        if(st.find(board[row][col])!=st.end())
            return false;
        if(board[row][col]!='.')
            st.insert(board[row][col]);
    }
    return true;
}
bool is_valid_col(int col, vector<vector<char>> &board){
    set<char> st;
    for (int row = 0; row < 9; row++)
    {
        if (st.find(board[row][col]) != st.end())
            return false;
        if (board[row][col] != '.')
            st.insert(board[row][col]);
    }
    return true;
}
bool is_valid_block(int start_row,int start_col, vector<vector<char>> &board){
    set<char> st;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            char curr = board[row + start_row][col + start_col];
            if (st.find(curr) != st.end())
                return false;
            if (curr != '.')
                st.insert(curr);
        }
    }
    return true;
}
bool isValid(vector<vector<char>> &board,int row,int col){
    return is_valid_row(row, board) && is_valid_col(col, board) && is_valid_block(row - row % 3, col - col % 3, board);
}
bool isValidSudoku(vector<vector<char>> &board){
    for (int i = 0; i < 9;i++){
        for (int j = 0; j < 9;j++){
            if(!isValid(board,i,j))
                return false;
        }
    }
    return true;
}
int main(){
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    cout<<isValidSudoku(board);
}