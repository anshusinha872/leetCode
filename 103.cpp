// 103. Binary Tree Zigzag Level Order Traversal
//     Given the root of a binary tree,
//     return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

//            Example 1 :

//     Input : root = [ 3, 9, 20, null, null, 15, 7 ] Output : [ [3], [ 20, 9 ], [ 15, 7 ] ] Example 2 :

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
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return 1 + max(height(root->left), height(root->right));
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> vect(height(root));
        int i = 0;
        if (root == NULL)
            return vect;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (s1.empty() == false || s2.empty() == false)
        {
            while (s1.empty() == false)
            {
                TreeNode *curr = s1.top();
                s1.pop();
                vect[i].push_back(curr->val);

                if (curr->left != NULL)
                {
                    s2.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    s2.push(curr->right);
                }
            }
            i++;
            while (s2.empty() == false)
            {
                TreeNode *curr = s2.top();
                s2.pop();
                vect[i].push_back(curr->val);

                if (curr->right != NULL)
                {
                    s1.push(curr->right);
                }
                if (curr->left != NULL)
                {
                    s1.push(curr->left);
                }
            }
            i++;
        }
        return vect;
    }
};