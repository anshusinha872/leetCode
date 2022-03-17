// 2. Add Two Numbers
//         You are given two non -
//     empty linked lists representing two non - negative integers.The digits are stored in reverse order,
//     and each of their nodes contains a single digit.Add the two numbers and return the sum as a linked list.

//         You may assume the two numbers do not contain any leading zero,
//     except the number 0 itself.

//     Example 1 :

//     Input : l1 = [ 2, 4, 3 ],
//             l2 = [ 5, 6, 4 ] Output : [ 7, 0, 8 ] Explanation : 342 + 465 = 807. Example 2 :

//     Input : l1 = [0],
//             l2 = [0] Output : [0] Example 3 :

//     Input : l1 = [ 9, 9, 9, 9, 9, 9, 9 ],
//             l2 = [ 9, 9, 9, 9 ] Output : [ 8, 9, 9, 9, 0, 0, 0, 1 ]

#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
        next = NULL;
    }
};
void printNode(ListNode *head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
}
ListNode *addTwoNumbers(ListNode * l1, ListNode * l2){
    int sum = 0, carry = 0;
    ListNode *curr = NULL;
    ListNode *head=NULL;
    while(l1!=NULL && l2!=NULL){
        sum = l1->val + l2->val;
        sum = sum+carry;
        carry = sum / 10;
        sum = sum % 10;
        if(head==NULL){
            head = new ListNode(sum);
            curr = head;
        }
        else{
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1!=NULL){
        sum = l1->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        if (head == NULL)
        {
            head = new ListNode(sum);
            curr = head;
        }
        else
        {
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        sum = l2->val + carry;
        carry = sum / 10;
        sum = sum % 10;
        if (head == NULL)
        {
            head = new ListNode(sum);
            curr = head;
        }
        else
        {
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        l2 = l2->next;
    }
    if(carry!=0){
        if (head == NULL)
        {
            head = new ListNode(carry);
            curr = head;
        }
        else
        {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        carry = carry / 10;
    }
    return head;
}
int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *result = addTwoNumbers(l1, l2);
    printNode(result);
    return 0;
}