// 404. Sum of Left Leaves
//     Given the root of a binary tree,
//     return the sum of all left leaves.

//            A leaf is a node with no children.A left leaf is a leaf that is the left child of another node.Example 1 :

//     Input : root = [ 3, 9, 20, null, null, 15, 7 ] Output : 24 Explanation : There are two left leaves in the binary tree,
//             with values 9 and 15 respectively.Example 2 :

//     Input : root = [1] Output : 0

//                        Constraints :

//     The number of nodes in the tree is in the range[1, 1000]
//         .- 1000 <= Node.val <= 1000
#include <bits/stdc++.h>
                   using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};
int sumOfLeftLeaves(TreeNode *root){
    queue<pair<TreeNode *, char>> q;
    q.push({root, 'V'});
    int res = 0;
    while (q.empty() == false)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto curr = q.front();
            q.pop();
            if (curr.second != 'R' && curr.second != 'V' && curr.first->left == NULL && curr.first->right == NULL)
            {
                res += curr.first->val;
            }
            if (curr.first->left != NULL)
                q.push({curr.first->left, 'L'});
            if (curr.first->right != NULL)
                q.push({curr.first->right, 'R'});
        }
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    // root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);
    cout<<sumOfLeftLeaves(root);
    return 0;
}