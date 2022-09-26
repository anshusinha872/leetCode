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
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        map<int, bool> isParent;
        set<TreeNode *> allNodes;
        map<int, TreeNode *> mp;

        for (auto itr : descriptions)
        {
            TreeNode *parent = NULL;
            TreeNode *child = NULL;
            bool isLeft = itr[2];
            int parentValue = itr[0];
            int childValue = itr[1];
            isParent[childValue] = true;
            if (mp.find(parentValue) == mp.end())
            {
                parent = new TreeNode(parentValue);
                mp[parentValue] = parent;
            }
            else
            {
                parent = mp[parentValue];
            }
            if (mp.find(childValue) == mp.end())
            {
                child = new TreeNode(childValue);
                mp[childValue] = child;
            }
            else
            {
                child = mp[childValue];
            }
            allNodes.insert(parent);
            allNodes.insert(child);
            // isLeft = mp[itr[2]];
            if (isLeft)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }

        // for(auto itr:isParent){
        //     cout<<itr.first<<' '<< itr.second <<'\n';
        // }
        // cout<<'\n';
        for (TreeNode *root : allNodes)
        {
            if (isParent.find(root->val) == isParent.end())
            {
                return root;
            }
        }
        return NULL;
    }
};
int main(){
    vector<vector<int>> vect;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        vect.push_back({x, y, z});
    }
}