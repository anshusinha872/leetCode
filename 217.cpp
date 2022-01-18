// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.Example 1 :

//     Input : nums = [ 1, 2, 3, 1 ] Output : true Example 2 :

//     Input : nums = [ 1, 2, 3, 4 ] Output : false Example 3 :

//     Input : nums = [ 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 ] Output : true

#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> &v){
    set<int> s;
    s.insert(v[0]);
    for (int i = 1; i < v.size();i++){
        if(s.find(v[i])==s.end()){
            s.insert(v[i]);
        }
        else{
            return true;
        }
    }
    return false;
} 
int main()
{
    int size;
    cin >> size;
    vector<int> v;
    for (int i = 0; i < size;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << containsDuplicate(v);
    return 0;
}