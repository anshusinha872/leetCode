// 42. Trapping Rain Water
//         Given n non -
//     negative integers representing an elevation map where the width of each bar is 1,
//     compute how much water it can trap after raining.

//     Example 1 :

//     Input : height = [ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 ] Output : 6 Explanation : The above elevation map(black section) is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case,
//             6 units of rain water(blue section) are being trapped.Example 2 :

//     Input : height = [ 4, 2, 0, 3, 2, 5 ] Output : 9

//                      Constraints :

//     n
//     == height.length
//            1 <= n
//            <= 2 * 104 0 <= height[i] <= 105

#include<bits/stdc++.h>
           using namespace std;
int trap(vector<int> &height){
    int n = height.size();
    int left[n];
    int right[n];
    int l = height[0];
    for (int i = 0; i < n;i++){
        l = max(height[i], l);
        left[i] = l;
    }
    int r = height[n-1];
    for (int i = n - 1; i >= 0;i--){
        r = max(height[i], r);
        right[i] = r;
    }
    int area=0;
    for (int i = 0; i < n;i++){
        int min_height = min(left[i], right[i]);
        if(min_height>=height[i]){
            area += (min_height - height[i]);
        }
    }
    return area;
}
int main(){
    int n;
    cin >> n;
    int temp;
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    // for (int i = 0; i < n;i++){
    //     cin >> temp;
    //     height.push_back(temp);
    // }
    cout<<trap(height) << endl;
    return 0;
}