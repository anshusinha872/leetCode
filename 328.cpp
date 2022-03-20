// 328. Odd Even Linked List
//     Given the head of a singly linked list,
//     group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

//                                                                                            The first node is considered odd,
//     and the second node is even, and so on.

//                                      Note that the relative order inside both the even and odd groups should remain as it was in the input.

//                                      You must solve the problem in O(1) extra space complexity and O(n) time complexity.

//                                      Example 1 :

//     Input : head = [ 1, 2, 3, 4, 5 ] Output : [ 1, 3, 5, 2, 4 ] Example 2 :

//     Input : head = [ 2, 1, 3, 5, 6, 4, 7 ] Output : [ 2, 3, 6, 7, 1, 5, 4 ]

//                                                     Constraints :

//     n
//     == number of nodes in the linked list 0 <= n <= 104 - 106 <= Node.val <= 106
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
void printNode(ListNode *head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode *oddEvenList(ListNode *head){
    ListNode *eS = NULL, *eE = NULL, *oS = NULL, *oE = NULL;
    ListNode *curr = head;
    bool flag=true;
    int x;
    while (curr != NULL)
    {
        if(flag){
            x = 1;
            flag=!flag;
        }
        else{
            x = 2;
            flag = !flag;
        }
        // int x = curr->val;
        if(x%2==0){
            if(eS==NULL){
                eS = curr;
                eE = eS;
            }
            else{
                eE->next = curr;
                eE = eE->next;
            }
        }else{
            if(oS==NULL){
                oS = curr;
                oE = oS;
            }
            else{
                oE->next = curr;
                oE = oE->next;
            }
        }
        
        curr = curr->next;
    }
    if (oS == NULL || eS == NULL)
        return head;
    oE->next = eS;
    eE->next = NULL;
    return oS;
}
int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    printNode(head);
    head=oddEvenList(head);
    printNode(head);
    return 0;
}