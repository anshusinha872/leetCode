#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left = right = NULL;
    }
};

class BSTIterator
{
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root)
    {
        pushAllNode(root);
    }

    int next()
    {
        TreeNode *curr = s.top();
        s.pop();
        if(curr->right!=NULL){
            pushAllNode(curr->right);
        }
        return curr->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
    void pushAllNode(TreeNode *root){
        while(root!=NULL){
            s.push(root);
            root = root->left;
        }
    }
};

int main(){
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
}