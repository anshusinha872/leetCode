// 1338. Reduce Array Size to The Half
//     You are given an integer array arr.You can choose a set of integers and remove all the occurrences of these integers in the array.

//     Return the minimum size of the set so that at least half of the integers of the array are removed.

//     Example 1 :

//     Input : arr = [ 3, 3, 3, 3, 5, 5, 5, 2, 2, 7 ] Output : 2 Explanation : Choosing{3, 7} will make the new array[5, 5, 5, 2, 2] which has size 5(i.e equal to half of the size of the old array).Possible sets of size 2 are{3, 5},
//             {3, 2}, {5, 2}.Choosing set{2, 7} is not possible as it will make the new array[3, 3, 3, 3, 5, 5, 5] which has a size greater than half of the size of the old array.Example 2 :

//     Input : arr = [ 7, 7, 7, 7, 7, 7 ] Output : 1 Explanation : The only possible set you can choose is{7}.This will make the new array empty.

//                                                                 Constraints :

//                                                                 2 <= arr.length <= 105 arr.length is even.1 <= arr[i] <= 105
#include<bits/stdc++.h>
                    using namespace std;
int minSetSize(vector<int> &arr){
    map<int, int> mp;
    for(int x:arr){
        mp[x]++;
    }
    int size = arr.size();
    int count = 0;
    vector<int> freq;
    for(auto itr:mp){
        freq.push_back(itr.second);
    }
    sort(freq.begin(), freq.end(),greater<int>());
    int res = 0;
    int i = 0;
    while(res<size/2 && i<size){
        count++;
        res += freq[i++];
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    cout << minSetSize(arr) << endl;
    return 0;
}