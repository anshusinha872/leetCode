#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};
struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};
class Solution
{
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return NULL;
        if (head->next == tail)
        {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *mid = head;
        ListNode *curr = head;
        while (curr != tail && curr->next != tail)
        {
            mid = mid->next;
            curr = curr->next->next;
        }

        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(mid->next, tail);
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return sortedListToBST(head, NULL);
    }
};
int main()
{
    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
}