#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    bool traversal(TreeNode *root, int value, string &path)
    {
        if (root == NULL)
            return false;
        if (root->val == value)
            return true;
        path.push_back('L');
        if (traversal(root->left, value, path) == true)
            return true;
        path.pop_back();
        path.push_back('R');
        if (traversal(root->right, value, path) == true)
            return true;
        path.pop_back();
        return false;
    }
    TreeNode *lcaNode(TreeNode *root, int x, int y)
    {
        if (root == NULL)
            return NULL;
        if (root->val == x || root->val == y)
            return root;
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        left = lcaNode(root->left, x, y);
        right = lcaNode(root->right, x, y);
        if (left != NULL && right != NULL)
            return root;
        if (left == NULL)
            return right;
        return left;
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        TreeNode *lca = lcaNode(root, startValue, destValue);
        string lca_start = "", lca_dest = "";
        traversal(lca, startValue, lca_start);
        traversal(lca, destValue, lca_dest);
        for (int i = 0; i < lca_start.size(); i++)
        {
            lca_start[i] = 'U';
        }
        return lca_start + lca_dest;
    }
};

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    Solution s;
    int startValue, destValue;
    cin >> startValue >> destValue;
    s.getDirections(root, startValue, destValue);
    return 0;
}