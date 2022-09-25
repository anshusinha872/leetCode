#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        int val = x;
        left = right = NULL;
    }
};
class Solution
{
    int preIndex = 0;
    TreeNode *constructTreeNode(vector<int> &preOrder,vector<int> &inOrder,int is,int ie){
        if(is>ie)
            return NULL;
        TreeNode *root = new TreeNode(preOrder[preIndex++]);
        int index = 0;
        for (int i = is; i <= ie;i++){
            if(inOrder[i]==root->val){
                index = i;
                break;
            }
        }
        root->left = constructTreeNode(preOrder, inOrder, is, index - 1);
        root->right = constructTreeNode(preOrder, inOrder, index + 1, ie);
        return root;
    }
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        TreeNode *root = constructTreeNode(preorder, inorder, 0, inorder.size() - 1);
        return root;
    }
};
int main(){
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(12);
}