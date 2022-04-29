// 221. Maximal Square
//         Given an m x n binary matrix filled with 0's and
//     1's,
//     find the largest square containing only 1's and return its area.

//     Example 1 :

//     Input : matrix = [ [ "1", "0", "1", "0", "0" ], [ "1", "0", "1", "1", "1" ], [ "1", "1", "1", "1", "1" ], [ "1", "0", "0", "1", "0" ] ] Output : 4 Example 2 :

//     Input : matrix = [ [ "0", "1" ], [ "1", "0" ] ] Output : 1 Example 3 :

//     Input : matrix = [["0"]] Output : 0

//                      Constraints :

//     m == matrix.length n == matrix[i].length 1 <= m,
//             n <= 300 matrix[i][j] is '0' or '1'.
#include<bits/stdc++.h>
using namespace std;
int maxima_square_util(vector<int> &matrix){
    vector<int> ns;
    vector<int> ps;
    int n = matrix.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (st.empty() == false && (matrix[st.top()]) >= (matrix[i]))
        {
            st.pop();
        }
        int res = st.empty() ? -1 : st.top();
        ps.push_back(res);
        st.push(i);
    }
    while (st.empty() == false)
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.empty() == false && (matrix[st.top()]) >= (matrix[i]))
        {
            st.pop();
        }
        int res = st.empty() ? n : st.top();
        ns.push_back(res);
        st.push(i);
    }
    reverse(ns.begin(), ns.end());
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int left = ps[i];
        int right = ns[i];
        int width = (right - left) - 1;
        int temp = min(width, matrix[i]);
        res = max(res, temp * temp);
    }
    return res;
}
int maximalSquare(vector<vector<char>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> res_vect(m, 0);
    for (int i = 0; i < m; i++){
        res_vect[i] = matrix[0][i] - '0';
    }
    int res = maxima_square_util(res_vect);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                res_vect[j] = (matrix[i][j] - '0') + res_vect[j];
            }
            else if (matrix[i][j] == '0')
            {
                res_vect[j] = 0;
            }
        }
        res = max(res, maxima_square_util(res_vect));
    }
    return res;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>>vect(n, vector<char>(m));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> vect[i][j];
        }
    }
    cout << maximalSquare(vect) << endl;
    return 0;
}