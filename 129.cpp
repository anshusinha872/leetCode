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
    void sumNumbersUtil(TreeNode *root,vector<int> &vect,int num){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            vect.push_back(num * 10 + root->val);
        }
        sumNumbersUtil(root->left, vect, (num * 10 + root->val));
        sumNumbersUtil(root->right, vect, (num * 10 + root->val));
    }
    int sumNumbers(TreeNode *root)
    {
        vector<int> vect;
        sumNumbersUtil(root, vect, 0);
        int sum = 0;
        for(int x:vect){
            sum += x;
            cout << x << ' ';
        }
        cout << '\n';
        return sum;
    }
};
int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    Solution s;
    cout<<s.sumNumbers(root);
    return 0;
}