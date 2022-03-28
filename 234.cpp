// 234. Palindrome Linked List
//     Given the head of a singly linked list,
//     return true if it is a palindrome.

//            Example 1 :

//     Input : head = [ 1, 2, 2, 1 ] Output : true Example 2 :

//     Input : head = [ 1, 2 ] Output : false

//                                      Constraints :

//     The number of nodes in the list is in the range[1, 105]
//         .0 <= Node.val <= 9

//                    Follow up : Could you do it in
//                                O(n)
// time and O(1) space ?

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
ListNode *reverse_linked_list(ListNode *head){
    if(head==NULL)
        return head;
    ListNode *prev = NULL;
    ListNode *curr = head;
    while(curr!=NULL){
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    if(head==NULL)
        return true;
    if(head->next==NULL)
        return true;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *rev = reverse_linked_list(slow->next);
    ListNode *curr = head;
    while(rev!=NULL){
        if(rev->val!=curr->val)
            return false;
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
}