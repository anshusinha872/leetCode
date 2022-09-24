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
class Solution
{
    // int count=0;
    int solve(TreeNode *root, int value)
    {
        if (root == NULL)
            return 0;
        int count = 0;
        if (root->val >= value)
            count = 1;
        else
        {
            count = 0;
        }
        count += solve(root->left, max(value, root->val));
        count += solve(root->right, max(value, root->val));
        return count;
    }

public:
    int goodNodes(TreeNode *root)
    {
        return 1 + solve(root->left, root->val) + solve(root->right, root->val);
    }
};
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
}