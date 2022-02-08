// 83. Remove Duplicates from Sorted List
//     Easy

//     4155

//     176

//     Add to List

//         Share
//             Given the head of a sorted linked list,
//     delete all duplicates such that each element appears only once.Return the linked list sorted as well.

//     Example 1 :

//     Input : head = [ 1, 1, 2 ] Output : [ 1, 2 ] Example 2 :

//     Input : head = [ 1, 1, 2, 3, 3 ] Output : [ 1, 2, 3 ]

//                                               Constraints :

//     The number of nodes in the list is in the range[0, 300]
//         .- 100 <= Node.val <= 100 The list is guaranteed to be sorted in ascending order.

#include<bits/stdc++.h>
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
ListNode *deleteDuplicates(ListNode *head){
    ListNode *curr = head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->val==curr->next->val){
            ListNode *temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        }
        else
            curr = curr->next;
    }
    return head;
}
ListNode *addNode(ListNode *root, int val)
{
    ListNode *temp = new ListNode(val);
    ListNode *ptr = root;
    if (ptr == NULL)
        return ptr;
    ListNode *curr = ptr;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return ptr;
}
void printNode(ListNode *root)
{
    while (root != NULL)
    {
        cout << root->val << " ";
        root = root->next;
    }
}
int main(){
    ListNode *head = new ListNode(1);
    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 3);
    printNode(head);
    cout << "Duplicate deleted : ";
    deleteDuplicates(head);
    printNode(head);
    return 0;
}