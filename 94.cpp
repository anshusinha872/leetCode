// 94. Binary Tree Inorder Traversal
//     Given the root of a binary tree,
//     return the inorder traversal of its nodes' values.

//            Example 1 :

//     Input : root = [ 1, null, 2, 3 ] Output : [ 1, 3, 2 ] Example 2 :

//     Input : root = [] Output : [] Example 3 :

//     Input : root = [1] Output : [1]

#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};
vector<int> inorderTraversal(TreeNode *root){
    stack<TreeNode*> st;
    vector<int> vect;
    if (root == NULL)
        return vect;

    TreeNode *curr = root;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        vect.push_back(curr->val);
        curr = curr->right;
    }
    return vect;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = inorderTraversal(root);
}