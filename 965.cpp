#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

bool isUnivalTree(TreeNode *root){
    if(root==NULL)
        return true;
    if(root->left!=NULL && root->left->val!=root->val)
        return false;
    if(root->right!=NULL && root->right->val!=root->val)
        return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
int main(){
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(1);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(1);
    // root->right->right = new TreeNode(1);

    
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(2);


    cout << isUnivalTree(root);
    return 0;
}