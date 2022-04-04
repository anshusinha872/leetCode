// 1721. Swapping Nodes in a Linked List
//     You are given the head of a linked list,
//     and an integer k.

//         Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the
//         end(the list is 1 - indexed)
//             .

//         Example 1 :

//     Input : head = [ 1, 2, 3, 4, 5 ],
//             k = 2 Output : [ 1, 4, 3, 2, 5 ] Example 2 :

//     Input : head = [ 7, 9, 6, 6, 7, 8, 3, 0, 9, 5 ],
//             k = 5 Output : [ 7, 9, 6, 6, 8, 7, 3, 0, 9, 5 ]

//                            Constraints :

//     The number of nodes in the list is n.1 <= k
//                 <= n <= 105 0 <= Node.val <= 100

#include<bits/stdc++.h>
                using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};
void printNode(ListNode *head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode *swapNodes(ListNode *head, int k){
    ListNode *ptr = head;
    ListNode *ptr1=head, *ptr2=head;
    ListNode *next_ptr=head;
    for (int i = 0; i < k - 1;i++){
        ptr1 = ptr1->next;
        next_ptr = next_ptr->next;
    }
    next_ptr = next_ptr->next;
    while(next_ptr!=NULL){
        ptr2 = ptr2->next;
        next_ptr = next_ptr->next;
    }
    swap(ptr1->val, ptr2->val);
    return head;
}
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    printNode(head);
    head=swapNodes(head, 2);
    printNode(head);
    return 0;
}