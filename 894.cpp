#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
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
    map<int, vector<TreeNode *>> mp;
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        vector<TreeNode *> vect;
        if(n%2==0){
            return vect;
        }
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
        if(n==1){
            vect.push_back(new TreeNode(0));
            return vect;
        }
        n = n - 1;
        for (int i = 1; i < n;i+=2){
            vector<TreeNode *> leftTree = allPossibleFBT(i);
            vector<TreeNode *> rightTree = allPossibleFBT(n - i);
            for(TreeNode *leftNode : leftTree){
                for(TreeNode *rightNode :rightTree){
                    TreeNode *root = new TreeNode(0);
                    root->left = leftNode;
                    root->right = rightNode;
                    vect.push_back(root);
                }
            }
        }
        mp[n + 1] = vect;
        return vect;
    }
};
int main(){

}