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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        long ans = 1;
        while (!q.empty())
        {
            long cnt = q.size();
            long minIndex = q.front().second;
            long firstIndex = 0, lastIndex = 0;
            for (int i = 0; i < cnt; i++)
            {
                pair<TreeNode *, int> p = q.front();
                q.pop();
                long currIndex = p.second - minIndex;
                if (i == 0)
                {
                    firstIndex = currIndex;
                }
                if (i == cnt - 1)
                {
                    lastIndex = currIndex;
                }
                if (p.first->left != NULL)
                    q.push({p.first->left, 2 * currIndex + 1});
                if (p.first->right != NULL)
                    q.push({p.first->right, 2 * currIndex + 2});
            }
            ans = max(ans, lastIndex - firstIndex + 1);
        }
        return ans;
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
        root->left = new TreeNode(3);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(5);
        root->right->right = new TreeNode(9);
        root->left->left->left = new TreeNode(6);
        root->right->right->left = new TreeNode(7);
        TreeNode *root2 = new TreeNode(1);
        root2->left = new TreeNode(3);
        root2->right = new TreeNode(2);
        root2->left->left = new TreeNode(5);
        Solution s;
        cout << s.widthOfBinaryTree(root2) << endl;
    }
    return 0;
}
