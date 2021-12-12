/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {return head;}
        ListNode *ffront = head; 
        ffront=ffront->next;
        ListNode* x = head;
        x->next = NULL;
        while (ffront!=NULL){
            head=ffront; 
            ffront=ffront->next;
            head->next=x;
            x=head;
        }
        return head;
    }
};