#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value){
        val = value;
        left=NULL;
        right = NULL;
    }
};
TreeNode *search(TreeNode *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->val == value)
        return root;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    left = search(root->left, value);
    right = search(root->right, value);

    if (left != NULL && left->val == value)
        return left;
    if (right != NULL && right->val == value)
        return right;
    return NULL;
}
TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target){
    int value = target->val;
    return search(cloned, value);
}
int main(){
    
}