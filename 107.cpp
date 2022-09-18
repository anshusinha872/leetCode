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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {

        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> vect;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                vect.push_back(curr->val);
                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                }
                if (curr->right != nullptr)
                {

                    q.push(curr->right);
                }
            }
            res.push_back(vect);
        }
        int i = res.size();
        vector<vector<int>> res_vector;
        for (int i = res.size() - 1; i >= 0; i--)
        {
            vector<int> vect = res[i];
            res_vector.push_back(vect);
        }
        return res_vector;
    }
};