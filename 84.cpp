// 84. Largest Rectangle in Histogram
//     Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

//     Example 1 :

//     Input : heights = [ 2, 1, 5, 6, 2, 3 ] Output : 10 Explanation : The above is a histogram where width of each bar is 1. The largest rectangle is shown in the red area,
//             which has an area = 10 units.Example 2 :

//     Input : heights = [ 2, 4 ] Output : 4

//                       Constraints :

//                       1 <= heights.length <= 105 0 <= heights[i] <= 104

#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights){
    int n = heights.size();
    vector<int> ps;
    vector<int> ns;
    stack<int> st;
    st.push(0);
    ps.push_back(-1);
    for (int i = 1; i < n;i++){
        while(st.empty()==false && heights[st.top()]>=heights[i]){
            st.pop();
        }
        int res = st.empty() ? -1 : st.top();
        ps.push_back(res);
        st.push(i);
    }
    while(st.empty()==false){
        st.pop();
    }
    st.push(n-1);
    ns.push_back(n);
    for (int i = n - 2; i >= 0;i--){
        while(st.empty()==false && heights[st.top()]>=heights[i]){
            st.pop();
        }
        int res = st.empty() ? n : st.top();
        ns.push_back(res);
        st.push(i);
    }
    reverse(ns.begin(), ns.end());
    int res = 0;
    for (int i = 0; i < n;i++){
        int curr = heights[i];
        curr += (i - ps[i] - 1) * heights[i];
        curr += (ns[i] - i - 1) * heights[i];
        res = max(res, curr);
    }
    // cout << "Previous Smaller : ";
    // for(int x:ps){
    //     cout << x << " ";
    // }
    // cout << "\nNext smaller : ";
    // for(int x:ns){
    //     cout << x << " ";
    // }
    for (int i = 0; i < n;i++){
        res = max(heights[i], res);
    }
        return res;
}
int main(){
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n;i++){
        cin>>heights[i];
    }
    cout << largestRectangleArea(heights) << endl;
    return 0;
}