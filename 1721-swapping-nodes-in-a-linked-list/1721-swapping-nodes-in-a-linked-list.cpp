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
    ListNode* swapNodes(ListNode* head, int k) {
        // Boundary conditions 
        if(head == NULL) return NULL;
        if(head->next == NULL) return head; 
        //
        ListNode* temp = head;
        int len = 0;
        ListNode* stora = head; 
        ListNode* storb = head;
        
        while(temp != NULL){
            temp = temp->next; 
            len++;    
        }
        int i =0;
        temp = head;
        while(temp != NULL){
            i++;
            if(i == k){
                stora = temp;
            }
            if(i == len-k+1 ){
                storb = temp;
            }
            temp = temp->next;
        }
        swap(storb->val, stora->val );
        return head;
    }
};