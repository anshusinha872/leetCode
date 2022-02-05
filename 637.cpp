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
vector<double> averageOfLevels(TreeNode *root){
    vector<double> vect;
    if(root==NULL)
        return vect;
    deque<TreeNode *> dq;
    dq.push_back(root);
    double sum = 0.0;
    dq.push_back(NULL);
    vect.push_back(root->val);
    while(dq.empty()==false){
        // int size = dq.size();
        TreeNode *curr = dq.front();
        dq.pop_front();
        sum = 0.0;
        if(curr==NULL){
            
            for (auto itr = ++dq.begin(); itr != dq.end();itr++){
                sum += (*itr)->val;
            }
            vect.push_back(sum / double(dq.size() - 1));
            dq.push_back(NULL);
            continue;
        }
        if(curr->left!=NULL)
            dq.push_back(curr->left);
        if(curr->right!=NULL)
            dq.push_back(curr->right);
    }
    return vect;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<double> vect;
    vect = averageOfLevels(root);
    for(auto itr:vect)
        cout << itr << " ";
    return 0;
}