// 101. Symmetric Tree
//     Easy

//     8602

//     213

//     Add to List

//         Share
//             Given the root of a binary tree,
//     check whether it is a mirror of itself(i.e., symmetric around its center).

//     Example 1 :

//     Input : root = [ 1, 2, 2, 3, 4, 4, 3 ] Output : true Example 2 :

//     Input : root = [ 1, 2, 2, null, 3, null, 3 ] Output : false

//                                                           Constraints :

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
bool isSymmetric(TreeNode *root){
    TreeNode *left, *right;
    if (!root)
        return true;

    queue<TreeNode *> q1, q2;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() && !q2.empty())
    {
        left = q1.front();
        q1.pop();
        right = q2.front();
        q2.pop();
        if (NULL == left && NULL == right)
            continue;
        if (NULL == left || NULL == right)
            return false;
        if (left->val != right->val)
            return false;
        q1.push(left->left);
        q1.push(left->right);
        q2.push(right->right);
        q2.push(right->left);
    }
    return true;
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout<<isSymmetric(root);
    return 0;
}