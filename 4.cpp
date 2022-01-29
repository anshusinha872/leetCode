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
    // priority_queue<int> max_heap;
    // priority_queue<int, vector<int>, greater<>> min_heap;
    // int i = 0, j = 0;
    // vector<int> merge_vector;
    // while(i<nums1.size() && j<nums2.size()){
    //     if(nums1[i]<nums2[j]){
    //         merge_vector.push_back(nums1[i]);
    //         i++;
    //     }
    //     else{
    //         merge_vector.push_back(nums2[j]);
    //         j++;
    //     }
    // }
    // while(i<nums1.size()){
    //     merge_vector.push_back(nums1[i]);
    //     i++;
    // }
    // while(j<nums2.size()){
    //     merge_vector.push_back(nums2[j]);
    //     j++;
    // }
    // cout << "merged vector : ";
    // for(auto x:merge_vector)
    //     cout << x << " ";
    // cout << endl;
    // max_heap.push(merge_vector[0]);
    // for (i = 1; i < merge_vector.size();i++){
    //     int x = merge_vector[i];
    //     if(max_heap.size()>min_heap.size()){
    //         if(max_heap.top()>x){
    //             min_heap.push(max_heap.top());
    //             max_heap.pop();
    //             max_heap.push(x);
    //         }
    //         else{
    //             min_heap.push(x);
    //         }
    //     }
    //     else{
    //         if(x<=max_heap.top())
    //             max_heap.push(x);
    //         else{
    //             min_heap.push(x);
    //             max_heap.push(min_heap.top());
    //             min_heap.pop();
    //         }
    //     }
    // }
    // if(max_heap.size()>min_heap.size())
    //     return max_heap.top();
    // return (max_heap.top() + min_heap.top()) / 2.0;

    // using heap cause time complexity of O((m+n)log(m+n))
    // efficient approach
    // using binary search we can reduce time complexity to log(n) where n is size of smallar of both the arrays

    // we do binary search for smaller size array
    // we flip the array if nums2 array is smaller than nums1
    if(nums2.size()<nums1.size())
        return findMedianSortedArrays(nums2,nums1);
    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0, high = n1;

    while(low<=high){
        int cut1 = (low + high)/2;
        int cut2 = (n1 + n2 + 1)/2-cut1;

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if(left1<=right2 && left2<=right1){
            if((n1+n2)%2==0){
                return (max(left2, left1) + min(right1, right2)) / 2.0;
            }
            else
                return max(left1, left2);
        }
        else if(left1>right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
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