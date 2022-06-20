
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* even = new ListNode();
        ListNode* odd = new ListNode();
        ListNode* head_even = even;
        ListNode* head_odd = odd;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                odd->next = temp;
                odd = odd->next;
            }
            else{
                even->next = temp;
                even = even->next;
            }
             temp = temp->next;
        }
        even->next = NULL;
        odd->next = head_even->next;
        return head_odd->next;
    }
};