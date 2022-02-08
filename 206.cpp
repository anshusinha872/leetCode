// 206. Reverse Linked List
//     Given the head of a singly linked list,
//     reverse the list, and return the reversed list.

//                       Example 1 :

//     Input : head = [ 1, 2, 3, 4, 5 ] Output : [ 5, 4, 3, 2, 1 ] Example 2 :

//     Input : head = [ 1, 2 ] Output : [ 2, 1 ] Example 3 :

//     Input : head = [] Output : []
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
ListNode* addNode(ListNode* root,int val){
    ListNode *temp = new ListNode(val);
    ListNode *ptr = root;
    if(ptr==NULL)
        return ptr;
    ListNode *curr = ptr;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return ptr;
}
void printNode(ListNode *root){
    while(root!=NULL){
        cout << root->val << " ";
        root = root->next;
    }
}
ListNode *reverseList(ListNode *head){
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = head;
    if(head==NULL)
        return head;
    if(head->next==NULL)
        return head;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main(){
    ListNode *root = new ListNode(1);
    addNode(root, 2);
    addNode(root, 3);
    addNode(root, 4);
    addNode(root, 5);
    printNode(root);
    root = reverseList(root);
    cout << "\nReversed Node : ";
    printNode(root);
    return 0;
}