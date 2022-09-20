class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        map<int, int> mp;
        q.push({root, 1});
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto itr = q.front();
                q.pop();
                TreeNode *node = itr.first;
                int level = itr.second;
                mp[level] += node->val;
                if (node->left != NULL)
                {
                    q.push({node->left, level + 1});
                }
                if (node->right != NULL)
                {
                    q.push({node->right, level + 1});
                }
            }
        }
        int res = INT_MIN;
        int level = 0;
        for (auto itr : mp)
        {
            if (itr.second > res)
            {
                res = itr.second;
                level = itr.first;
            }
        }
        return level;
    }
};