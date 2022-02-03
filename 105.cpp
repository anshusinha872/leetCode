// 105. Construct Binary Tree from Preorder and Inorder Traversal
//     Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree,
//     construct and return the binary tree.

//     Example 1 :

//     Input : preorder = [ 3, 9, 20, 15, 7 ],
//             inorder = [ 9, 3, 15, 20, 7 ] Output : [ 3, 9, 20, null, null, 15, 7 ] Example 2 :

//     Input : preorder = [-1],
//             inorder = [-1] Output : [-1]

//                                     Constraints :

//                                     1 <= preorder.length <= 3000 inorder.length ==
//                       preorder.length - 3000 <= preorder[i],
//             inorder[i] <= 3000 preorder and inorder consist of unique values.Each value of inorder also appears in preorder.preorder is guaranteed to be the preorder traversal of the tree.inorder is guaranteed to be the inorder traversal of the tree.



// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
    int pre_index=0;
    TreeNode* buildTreeUtil(vector<int>& preorder,vector<int> &inorder,int is,int ie){
        if(is>ie)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pre_index++]);
        int inIndex=0;
        for(int i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                inIndex=i;
                break;
            }
        }
        root->left=buildTreeUtil(preorder,inorder,is,inIndex-1);
        root->right=buildTreeUtil(preorder,inorder,inIndex+1,ie);
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeUtil(preorder,inorder,0,(inorder.size()-1));
        
    }
};