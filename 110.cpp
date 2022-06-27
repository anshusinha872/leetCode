// 110. Balanced Binary Tree
//     Given a binary tree,
//     determine if it is height - balanced.

//                                 For this problem,
//     a height - balanced binary tree is defined as :

//     a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
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
int height(TreeNode *root){
    if(root==NULL)
        return -1;
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(TreeNode *root){
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    cout << isBalanced(root) << endl;
    return 0;
}