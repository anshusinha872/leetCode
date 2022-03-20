// 24. Swap Nodes in Pairs
//     Given a linked list,
//     swap every two adjacent nodes and return its head.You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

//     Example 1 :

//     Input : head = [ 1, 2, 3, 4 ] Output : [ 2, 1, 4, 3 ] Example 2 :

//     Input : head = [] Output : [] Example 3 :

//     Input : head = [1] Output : [1]

//                                 Constraints :

//     The number of nodes in the list is in the range[0, 100]
//         .0 <= Node.val <= 100

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
ListNode *swapPairs(ListNode *head){
    if(head==NULL ||head->next==NULL)
        return head;
    ListNode *curr = head->next->next;
    ListNode *prev = head;
    head = head->next;
    head->next = prev;
    while(curr!=NULL || curr->next!=NULL){
        prev->next = curr->next;
        prev = curr;
        ListNode *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    return 0;
}