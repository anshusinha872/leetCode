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
    // priority_queue <int, vector<int>, greater<int>> pq;
    vector<int> vect;
    void inOrderTraversal(TreeNode *root)
    {
        if (root != NULL)
        {
            inOrderTraversal(root->left);
            // pq.push(root->val);
            vect.push_back(root->val);
            inOrderTraversal(root->right);
        }
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        inOrderTraversal(root1);
        inOrderTraversal(root2);
        sort(vect.begin(), vect.end());
        return vect;
    }
};