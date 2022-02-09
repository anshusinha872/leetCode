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
void printNode(TreeNode *root){
    if(root!=NULL){
        cout << root->val << " ";
        printNode(root->left);
        printNode(root->right);
    }
}
int findTiltUtil(TreeNode *root,int &sum){
    if(root==NULL)
        return 0;
    int leftSum = findTiltUtil(root->left, sum);
    int rightSUm = findTiltUtil(root->right, sum);
    sum += abs(leftSum - rightSUm);
    return leftSum + rightSUm + root->val;
}
int findTilt(TreeNode *root){
    if(root==NULL)
        return 0;
    int sum = 0;
    findTiltUtil(root, sum);
    return sum;
}
int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    findTilt(root);
    return 0;
}