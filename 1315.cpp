// 1315. Sum of Nodes with Even - Valued Grandparent
//                                    Given the root of a binary tree,
//     return the sum of values of nodes with an even - valued grandparent.If there are no nodes with an even - valued grandparent, return 0.

//                                                                                                                                         A grandparent of a node is the parent of its parent if it exists.

//                                                                                                                                         Example 1 :

//     Input : root = [ 6, 7, 8, 2, 7, 1, 3, 9, null, 1, 4, null, null, null, 5 ] Output : 18 Explanation : The red nodes are the nodes with even - value grandparent while the blue nodes are the even - value grandparents.Example 2 :

//     Input : root = [1] Output : 0
#include<bits/stdc++.h>
                                                                                                                                        using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left = NULL;
        right = NULL;
    }
};
int sumEvenGrandparent_util(TreeNode *root,map<TreeNode*,TreeNode*> &mp){
    // mp[root] = NULL;
    int res = 0;
    mp[root] = nullptr;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for (int i = 0; i < size;i++){
            TreeNode *curr = q.front();
            q.pop();
            if(mp[curr]!=nullptr && mp[mp[curr]]!=nullptr){
                if(mp[mp[curr]]->val%2==0){
                    res += curr->val;
                }
            }
            if(curr->left!=NULL){
                q.push(curr->left);
                mp[curr->left] = curr;
            }
            if(curr->right!=NULL){
                q.push(curr->right);
                mp[curr->right] = curr;
            }
        }
    }
    return res;
}
int sumEvenGrandparent(TreeNode *root)
{
    map<TreeNode *, TreeNode *> mp;
    return sumEvenGrandparent_util(root, mp);
    // for(auto itr:mp){
    //     if(itr.second==nullptr){
    //         cout << "Root : " << itr.first->val << " Parent : NULL" << endl;
    //     }
    //     else{
    //         cout << "Root : " << itr.first->val << " Parent : " << itr.second->val << endl;
    //     }
    // }
}
int main(){
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(7);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(9);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);
    cout << sumEvenGrandparent(root) << endl;
    return 0;
}