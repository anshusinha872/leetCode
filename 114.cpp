#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};
vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> vect;
    if (root == NULL)
        return vect;
    TreeNode *curr = root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            vect.push_back(curr->val);
            if(curr->right!=NULL)
                st.push(curr->right);
            curr = curr->left;
        }
        if(st.empty()==false){
            curr = st.top();
            // vect.push_back(curr->val);
            st.pop();
        }
    }
    return vect;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = inorderTraversal(root);
    for(auto itr:ans)
        cout << itr << " ";
    return 0;
}