// 23. Merge k Sorted Lists
//         You are given an array of k linked -
//     lists lists,
//     each linked - list is sorted in ascending order.

//                   Merge all the linked -
//         lists into one sorted linked - list and return it.

//                                        Example 1 :

//     Input : lists = [ [ 1, 4, 5 ], [ 1, 3, 4 ], [ 2, 6 ] ] Output : [ 1, 1, 2, 3, 4, 4, 5, 6 ] Explanation : The linked - lists are : [
//         1->4->5,
//         1->3->4,
//         2->6
//     ] merging them into one sorted list : 1->1->2->3->4->4->5->6 Example 2 :

//     Input : lists = [] Output : [] Example 3 :

//     Input : lists = [[]] Output : []

//                                   Constraints :

//     k == lists.length 0 <= k <= 104 0 <= lists[i].length <= 500 - 104 <= lists[i][j] <= 104 lists[i] is sorted in ascending order.The sum of lists[i].length will not exceed 104.

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
void add_at_head(ListNode **head,ListNode *temp){
    ListNode *ptr = *head;
    if(ptr==NULL){
        ptr = temp;
        temp->next = NULL;
        *head = temp;
        return;
    }
    else{
        temp->next = ptr;
        ptr = temp;
        *head = ptr;
        return;
    }
}
ListNode* reverse_node(ListNode *head){
    ListNode *curr = head;
    ListNode *prev = NULL;
    while(curr!=NULL){
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode *mergeKLists(vector<ListNode *> &lists){
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
    for (int i = 0; i < lists.size();i++){
        ListNode *head = lists[i];
        while(head!=NULL){
            pq.push({head->val, head});
            head = head->next;
        }
    }
    ListNode *head = NULL;
    while(pq.empty()==false){
        add_at_head(&head, pq.top().second);
        pq.pop();
    }
    head = reverse_node(head);
    return head;
}
void printNode(ListNode *head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
}
int main(){
    int k;
    cin >> k;
    vector<ListNode *> lists;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);
    lists.push_back(head1);
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    lists.push_back(head2);
    ListNode *head3 = new ListNode(2);
    head3->next = new ListNode(6);
    lists.push_back(head3);
    ListNode *head=mergeKLists(lists);
    printNode(head);
    return 0;
}