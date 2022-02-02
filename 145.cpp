// 145. Binary Tree Postorder Traversal
//     Given the root of a binary tree,
//     return the postorder traversal of its nodes' values.

//            Example 1 :

//     Input : root = [ 1, null, 2, 3 ] Output : [ 3, 2, 1 ] Example 2 :

//     Input : root = [] Output : [] Example 3 :

//     Input : root = [1] Output : [1]

//                                 Constraints :

//     The number of the nodes in the tree is in the range[0, 100]
//         .- 100 <= Node.val <= 100
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
// class Solution
// {
//     void postorder_Traversal_util(TreeNode *root, vector<int> &vect)
//     {
//         if (root != NULL)
//         {
//             postorder_Traversal_util(root->left, vect);
//             postorder_Traversal_util(root->right, vect);
//             vect.push_back(root->val);
//         }
//     }

// public:
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         vector<int> vect;
//         postorder_Traversal_util(root, vect);
//         return vect;
//     }
// };