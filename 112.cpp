// 112. Path Sum
//     Easy

//     4874

//     748

//     Add to List

//         Share
//             Given the root of a binary tree and an integer targetSum,
//     return true if the tree has a root - to - leaf path such that adding up all the values along the path equals targetSum.

//                                               A leaf is a node with no children.

//                                               Example 1 :

//     Input : root = [ 5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1 ],
//             targetSum = 22 Output : true Explanation : The root - to - leaf path with the target sum is shown.Example 2 :

//     Input : root = [ 1, 2, 3 ],
//             targetSum = 5 Output : false Explanation : There two root - to - leaf paths in the tree : (1 -- > 2) : The sum is 3.(1 -- > 3) : The sum is 4. There is no root - to - leaf path with sum = 5. Example 3 :

//     Input : root = [],
//             targetSum = 0 Output : false Explanation : Since the tree is empty, there are no root - to - leaf paths.

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
bool hasPathSum(TreeNode *root,int targetSum){
    if(root!=NULL){
        if((targetSum-(root->val))==0 && (root->left==NULL && root->right==NULL))
            return true;
        if(root->left!=NULL)
            if(hasPathSum(root->left, (targetSum - root->val)))
                return true;
        if(root->right!=NULL)
            if(hasPathSum(root->right, (targetSum - root->val)))
                return true;
    }
    return false;
}
int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    cout<<hasPathSum(root,22);
    return 0;
}
