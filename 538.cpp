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
    map<TreeNode *, int> mp;
    void inOrder(TreeNode *root, vector<pair<TreeNode *, int>> &vect)
    {
        if (root != NULL)
        {
            inOrder(root->left, vect);
            mp[root] = root->val;
            vect.push_back({root, root->val});
            inOrder(root->right, vect);
        }
    }
    void traversal(TreeNode *root)
    {
        if (root != NULL)
        {
            traversal(root->left);
            root->val = mp[root];
            traversal(root->right);
        }
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        vector<pair<TreeNode *, int>> vect;
        inOrder(root, vect);
        for (int i = vect.size() - 2; i >= 0; i--)
        {
            vect[i].second = vect[i].second + vect[i + 1].second;
        }
        for (auto itr : vect)
        {
            mp[itr.first] = itr.second;
        }
        traversal(root);
        return root;
    }
};