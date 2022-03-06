// 56. Merge Intervals
//     Given an array of intervals where intervals[i] = [ starti, endi ],
//                                       merge all overlapping intervals, and return an array of the non - overlapping intervals that cover all the intervals in the input.

//                                                                                                         Example 1 :

//     Input : intervals = [ [ 1, 3 ], [ 2, 6 ], [ 8, 10 ], [ 15, 18 ] ] Output : [ [ 1, 6 ], [ 8, 10 ], [ 15, 18 ] ] Explanation : Since intervals[1, 3] and [ 2, 6 ] overlaps,
//                                       merge them into[1, 6].Example 2 :

//     Input : intervals = [ [ 1, 4 ], [ 4, 5 ] ] Output : [[ 1, 5 ]] Explanation : Intervals[1, 4] and [ 4, 5 ] are considered overlapping.

#include<bits./stdc++.h>
using namespace std;
// bool mycmp(v)
vector<vector<int>> merge(vector<vector<int>> &intervals){
    vector<vector<int>> vect;
    sort(intervals.begin(), intervals.end());
    vect.push_back({intervals[0][0], intervals[0][1]});
    
    for (int i = 1; i < intervals.size();i++){
        if(intervals[i][0]<=vect[vect.size()-1][1]){
            vect[vect.size() - 1][1] = max(vect[vect.size() - 1][1], intervals[i][1]);
        }
        else{
            vect.push_back({intervals[i][0], intervals[i][1]});
        }
    }
    return vect;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> interval;
    for (int i = 0; i < n;i++){
        int si, ei;
        cin >> si >> ei;
        interval.push_back({si, ei});
    }
    interval = merge(interval);
    for(auto x:interval){
        for(int y:x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}