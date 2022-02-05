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
void sumRoot(TreeNode *root,vector<string> &vect,string str){
    if(root!=NULL){

        sumRoot(root->left, vect, str + to_string(root->val));
        sumRoot(root->right, vect, str + to_string(root->val));
        if(root->left==NULL && root->right==NULL){
            str = str + to_string(root->val);
            vect.push_back(str);
        }
    }
}
int sumRootToLeaf(TreeNode *root){
    vector<string> vect;
    if(root==NULL)
        return 0;
    sumRoot(root, vect,"");
    int sum = 0;
    for(auto itr:vect){
        int curr_sum = 0;
        for (int i = 0; i < itr.size();i++){
            curr_sum += (itr[i]-'0') * pow(2, itr.size() - i - 1);
        }
        sum += curr_sum;
    }
    return sum;
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    cout<<sumRootToLeaf(root);
    return 0;
}