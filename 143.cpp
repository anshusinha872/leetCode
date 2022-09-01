// 143. Reorder List
//         You are given the head of a singly linked -
//     list.The list can be represented as :

//     L0 → L1 → … → Ln -
//     1 → Ln
//         Reorder the list to be on the following form :

//     L0 → Ln → L1 → Ln -
//     1 → L2 → Ln - 2 → … You may not modify the values in the list's nodes. Only nodes themselves may be changed.
#include<bits/stdc++.h>
    using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};
void printNode(ListNode* head){
    int i = 0;
    while(head!=nullptr ){
        cout << head->val << " ";
        head = head->next;
        i++;
    }
}
void reorderList(ListNode *head){
        if (head->next == nullptr)
            return;
        stack<ListNode *> st;
        ListNode *curr = head;
        ListNode *lastNode = nullptr;
        while (curr != nullptr)
        {
            st.push(curr);
            lastNode = curr;
            curr = curr->next;
        }
        curr = head;
        ListNode *fast = head->next;
        int n = st.size();
        bool flag = false;
        if (n % 2 == 0)
        {
            n = (n / 2) - 1;
            flag = true;
        }
        else
        {
            n = n / 2;
        }
        for (int i = 0; i < n; i++)
        {
            ListNode *temp = st.top();
            curr->next = temp;
            st.pop();
            curr = curr->next;
            curr->next = fast;
            curr = fast;
            fast = fast->next;
        }
        if (flag)
        {
            fast->next = nullptr;
        }
        else
        {
            curr->next = nullptr;
        }
}
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // printNode(head);
    cout << endl;
    reorderList(head);
    printNode(head);
    return 0;
}