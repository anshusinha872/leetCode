#include<bits/stdc++.h>
using namespace std;
int kthSmallest(vector<vector<int>> &matrix, int k){
    int n = matrix.size();
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            pq.push(matrix[i][j]);
        }
    }
    for (int i = 0; i < n * n;i++){
        if(i == k - 1){
            return pq.top();
        }
        pq.pop();
    }
    return -1;
}
int main(){
    int n,k;
    cin >> n>>k;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cin >> matrix[i][j];
        }
    }
    cout << kthSmallest(matrix, k) << endl;
    return 0;
}