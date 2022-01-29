// 4. Median of Two Sorted Arrays
//     Given two sorted arrays nums1 and nums2 of size m and n respectively,
//     return the median of the two sorted arrays.

//            The overall run time complexity should be
//            O(log(m + n))
//                .

//            Example 1 :

//     Input : nums1 = [ 1, 3 ],
//             nums2 = [2] Output : 2.00000 Explanation : merged array = [ 1, 2, 3 ] and median is 2. Example 2 :

//     Input : nums1 = [ 1, 2 ],
//             nums2 = [ 3, 4 ] Output : 2.50000 Explanation : merged array = [ 1, 2, 3, 4 ] and median is(2 + 3) / 2 = 2.5.

//                                                                                                                      Constraints :

//     nums1.length == m nums2.length == n 0 <= m <= 1000 0 <= n <= 1000 1 <= m + n <= 2000 - 106 <= nums1[i],
//             nums2[i] <= 106
#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;
    int i = 0, j = 0;
    vector<int> merge_vector;
    while(i<nums1.size() && j<nums2.size()){
        if(nums1[i]<nums2[j]){
            merge_vector.push_back(nums1[i]);
            i++;
        }
        else{
            merge_vector.push_back(nums2[j]);
            j++;
        }
    }
    while(i<nums1.size()){
        merge_vector.push_back(nums1[i]);
        i++;
    }
    while(j<nums2.size()){
        merge_vector.push_back(nums2[j]);
        j++;
    }
    cout << "merged vector : ";
    for(auto x:merge_vector)
        cout << x << " ";
    cout << endl;
    max_heap.push(merge_vector[0]);
    for (i = 1; i < merge_vector.size();i++){
        int x = merge_vector[i];
        if(max_heap.size()>min_heap.size()){
            if(max_heap.top()>x){
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(x);
            }
            else{
                min_heap.push(x);
            }
        }
        else{
            if(x<=max_heap.top())
                max_heap.push(x);
            else{
                min_heap.push(x);
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }
    if(max_heap.size()>min_heap.size())
        return max_heap.top();
    return (max_heap.top() + min_heap.top()) / 2.0;
}
int main(){
    int m, n;
    cin >> m >> n;
    vector<int> nums1, nums2;
    for (int i = 0; i < m;i++){
        int temp;
        cin >> temp;
        nums1.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums2.push_back(temp);
    }
    cout<<findMedianSortedArrays(nums1, nums2);
    return 0;
}