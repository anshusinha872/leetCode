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
ListNode *addTwoNumbers(ListNode * l1, ListNode * l2){
    int sum = 0, carry = 0;
    ListNode *res=NULL;
    ListNode *curr = res;
    while(l1!=NULL && l2!=NULL){
        sum = l1->val + l2->val;
        sum = sum+carry;
        carry = sum / 10;
        sum = sum % 10;
        curr->next=new ListNode(sum);

    }

}
int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
}