// 2236. Root Equals Sum of Children
//     You are given the root of a binary tree that consists of exactly 3 nodes : the root,
//                                                                                its left child,
//                                                                                and its right child.

//                                                                                    Return true if the value of the root is equal to the sum of the values of its two children,
//                                                                                or false otherwise.

//                                                                                    Example 1 :

//     Input : root = [ 10, 4, 6 ] Output : true Explanation : The values of the root,
//             its left child,
//             and its right child are 10,
//             4,
//             and6,
//             respectively.10 is equal to 4 + 6,
//             so we return true.Example 2 :

//     Input : root = [ 5, 3, 1 ] Output : false Explanation : The values of the root,
//             its left child,
//             and its right child are 5,
//             3,
//             and1,
//             respectively.5 is not equal to 3 + 1,
//             so we return false.
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
bool checkTree(TreeNode *root){
    return root->val == root->left->val + root->right->val;
}
void printNode(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        printNode(root->left);
        printNode(root->right);
    }
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    cout << checkTree(root) << endl;
    return 0;
}