// 606. Construct String from Binary Tree
//     Given the root of a binary tree,
//     construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

//                                                                                                                       Omit all the empty parenthesis pairs that do not affect the one -
//                                                                                                                       to - one mapping relationship between the string and the original binary tree.

//                                                                                                                            Example 1 :

//     Input : root = [ 1, 2, 3, 4 ] Output : "1(2(4))(3)" Explanation : Originally,
//             it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs.And it will be "1(2(4))(3)" Example 2 :

//     Input : root = [ 1, 2, 3, null, 4 ] Output : "1(2()(4))(3)" Explanation : Almost the same as the first example,
//             except we cannot omit the first parenthesis pair to break the one - to - one mapping relationship between the input and the output.
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
string tree2str(TreeNode *root){
    string sub = to_string(root->val);
    if (root->left) // left check
        sub += "(" + tree2str(root->left) + ")";
    if (root->right)
    { // right check
        if (!root->left)
            sub += "()"; // left not present, but right present
        sub += "(" + tree2str(root->right) + ")";
    }
    return sub;
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    cout << tree2str(root) << endl;
    return 0;
}