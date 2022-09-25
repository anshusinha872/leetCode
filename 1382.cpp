#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
    void inOrderTraversal(TreeNode *root, vector<int> &inorder)
    {
        if (root != NULL)
        {
            inOrderTraversal(root->left, inorder);
            inorder.push_back(root->val);
            inOrderTraversal(root->right, inorder);
        }
    }
    TreeNode *constructTree(vector<int> &inorder, int s, int e)
    {
        if (s > e)
            return NULL;
        int mid = (s + e) / 2;
        TreeNode *root = new TreeNode(inorder[mid]);
        root->left = constructTree(inorder, s, mid - 1);
        root->right = constructTree(inorder, mid + 1, e);
        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorder;
        inOrderTraversal(root, inorder);
        root = constructTree(inorder, 0, inorder.size() - 1);
        return root;
    }
};
int main(){
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    return 0;
}