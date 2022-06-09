// 938. Range Sum of BST
//     Given the root node of a binary search tree and two integers low and high,
//     return the sum of values of all nodes with a value in the inclusive range[low, high].

//            Example 1 :

//     Input : root = [ 10, 5, 15, 3, 7, null, 18 ],
//             low = 7, high = 15 Output : 32 Explanation : Nodes 7, 10, and15 are in the range[7, 15].7 + 10 + 15 = 32. Example 2 :

//     Input : root = [ 10, 5, 15, 3, 7, 13, 18, 1, null, 6 ],
//             low = 6, high = 10 Output : 23 Explanation : Nodes 6, 7, and10 are in the range[6, 10].6 + 7 + 10 = 23.

#include<bits/stdc++.h>
                                                                     using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
int rangeSumBST(TreeNode *root, int low, int high){
    if(root==NULL)
        return 0;
    int ans = 0;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        if(curr->val<=high && curr->val>=low){
            cout << curr->val << endl;
            ans += curr->val;
        }
        curr = curr->right;
    }
    return ans;
}
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    // root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->left->left->left = new TreeNode(1);
    root->left->right->left = new TreeNode(6);
    int low, high;
    cin >> low >> high;
    cout << rangeSumBST(root, low, high) << endl;
    return 0;
}