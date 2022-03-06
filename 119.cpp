// 119. Pascal's Triangle II Easy

//     2310

//     258

//     Add to List

//         Share
//             Given an integer rowIndex,
//     return the rowIndexth(0 - indexed) row of the Pascal's triangle.

//            In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

//            Example 1 :

//     Input : rowIndex = 3 Output : [ 1, 3, 3, 1 ] Example 2 :

//     Input : rowIndex = 0 Output : [1] Example 3 :

//     Input : rowIndex = 1 Output : [ 1, 1 ]

//                                   Constraints :

//                                   0 <= rowIndex <= 33

#include<bits/stdc++.h>
using namespace std;
// space complexity = O(rowIndex)
vector<int> getRow(int rowIndex){
    vector<int> vect(rowIndex+1,1);
    vector<int> temp(rowIndex + 1, 1);
    for (int i = 2; i <= rowIndex;i++){
        for (int j = 1; j < i;j++){
            vect[j] = temp[j - 1] + temp[j];
        }
        temp = vect;
    }
    return vect;
}
int main(){
    int rowIndex;
    cin >> rowIndex;
    vector<int> vect = getRow(rowIndex);
    for(auto x:vect)
        cout << x << " ";
    return 0;
}