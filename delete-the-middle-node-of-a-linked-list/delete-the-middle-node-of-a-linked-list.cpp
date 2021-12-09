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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp =head; 
        int len = 0; 
        
        // Boundary conditions
        if(head->next == NULL){
            
            return NULL;
        }
        // 
        while(temp != NULL){
            temp = temp->next; 
            len++;
        }
        temp = head; 
        int i = 0;
        while(temp != NULL){
            i++;
            if(i == len/2){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        return head;
        
    }
};