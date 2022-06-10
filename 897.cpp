// 897. Increasing Order Search Tree
//     Given the root of a binary search tree,
//     rearrange the tree in in - order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

//                                                                                                             Example 1 :

//     Input : root = [ 5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9 ] Output : [ 1, null, 2, null, 3, null, 4, null, 5, null, 6, null, 7, null, 8, null, 9 ] Example 2 :

//     Input : root = [ 5, 1, 7 ] Output : [ 1, null, 5, null, 7 ]

//                                         Constraints :

//     The number of nodes in the given tree will be in the range[1, 100]
//         .0 <= Node.val <= 1000

#include<bits/stdc++.h>
                   using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
void inorder_traversal(TreeNode *root, vector<TreeNode *> &vect)
{
    if (root != NULL)
    {
        inorder_traversal(root->left, vect);
        vect.push_back(root);
        inorder_traversal(root->right, vect);
    }
}
TreeNode *increasingBST(TreeNode *root){
    if (root == NULL)
        return NULL;
    vector<TreeNode *> vect;
    TreeNode *curr = root;
    inorder_traversal(root, vect);
    for (int i = 0; i < vect.size() - 1; i++)
    {
        vect[i]->right = vect[i + 1];
        vect[i]->left = NULL;
    }
    vect[vect.size() - 1]->left = NULL;
    vect[vect.size() - 1]->right = NULL;
    return vect[0];
}
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);
    increasingBST(root);
}