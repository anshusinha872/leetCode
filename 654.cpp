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
class Solution
{
    int getIndex(vector<int> &nums,int s,int e){
        int resIndex = s;
        for (int i = s; i <= e;i++){
            if(nums[i]>=nums[resIndex]){
                resIndex = i;
            }
        }
        return resIndex;
    }
    TreeNode *constructTree(vector<int> &nums,int s,int e){
        if(s>e)
            return NULL;
        int i = getIndex(nums, s, e);
        TreeNode *root = new TreeNode(nums[i]);
        root->left = constructTree(nums, s, i - 1);
        root->right = constructTree(nums, i + 1, e);
        return root;
    }
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        TreeNode *root = constructTree(nums, 0, nums.size() - 1);
        return root;
    }
};
int main(){
    TreeNode *root =NULL;
    int size = 0;
    cin >>size;
    vector<int> nums(size);
    Solution s;
    root = s.constructMaximumBinaryTree(nums);
    return 0;
}