// 2265. Count Nodes Equal to Average of Subtree
//     Given the root of a binary tree,
//     return the number of nodes where the value of the node is equal to the average of the values in its subtree.

//            Note :

//     The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.A subtree of root is a tree consisting of root and all of its descendants.

//     Example 1 :

//     Input : root = [ 4, 8, 5, 0, 1, null, 6 ] Output : 5 Explanation : For the node with value 4 : The average of its subtree is(4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4. For the node with value 5 : The average of its subtree is(5 + 6) / 2 = 11 / 2 = 5. For the node with value 0 : The average of its subtree is 0 / 1 = 0. For the node with value 1 : The average of its subtree is 1 / 1 = 1. For the node with value 6 : The average of its subtree is 6 / 1 = 6. Example 2 :

//     Input : root = [1] Output : 1 Explanation : For the node with value 1 : The average of its subtree is 1 / 1 = 1.
#include<bits/stdc++.h>
            using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
int size(TreeNode *root){
    if(root==nullptr){
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
int sum(TreeNode *root){
    if(root==nullptr)
        return 0;
    return root->val + sum(root->left) + sum(root->right);
}

void inorder_traversal(TreeNode *root,int *count){
    if(root!=nullptr){
        inorder_traversal(root->left,count);


        int left_size = size(root->left);
        int left_sum = sum(root->left);
        int right_size = size(root->right);
        int right_sum = sum(root->right);
        int n = left_size + right_size + 1;
        int sum = left_sum + right_sum + root->val;

        // cout << endl;
        // cout << "Root : " << root->val << endl;
        // cout << "Left sum : " << left_sum << endl;
        // cout << "Left size : " << left_size << endl;
        // cout << "Right sum : " << right_sum << endl;
        // cout << "Right size : " << right_size << endl;
        // cout << "Sum : " << sum << endl;
        // cout << "n : " << n << endl;
        // cout << " :: " << sum / n << endl;
        // cout << endl;
        if(root->val==floor(sum/n)){
            (*count)++;
        }
        inorder_traversal(root->right,count);
    }
}
int averageOfSubtree(TreeNode *root){
    int count = 0;
    inorder_traversal(root,&count);
    return count;
}
int main(){
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);
    cout << averageOfSubtree(root) << endl;
    // cout << size(root->right) << endl;
}