// 876. Middle of the Linked List
//     Given the head of a singly linked list,
//     return the middle node of the linked list.

//     If there are two middle nodes,
//     return the second middle node.

//            Example 1 :

//     Input : head = [ 1, 2, 3, 4, 5 ] Output : [ 3, 4, 5 ] Explanation : The middle node of the list is node 3. Example 2 :

//     Input : head = [ 1, 2, 3, 4, 5, 6 ] Output : [ 4, 5, 6 ] Explanation : Since the list has two middle nodes with values 3 and 4,
//             we return the second one.

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};
int print_Middle(Node *head)
{
    if (head == NULL)
        return -1;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    cout << print_Middle(head) << endl;
    return 0;
}
