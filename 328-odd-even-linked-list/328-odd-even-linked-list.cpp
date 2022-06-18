
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even = new ListNode();
        ListNode* odd = new ListNode();
        ListNode* head_even = even;
        ListNode* head_odd = odd;
        int i = 1;
        ListNode* temp = head;
        while(temp != NULL){
            if((i&1)==1){
                odd->next = temp;
                odd = odd->next;
            }
            else{
                even->next = temp;
                even = even->next;
            }
           
            i++; temp = temp->next;
        }
        even->next = NULL;
        odd->next = head_even->next;
        return head_odd->next;
    }
};