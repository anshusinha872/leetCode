// 2250. Count Number of Rectangles Containing Each Point
//     You are given a 2D integer array rectangles where rectangles[i] = [ li, hi ] indicates that ith rectangle has a length of li and a height of hi.You are also given a 2D integer array points where points[j] = [ xj, yj ] is a point with coordinates(xj, yj).

//                                                                                                                                                                                                                        The ith rectangle has its bottom -
//                                                                                                                                                                                                                        left corner point at the coordinates(0, 0) and
//                                                                                                                                                                                                                    its top - right corner point at(li, hi).

//                                                                                                                                                                                                                              Return an integer array count of length points.length where count[j] is the number of rectangles that contain the jth point.

//                                                                                                                                                                                                                              The ith rectangle contains the jth point if 0 <=
//                                                                                                                                                                                                                        xj <= li and 0 <= yj <= hi.Note that points that lie on the edges of a rectangle are also considered to be contained by that rectangle.

//                                                                                                                                                                                                                                                Example 1 :

//     Input : rectangles = [ [ 1, 2 ], [ 2, 3 ], [ 2, 5 ] ],
//                                                       points = [ [ 2, 1 ], [ 1, 4 ] ] Output : [ 2, 1 ] Explanation : The first rectangle contains no points.The second rectangle contains only the point(2, 1).The third rectangle contains the points(2, 1) and (1, 4).The number of rectangles that contain the point(2, 1) is 2. The number of rectangles that contain the point(1, 4) is 1. Therefore, we return [ 2, 1 ].Example 2 :

//     Input : rectangles = [ [ 1, 1 ], [ 2, 2 ], [ 3, 3 ] ],
//                                                       points = [ [ 1, 3 ], [ 1, 1 ] ] Output : [ 1, 3 ] Explanation : The first rectangle contains only the point(1, 1).The second rectangle contains only the point(1, 1).The third rectangle contains the points(1, 3) and (1, 1).The number of rectangles that contain the point(1, 3) is 1. The number of rectangles that contain the point(1, 1) is 3. Therefore, we return [ 1, 3 ].

//                                                                                                                                                                                                                                                                                                                                                                                                                            Constraints :

//                                                                                                                                                                                                                                                                                                                                                                                                                            1 <= rectangles.length,
//                                                       points.length <= 5 * 104 rectangles[i].length == points[j].length == 2 1 <= li, xj <= 109 1 <= hi, yj <= 100 All the rectangles are unique.All the points are unique.

#include<bits/stdc++.h>
using namespace std;
vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points){
    map<int,int> mp;
    // int n = points.size();
    // vector<int> vect(n,0);
    // for (int i = 0; i < points.size();i++){
    //     for (int j = 0; j < rectangles.size();j++){
    //         int p_x = points[i][0];
    //         int p_y = points[i][1];
    //         int r_x = rectangles[j][0];
    //         int r_y = rectangles[j][1];
    //         if(p_x<=r_x && p_y<=r_y){
    //             mp[i]++;
    //         }
    //     }
    // }
    // // cout << "MAP";
    // for(auto itr:mp){
    //     // cout << itr.first << " " << itr.second << endl;
    //     vect[itr.first]=itr.second;
    // }
    // return vect;
    unordered_map<int, vector<int>> umap;
    for(auto itr:rectangles){
        umap[itr[1]].push_back(itr[0]);
    }
    for (int i = 0; i <= 100;i++){
        sort(umap[i].begin(), umap[i].end());
    }
    vector<int> res;
    for(auto p:points){
        int sum = 0;
        for (int i = p[1]; i < 101;i++){
            auto lb = lower_bound(begin(umap[i]), end(umap[i]), p[0]);
            // cout << end(umap[i]) - lb << endl;
            sum += end(umap[i]) - lb;
        }
        res.push_back(sum);
    }
    return res;
}
int main(){
    int rect, point;
    cin >> rect >> point;
    vector<vector<int>> rectangles(rect, vector<int>(2));
    vector<vector<int>> points(point, vector<int>(2));
    for (int i = 0; i < rect;i++){
        for (int j = 0; j < 2;j++){
            cin >> rectangles[i][j];
        }
    }
    for (int i = 0; i < point;i++){
        for (int j = 0; j < 2;j++){
            cin >> points[i][j];
        }
    }
    vector<int> vect = countRectangles(rectangles, points);
    cout << endl;
    for(int x:vect){
        cout << x << " ";
    }
    return 0;
}