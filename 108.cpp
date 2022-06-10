// 108. Convert Sorted Array to Binary Search Tree
//     Given an integer array nums where the elements are sorted in ascending order,
//     convert it to a height - balanced binary search tree.

//                              A height -
//         balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

//         Example 1 :

//     Input : nums = [ -10, -3, 0, 5, 9 ] Output : [ 0, -3, 9, -10, null, 5 ] Explanation : [ 0, -10, 5, null, -3, null, 9 ] is also accepted :

//     Example 2 :

//     Input : nums = [ 1, 3 ] Output : [ 3, 1 ] Explanation : [ 1, null, 3 ] and [ 3, 1 ] are both height - balanced BSTs.
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        left = NULL;
        right = NULL;
        val = x;
    }
};
TreeNode* binary(vector<int> &nums,int s,int e){
    if(s>=e){
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode *temp = new TreeNode(nums[mid]);
    temp->left = binary(nums, s, mid);
    temp->right = binary(nums, mid+1, e);
    return temp;
}
TreeNode *sortedArrayToBST(vector<int> &nums){
    TreeNode *root = NULL;
    root = binary(nums, 0, nums.size());
    return root;
}
void preorder(TreeNode *root){
    if(root!=NULL){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n;i++){
        cin >> vect[i];
    }
    TreeNode *root = sortedArrayToBST(vect);
    preorder(root);
    return 0;
}