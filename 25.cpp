// 25. Reverse Nodes in k - Group
//                              Given the head of a linked list,
//     reverse the nodes of the list k at a time, and return the modified list.

//                                                        k is a positive integer and
//                                                        is less than or
//                                                    equal to the length of the linked list.If the number of nodes is not a multiple of k then left - out nodes,
//     in the end, should remain as it is.

//                 You may not alter the values in the list's nodes, only nodes themselves may be changed.

//                 Example 1 :

//     Input : head = [ 1, 2, 3, 4, 5 ],
//             k = 2 Output : [ 2, 1, 4, 3, 5 ] Example 2 :

//     Input : head = [ 1, 2, 3, 4, 5 ],
//             k = 3 Output : [ 3, 2, 1, 4, 5 ]

//                            Constraints :

//     The number of nodes in the list is n.1 <= k <= n <= 5000 0 <= Node.val <= 1000

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
ListNode *reverseKGroup(ListNode *head, int k){
    ListNode *curr = head;
    ListNode *ptr = head;
    ListNode *next = NULL;
    ListNode *prev = NULL;
    int count = 0;
    while(curr!=NULL && count!=k){
        curr = curr->next;
        count++;
    }
    if(count==k){
        curr = ptr;
        while(curr!=NULL && count!=0){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }
        if(next!=NULL){
            ListNode *next_head = reverseKGroup(next, k);
            head->next = next_head;
        }
        return prev;
    }
    else{
        return head;
    }
}
void printNode(ListNode *head){
    ListNode *curr = head;
    while(curr!=NULL){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    printNode(head);
    head=reverseKGroup(head, 3);
    printNode(head);
    return 0;
}