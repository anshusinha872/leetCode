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
class Solution
{
public:
    vector<vector<int>> vect;
    void pathSumUtil(TreeNode *root, vector<int> &path, int targetSum)
    {
        if (root == NULL)
        {
            return;
        }
        if (abs(targetSum - root->val) == 0 && (root->left == NULL && root->right == NULL))
        {
            path.push_back(root->val);
            vect.push_back(path);
        }
        else
        {
            path.push_back(root->val);
        }
        pathSumUtil(root->left, path, targetSum - root->val);
        pathSumUtil(root->right, path, targetSum - root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        pathSumUtil(root, path, targetSum);
        return vect;
    }
};
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    int targetSum = 0;
    cin >> targetSum;
    Solution S;
    S.pathSum(root, targetSum);
    return 0;
}