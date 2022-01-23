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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head; 
        ListNode* a = head;
        ListNode* ans =head;
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int len = 1;
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        temp->next = head;
        temp=head;
       
        for (int i = 0; i < len - (k % len) - 1; ++i) {
            temp = temp->next;
        }
        
        head = temp->next;
        
        temp->next = NULL;
        
        return head;
        
        
    }
};