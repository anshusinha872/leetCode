// 993. Cousins in Binary Tree
//     Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y,
//     return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

//                                                                                               Two nodes of a binary tree are cousins if they have the same depth with different parents.

//                                                                                               Note that in a binary tree,
//     the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

//                                          Example 1 :

//     Input : root = [ 1, 2, 3, 4 ],
//             x = 4, y = 3 Output : false Example 2 :

//     Input : root = [ 1, 2, 3, null, 4, null, 5 ],
//             x = 5, y = 4 Output : true Example 3 :

//     Input : root = [ 1, 2, 3, null, 4 ],
//             x = 2, y = 3 Output : false
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
void isCousins_util(TreeNode *root, map<int,int> &mp){
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for (int i = 0; i < size;i++){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left!=NULL){
                mp[curr->left->val] = curr->val;
                // mp.insert(curr->left->val,curr->val);
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                mp[curr->right->val] = curr->val;
                // mp.insert(curr->right->val, curr->val);
                q.push(curr->right);
            }
        }
    }
}
bool isCousins(TreeNode *root, int x, int y){
    map<int,int> mp;
    isCousins_util(root, mp);
    queue<TreeNode *> q;
    q.push(root);
    while(q.empty()==false){
        int size = q.size();
        unordered_set<int> st;
        for (int i = 0; i < size;i++){
            TreeNode *curr = q.front();
            q.pop();
            st.insert(curr->val);
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        if(st.find(x)!=st.end() && st.find(y)!=st.end() && mp[x]!=mp[y]){
            return true;
        }
    }
    return false;
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    int x, y;
    cin >> x >> y;
    cout << isCousins(root, x, y) << endl;
    return 0;
}