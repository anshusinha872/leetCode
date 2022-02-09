// 257. Binary Tree Paths
//     Easy

//     3645

//     171

//     Add to List

//         Share
//             Given the root of a binary tree,
//     return all root - to - leaf paths in any order.

//                            A leaf is a node with no children.

//                            Example 1 :

//     Input : root = [ 1, 2, 3, null, 5 ] Output : [ "1->2->5", "1->3" ] Example 2 :

//     Input : root = [1] Output : ["1"]

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
void binaryTreePathsUtil(TreeNode *root, vector<string> &vect, string str)
{
    if (root != NULL)
    {
        binaryTreePathsUtil(root->left, vect, (str +to_string(root->val)+"->"));
        binaryTreePathsUtil(root->right, vect, (str + to_string(root->val)+"->"));
        if (root->left == NULL && root->right == NULL)
        {
            vect.push_back(str + to_string(root->val));
        }
    }
}
void print(TreeNode *root){
    if(root!=NULL){
        cout << root->val << " ";
        print(root->left);
        print(root->right);
    }
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> vect;
    string str = "";
    binaryTreePathsUtil(root, vect, str);
    for (auto itr : vect)
        cout << itr << " ";
    return vect;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    print(root);
    cout << endl;
    binaryTreePaths(root);
    return 0;
}