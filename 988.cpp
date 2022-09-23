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
    
    void solve(TreeNode *root,string str,vector<string> &vect){
        if(root==NULL)
            return;
        char ch = root->val + 'a';
        if(root->left==NULL && root->right ==NULL){
            vect.push_back(str + ch);
        }
        solve(root->left, str + ch, vect);
        solve(root->right, str + ch, vect);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        vector<string> vect;
        solve(root, "", vect);
        vector<string> ans;
        for(string s:vect){
            reverse(s.begin(), s.end());
            ans.push_back(s);
            // cout << s << ' ';
        }
        // cout << '\n';
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};
int main(){
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->left->right->left = new TreeNode(0);
    Solution s;
    cout << s.smallestFromLeaf(root) << '\n';
    return 0;
}