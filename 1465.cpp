// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
//     You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where :

//     horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly,
//     and verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts.Since the answer can be a large number,
//     return this modulo 109 + 7.
#include<bits/stdc++.h>
           using namespace std;
const int mod = 1e9 + 7;
int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int vmax = INT_MIN;
    vmax = max(verticalCuts[0] - 0, abs(verticalCuts[verticalCuts.size()-1]-w));
    int hmax = INT_MIN;
    hmax = max(horizontalCuts[0] - 0, abs(horizontalCuts[horizontalCuts.size() - 1] - h));
    for (int i = 0; i < verticalCuts.size()-1;i++){
        vmax = max(vmax, abs(verticalCuts[i] - verticalCuts[i + 1]));
    }
    for (int i = 0; i < horizontalCuts.size() - 1;i++){
        hmax = max(hmax, abs(horizontalCuts[i] - horizontalCuts[i + 1]));
    }
    return (long)hmax * vmax % mod;
}
int main(){
    int h, w,x,y;
    cin>>h>>w>>x>>y;
    vector<int> horizontalCuts(x);
    for(int i=0;i<x;i++){
        cin >> horizontalCuts[i];
    }
    vector<int> verticalCuts(y);
    for(int i=0;i<y;i++){
        cin >> verticalCuts[i];
    }


}