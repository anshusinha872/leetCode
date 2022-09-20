/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;
    void recoverTreeUtil(TreeNode *root)
    {
        if (root != NULL)
        {
            recoverTreeUtil(root->left);
            if (prev != NULL && (first == NULL && prev->val >= root->val))
            {
                first = prev;
            }
            if (prev != NULL && (first != NULL && prev->val >= root->val))
            {
                second = root;
            }
            prev = root;
            recoverTreeUtil(root->right);
        }
    }
    void recoverTree(TreeNode *root)
    {
        recoverTreeUtil(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};