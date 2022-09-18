// 863. All Nodes Distance K in Binary Tree
//     Given the root of a binary tree,
//     the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

//                                                                 You can return the answer in any order.

//                                                                 Example 1 :

//     Input : root = [ 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 ],
//             target = 5, k = 2 Output : [ 7, 4, 1 ] Explanation : The nodes that are a distance 2 from the target node(with value 5) have values 7, 4, and1. Example 2 :

//     Input : root = [1],
//             target = 1, k = 3 Output : []
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    void distanceKUtil(TreeNode *root,map<TreeNode*,TreeNode*> &mp,map<TreeNode*,bool> &visited){
        visited[root] = false;
        queue<TreeNode *> q;
        q.push(root);
        mp[root] = NULL;
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left!=NULL){
                visited[curr->left] = false;
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                visited[curr->right] = false;
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    void traversal(TreeNode* root,map<TreeNode*,TreeNode*> &mp,int k,vector<int> &vect,map<TreeNode*,bool> &visited){
        if(root==NULL)
            return;
        if(k==0){
            vect.push_back(root->val);
        }
        else{
            if(mp[root]!=NULL && visited[root]==false){
                visited[root] = true;
                traversal(mp[root], mp, k - 1, vect,visited);
            }
            if(root->left!=NULL && visited[root->left]==false){
                visited[root->left] = true;
                traversal(root->left, mp, k - 1, vect,visited);
            }
            if(root->right!=NULL && visited[root->right]==false){
                visited[root->right] = true;
                traversal(root->right, mp, k - 1, vect,visited);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> vect;
        map<TreeNode *, TreeNode *> mp;
        map<TreeNode *, bool> visited;
        distanceKUtil(root, mp,visited);
        traversal(target, mp, k, vect,visited);
        return vect;
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
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
        Solution s;
        TreeNode *target = root->left;
        int k = 2;
        vector<int> vect = s.distanceK(root, target, k);
    }
    return 0;
}
