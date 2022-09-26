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
    void reverseNode(vector<TreeNode*> &vect){
        int i = 0, j = vect.size() - 1;
        while(i<=j){
            swap(vect[i]->val, vect[j]->val);
            i++;
            j--;
        }
    }
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int level = -1;
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode *> vect;
            level++;
            for (int i = 0; i < size;i++){
                auto itr = q.front();
                if(level%2!=0){
                    vect.push_back(itr);
                }
                q.pop();
                if(itr->left){
                    q.push(itr->left);
                }
                if(itr->right){
                    q.push(itr->right);
                }
            }
            reverseNode(vect);
        }
        return root;
    }
};
int main(){
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);
    Solution s;
    s.reverseOddLevels(root);
    return 0;
}