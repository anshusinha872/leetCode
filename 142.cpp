// 142. Linked List Cycle II
//     Given the head of a linked list,
//     return the node where the cycle begins.If there is no cycle, return null.

//     There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.Internally,
//     pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

//     Do not modify the linked list.

//     Example 1 :

//     Input : head = [ 3, 2, 0, -4 ],
//             pos = 1 Output : tail connects to node index 1 Explanation : There is a cycle in the linked list, where tail connects to the second node.Example 2 :

//     Input : head = [ 1, 2 ],
//             pos = 0 Output : tail connects to node index 0 Explanation : There is a cycle in the linked list, where tail connects to the first node.Example 3 :

//     Input : head = [1],
//             pos = -1 Output : no cycle
//                                   Explanation : There is no cycle in the linked list.

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
ListNode *detectCycle(ListNode *head){
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return NULL;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            slow = head;
            break;
        }
    }
    if (fast == NULL || slow == NULL)
    {
        // cout << "NO cycle";
        return NULL;
    }
    else
    {
        while (fast != slow)
        {
            if (fast->next == NULL || slow->next == NULL)
                return NULL;
            fast = fast->next;
            slow = slow->next;
        }
    }
    return fast;
}
void print_Node(ListNode *head){
    int t = 10;
    while(t--){
        cout << head->val << " ";
        head = head->next;
    }
}
int main(){
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(0);
    // head->next->next->next = new ListNode(-4);
    // head->next->next->next->next = head->next;
    // print_Node(head);
    ListNode *ans = detectCycle(head);
    cout << ans->val;

    return 0;
}