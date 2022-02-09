// 100. Same Tree
//     Easy

//     4981

//     121

//     Add to List

//         Share
//             Given the roots of two binary trees p and q,
//     write a function to check if they are the same or not .

//                                                           Two binary trees are considered the same if they are structurally identical,
//     and the nodes have the same value.

//         Example 1 :

//     Input : p = [ 1, 2, 3 ],
//             q = [ 1, 2, 3 ] Output : true Example 2 :

//     Input : p = [ 1, 2 ],
//             q = [ 1, null, 2 ] Output : false Example 3 :

//     Input : p = [ 1, 2, 1 ],
//             q = [ 1, 1, 2 ] Output : false

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
bool isSameTree(TreeNode *p, TreeNode *q){
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int main(){
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    cout << isSameTree(root1, root2);
    return 0;
}