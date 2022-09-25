#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    long long val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(long long x)
    {
        val = x;
        left = right = NULL;
    }
};
class Solution
{
    int count = 0;
    void pseudoPalindromicPathsUitl(TreeNode *root, vector<int> &freq)
    {
        if (root == NULL)
            return;
        freq[root->val]++;
        pseudoPalindromicPathsUitl(root->left, freq);
        pseudoPalindromicPathsUitl(root->right, freq);
        if (root->left == NULL && root->right == NULL)
        {

            int oddCount = 0;
            for (int i = 1; i <= 9; i++)
            {
                if (freq[i] % 2 != 0)
                {
                    oddCount++;
                }
            }
            if (oddCount == 1 || oddCount == 0)
            {
                count++;
            }
        }
        freq[root->val]--;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        vector<int> freq(10, 0);
        pseudoPalindromicPathsUitl(root, freq);
        return count;
    }
};
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);
    Solution s;
    s.pseudoPalindromicPaths(root) << '\n';
    return 0;
}