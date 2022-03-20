// 19. Remove Nth Node From End of List
//     Given the head of a linked list,
//     remove the nth node from the end of the list and return its head.

//     Example 1 :

//     Input : head = [ 1, 2, 3, 4, 5 ],
//             n = 2 Output : [ 1, 2, 3, 5 ] Example 2 :

//     Input : head = [1],
//             n = 1 Output : [] Example 3 :

//     Input : head = [ 1, 2 ],
//             n = 1 Output : [1]

//                            Constraints :

//     The number of nodes in the list is sz.1 <= sz <= 30 0 <= Node.val <= 100 1 <= n <= sz

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
ListNode *removeNthFromEnd(ListNode *head, int n){
    ListNode *prev = NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < n;i++){
        if(fast==NULL)
            return NULL;
        fast = fast->next;
    }
    while(fast!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if(slow==head){
        ListNode *temp = slow;
        head = slow->next;
        delete (temp);
        return head;
    }
    else if(slow->next==NULL){
        delete (slow);
        prev->next = NULL;
        return head;
    }
    else{
        prev->next = slow->next;
        delete (slow);
        return head;
    }
}
void printNode(ListNode *head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    printNode(head);
    ListNode * result=removeNthFromEnd(head, 1);
    printNode(head);
    return 0;
}