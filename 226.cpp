// 226. Invert Binary Tree
//     Given the root of a binary tree,
//     invert the tree, and return its root.

//                      Example 1 :

//     Input : root = [ 4, 2, 7, 1, 3, 6, 9 ] Output : [ 4, 7, 2, 9, 6, 3, 1 ] Example 2 :

//     Input : root = [ 2, 1, 3 ] Output : [ 2, 3, 1 ] Example 3 :

//     Input : root = [] Output : []
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};
void printNode(TreeNode *root){
    if(root!=NULL){
        cout << root->val << " ";
        printNode(root->left);
        printNode(root->right);
    }
}
void invertTree(TreeNode *root){
    if(root!=NULL){
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
} 
int main()
{
    TreeNode *root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);
    cout << "Tree before inverting : ";
    printNode(root1);
    invertTree(root1);
    cout << endl;
    printNode(root1);
    return 0;
}
