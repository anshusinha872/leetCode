// 2385. Amount of Time for Binary Tree to Be Infected
// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.
#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};
class Solution
{
public:
    TreeNode *amountOfTime_util(TreeNode *root, map<TreeNode *, TreeNode *> &mp, int value)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *target = NULL;
        while (q.empty() == false)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->val == value)
                {
                    target = curr;
                }
                if (curr->left)
                {
                    mp[curr->left] = curr;
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    mp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        return target;
    }
    int amountOfTime(TreeNode *root, int value)
    {
        map<TreeNode *, TreeNode *> mp;
        TreeNode *target = amountOfTime_util(root, mp, value);
        map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        int count = 0;
        while (q.empty() == false)
        {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left])
                {
                    visited[curr->left] = true;
                    q.push(curr->left);
                    flag = true;
                }
                if (curr->right && !visited[curr->right])
                {
                    visited[curr->right] = true;
                    q.push(curr->right);
                    flag = true;
                }
                if (mp[curr] && !visited[curr])
                {
                    visited[curr] = true;
                    q.push(mp[curr]);
                    flag = true;
                }
            }
            if (flag)
            {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(5);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right->left = new TreeNode(10);
        root->right->right = new TreeNode(6);
        root->left->right->left = new TreeNode(9);
        root->left->right->right = new TreeNode(2);
    }
    return 0;
}
