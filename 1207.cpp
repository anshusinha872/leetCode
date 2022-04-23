// 1207. Unique Number of Occurrences
//     Given an array of integers arr,
//     return true if the number of occurrences of each value in the array is unique, or false otherwise.

//                                                                                        Example 1 :

//     Input : arr = [ 1, 2, 2, 1, 1, 3 ] Output : true Explanation : The value 1 has 3 occurrences,
//             2 has 2 and 3 has 1. No two values have the same number of occurrences.Example 2 :

//     Input : arr = [ 1, 2 ] Output : false Example 3 :

//     Input : arr = [ -3, 0, 1, -3, 1, 1, 1, -3, 10, 0 ] Output : true

//                                                                 Constraints :

//                                                                 1 <= arr.length <= 1000 - 1000 <=
//                                                                 arr[i] <= 1000
#include<bits/stdc++.h>
using namespace std;
bool uniqueOccurrences(vector<int> &arr){
    if(arr.size()==1){
        return true;
    }
    map<int, int> mp;
    for (int i = 0; i < arr.size();i++){
        mp[arr[i]]++;
    }
    // cout << "MAP " << endl;
    vector<int> freq;
    for(auto itr:mp){
        freq.push_back(itr.second);
    }
    sort(freq.begin(), freq.end());
    for (int i = 1; i < freq.size();i++){
        if(freq[i-1]==freq[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    cout << uniqueOccurrences(arr) << endl;
    return 0;
}