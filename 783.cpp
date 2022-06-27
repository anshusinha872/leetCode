// 783. Minimum Distance Between BST Nodes
//     Given the root of a Binary Search Tree(BST),
//     return the minimum difference between the values of any two different nodes in the tree.

//            Example 1 :

//     Input : root = [ 4, 2, 6, 1, 3 ] Output : 1 Example 2 :

//     Input : root = [ 1, 0, 48, null, null, 12, 49 ] Output : 1

//                    Constraints :

//     The number of nodes in the tree is in the range[2, 100]
//         .0 <= Node.val
//                    <= 105
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
        left = NULL;
        right = NULL;
    }
};
void inorder_traversal(TreeNode *root, vector<int> &vect)
{
    if (root != NULL)
    {
        inorder_traversal(root->left, vect);
        vect.push_back(root->val);
        inorder_traversal(root->right, vect);
    }
}
int getMinimumDifference(TreeNode *root)
{
    vector<int> vect;
    inorder_traversal(root, vect);
    int min_diff = INT_MAX;
    int n = vect.size();
    for (int i = 0; i < n - 1; i++)
    {
        min_diff = min(min_diff, abs(vect[i] - vect[i + 1]));
    }
    return min_diff;
}
int main()
{
    TreeNode *root = new TreeNode(543);
    root->left = new TreeNode(384);
    root->right = new TreeNode(652);
    root->left->right = new TreeNode(445);
    root->right->right = new TreeNode(699);
    cout << getMinimumDifference(root) << endl;
    return 0;
}