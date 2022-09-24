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
class Solution
{
    long long pathSumUtil(TreeNode *root, long long targetSum)
    {
        if (root == NULL)
            return 0;
        long long ans = 0;
        if (root->val == targetSum)
        {
            ans++;
        }
        ans += pathSumUtil(root->left, targetSum - root->val);
        ans += pathSumUtil(root->right, targetSum - root->val);
        return ans;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return 0;
        return pathSumUtil(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};

int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    int targetSum = 0;
    cin >> targetSum;
    Solution s;
    cout << s.pathSum(root,targetSum) << '\n';
    return 0;
}