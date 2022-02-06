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
    if(root==NULL)
        return 0;
    int sum = 0;
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while(curr!=NULL || s.empty()==false){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        if(curr->left==NULL && curr->right==NULL){
            sum += curr->val;
        }
        curr = curr->right;
        
    }
    return sum;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout<<sumOfLeftLeaves(root);
    return 0;
}