// 617. Merge Two Binary Trees
//     You are given two binary trees root1 and root2.

//     Imagine that when you put one of them to cover the other,
//     some nodes of the two trees are overlapped while the others are not .You need to merge the two trees into a new binary tree.The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.Otherwise, the NOT null node will be used as the node of the new tree.

//                                                                                                                                                                                                                                                     Return the merged tree.

//                                                                                                                                                                                                                                                     Note : The merging process must start from the root nodes of both trees.

//                                                                                                                                                                                                                                                            Example 1 :

//     Input : root1 = [ 1, 3, 2, 5 ],
//             root2 = [ 2, 1, 3, null, 4, null, 7 ] Output : [ 3, 4, 5, 5, 4, null, 7 ] Example 2 :

//     Input : root1 = [ 1 ],
//             root2 = [ 1, 2 ] Output : [ 2, 2 ]



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
void printNode(TreeNode *root){
    if(root!=NULL){
        cout << root->val << " ";
        printNode(root->left);
        printNode(root->right);
    }
}
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2){
    if(root2==NULL)
        return root1;
    if(root1==NULL)
        return root2;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}
int main()
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);
    cout << "Before merge function : ";
    printNode(root1);
    cout << endl;

    mergeTrees(root1, root2);
    cout << "After merge function : ";
    printNode(root1);
    return 0;
}