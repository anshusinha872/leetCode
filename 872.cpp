// 872. Leaf - Similar Trees
//                 Consider all the leaves of a binary tree,
//     from left to right order, the values of those leaves form a leaf value sequence.

//                               For example,
//     in the given tree above, the leaf value sequence is(6, 7, 4, 9, 8).

//                                  Two binary trees are considered leaf
//                                  - similar if their leaf value sequence is the same.

//                                    Return true if and only if the two given trees with head nodes root1 and root2 are leaf
//                                  - similar.

//                                    Example 1 :

//     Input : root1 = [ 3, 5, 1, 6, 2, 9, 8, null, null, 7, 4 ],
//             root2 = [ 3, 5, 1, 6, 7, 4, 2, null, null, null, null, null, null, 9, 8 ] Output : true Example 2 :

//     Input : root1 = [ 1, 2, 3 ],
//             root2 = [ 1, 3, 2 ] Output : false

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
void traversal(TreeNode* root,vector<int> &vect){
    if(root!=NULL){
        traversal(root->left,vect);
        traversal(root->right,vect);
        if(root->left==NULL && root->right==NULL){
            vect.push_back(root->val);
        }
    }
}
bool leafSimilar(TreeNode *root1, TreeNode *root2){
    vector<int> vect1, vect2;
    traversal(root1, vect1);
    traversal(root2, vect2);
    if(vect1.size()!=vect2.size())
        return false;
    for (int i = 0; i < vect1.size();i++){
        if(vect1[i]!=vect2[i])
            return false;
    }
    return true;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(8);
    // traversal(root);
    // cout << endl;
    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);
    // traversal(root2);
    cout<<leafSimilar(root, root2);
    return 0;
}