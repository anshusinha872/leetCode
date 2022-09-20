/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto itr = q.front();
                q.pop();
                TreeNode *node = itr.first;
                int level = itr.second.first;
                int hd = itr.second.second;
                // mp[hd][level].insert(node->val);
                mp[hd][level].push(node->val);
                if (node->left != NULL)
                {
                    q.push({node->left, {level + 1, hd - 1}});
                }
                if (node->right != NULL)
                {
                    q.push({node->right, {level + 1, hd + 1}});
                }
            }
        }
        vector<vector<int>> vect;
        for (auto itr1 : mp)
        {
            vector<int> temp;
            for (auto itr2 : itr1.second)
            {
                priority_queue<int, vector<int>, greater<int>> pq = itr2.second;
                while (pq.empty() == false)
                {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            vect.push_back(temp);
        }
        return vect;
    }
};