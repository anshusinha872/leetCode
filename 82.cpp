// 82. Remove Duplicates from Sorted List II
//     Given the head of a sorted linked list,
//     delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.Return the linked list sorted as well.

//                                                   Example 1 :

//     Input : head = [ 1, 2, 3, 3, 4, 4, 5 ] Output : [ 1, 2, 5 ] Example 2 :

//     Input : head = [ 1, 1, 1, 2, 3 ] Output : [ 2, 3 ]

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
void add_node_at_end(ListNode *head,int value){
    ListNode *temp = new ListNode(value);
    if(head==NULL){
        head = temp;
        return;
    }
    ListNode *curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
}
void printNode(ListNode *head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
}
ListNode *deleteDuplicates(ListNode *head){
    if(head==NULL || head->next==NULL)
        return head;
    ListNode *curr = head->next;
    if(head->val!=curr->val){
        head->next = deleteDuplicates(curr);
        return head;
    }
    else{
        while(curr!=NULL && curr->val==head->val)
        {
            curr = curr->next;
        }
        return deleteDuplicates(curr);
    }
}
int main(){
    ListNode *head = new ListNode(1);
    add_node_at_end(head, 2);
    add_node_at_end(head, 3);
    add_node_at_end(head, 3);
    add_node_at_end(head, 4);
    add_node_at_end(head, 4);
    add_node_at_end(head, 5);
    printNode(head);
    cout << endl;
    ListNode *ans = deleteDuplicates(head);
    printNode(ans);
    return 0;
}