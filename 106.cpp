// 106. Construct Binary Tree from Inorder and Postorder Traversal

//     Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree,
//     construct and return the binary tree.

//     Example 1 :

//     Input : inorder = [ 9, 3, 15, 20, 7 ],
//             postorder = [ 9, 15, 7, 20, 3 ] Output : [ 3, 9, 20, null, null, 15, 7 ] Example 2 :

//     Input : inorder = [-1],
//             postorder = [-1] Output : [-1]

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
    int postorderIndex = 0;
    TreeNode *buildTreeUtil(vector<int> &inorder, vector<int> &postorder, int is, int ie)
    {
        if (is > ie)
            return NULL;
        int val = postorder[((postorder.size()) - 1 - postorderIndex)];
        postorderIndex++;
        int inorder_index;
        TreeNode *root = new TreeNode(val);
        for (int i = is; i <= ie; i++)
        {
            if (inorder[i] == root->val)
            {
                inorder_index = i;
                break;
            }
        }
        root->right = buildTreeUtil(inorder, postorder, inorder_index + 1, ie);
        root->left = buildTreeUtil(inorder, postorder, is, inorder_index - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildTreeUtil(inorder, postorder, 0, (inorder.size() - 1));
    }
};