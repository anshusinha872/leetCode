#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left = right = NULL;
    }
};
class Solution
{
public:
    int res = 0;
    int longestUnivaluePath(TreeNode *root,int value){
        if(root==NULL)
            return 0;
        int left = longestUnivaluePath(root->left, root->val);
        int right = longestUnivaluePath(root->right, root->val);
        res = max(res, left + right);
        if(root->val==value){
            return (max(left, right) + 1);
        }
        return 0;
    }
    int longestUnivaluePath(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        longestUnivaluePath(root, root->val);
        return res;
    }
};
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(5);
    Solution s;
    cout << s.longestUnivaluePath(root) << '\n';
    return 0;
}