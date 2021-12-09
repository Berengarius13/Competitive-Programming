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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0; 
        ListNode * temp = head; 
        ListNode * del;
        if(head == NULL) return NULL;
        if(head->next == NULL) {
            delete head;
            return NULL;
        }
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        
        temp = head;
        len = len -n; 
        if(len == 0) {
            del =head;
            head = head->next;
            delete del;
            return head;
        }
       
        while(temp!=NULL){
            
            if(len == 1){
                del = temp->next; 
                temp->next= temp->next->next;
                delete del;
                break;
            }
            len--;
            temp = temp->next;
        }
        return head;
    }
};