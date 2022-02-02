// 21. Merge Two Sorted Lists
//     You are given the heads of two sorted linked lists list1 and list2.

//     Merge the two lists in a one sorted list.The list should be made by splicing together the nodes of the first two lists.

//     Return the head of the merged linked list.

//     Example 1 :

//     Input : list1 = [ 1, 2, 4 ],
//             list2 = [ 1, 3, 4 ] Output : [ 1, 1, 2, 3, 4, 4 ] Example 2 :

//     Input : list1 = [],
//             list2 = [] Output : [] Example 3 :

//     Input : list1 = [],
//             list2 = [0] Output : [0]

#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(){
        val = 0;
        next = NULL;
    }
    ListNode(int x){
        val = x;
        next = NULL;
    }
    ListNode(int x,ListNode *next){
        val = x;
        next = next;
    }
};
void printData(ListNode *list){
    while(list!=NULL){
        cout << list->val << " ";
        list = list->next;
    }
}
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    ListNode *head = NULL, *tail = NULL;
    if (list1->val <= list2->val)
    {
        head = tail = list1;
        list1 = list1->next;
    }
    else
    {
        head = tail = list2;
        list2 = list2->next;
    }
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    if (list1 == NULL)
        tail->next = list2;
    else
        tail->next = list1;
    return head;
} 
int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    ListNode *list = mergeTwoLists(list1, list2);
    return 0;
}