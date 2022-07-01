// 1710. Maximum Units on a Truck
//     You are assigned to put some amount of boxes onto one truck.You are given a 2D array boxTypes,
//     where boxTypes[i] = [ numberOfBoxesi, numberOfUnitsPerBoxi ] :

//     numberOfBoxesi is the number of boxes of type i.numberOfUnitsPerBoxi is the number of units in each box of the type i.You are also given an integer truckSize,
//           which is the maximum number of boxes that can be put on the truck.You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

//           Return the maximum total number of units that can be put on the truck.

//           Example 1 :

//     Input : boxTypes = [ [ 1, 3 ], [ 2, 2 ], [ 3, 1 ] ],
//           truckSize = 4 Output : 8 Explanation : There are : -1 box of the first type that contains 3 units.- 2 boxes of the second type that contain 2 units each.- 3 boxes of the third type that contain 1 unit each.You can take all the boxes of the first and second types, and one box of the third type.The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8. Example 2 :

//     Input : boxTypes = [ [ 5, 10 ], [ 2, 5 ], [ 4, 7 ], [ 3, 9 ] ],
//           truckSize = 10 Output : 91

//                       Constraints :

//                       1 <= boxTypes.length <= 1000 1 <= numberOfBoxesi,
//           numberOfUnitsPerBoxi <= 1000 1 <= truckSize <= 106
#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a,vector<int> b){
    return a[1]>b[1];
}
int maximumUnits(vector<vector<int>> &boxTypes, int truckSize){
    sort(boxTypes.begin(), boxTypes.end(), cmp);
    int res = 0;
    for (int i = 0; i < boxTypes.size();i++){
        if(truckSize>=boxTypes[i][0]){
            res += (boxTypes[i][0] * boxTypes[i][1]);
            truckSize = truckSize - boxTypes[i][0];
        }
        else if(truckSize>0 && truckSize<boxTypes[i][0]){
            res += (truckSize) * boxTypes[i][1];
            truckSize = 0;
        }
    }
    return res;
}
int main(){
    int num,truckSize;
    cin >> num>>truckSize;
    vector<vector<int>> vect(num, vector<int>(2));
    for (int i = 0; i < num;i++){
        for (int j = 0; j < 2;j++){
            cin >> vect[i][j];
        }
    }
    cout << maximumUnits(vect, truckSize) << endl;
}