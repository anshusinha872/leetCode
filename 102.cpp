// 102. Binary Tree Level Order Traversal
//     Given the root of a binary tree,
//     return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

//            Example 1 :

//     Input : root = [ 3, 9, 20, null, null, 15, 7 ] Output : [ [3], [ 9, 20 ], [ 15, 7 ] ] Example 2 :

//     Input : root = [1] Output : [[1]] Example 3 :

//     Input : root = [] Output : []

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
    int height_tree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return 1 + max(height_tree(root->left), height_tree(root->right));
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        int height = height_tree(root);
        vector<vector<int>> vect(height);
        int i = 0;
        if (root == NULL)
            return vect;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (q.size() > 1)
        {
            int count = q.size();
            for (int j = 0; j < count; j++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr == NULL)
                {
                    q.push(NULL);
                    i++;
                    continue;
                }
                vect[i].push_back(curr->val);
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }
        return vect;
    }
};