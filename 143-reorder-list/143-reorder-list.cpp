
/** 
 * iterate indexing from 1
 * Make node of middle+1->next == NULL
 * Reverse the linked list after it
 * Append list2 in list1
 * Each element of list2 after each element of list one
 */
class Solution {
public:
    ListNode* reverseList(ListNode* hea) {
        if (hea == NULL)
        {return hea;}
        ListNode *ffront = hea; 
        ffront=ffront->next;
        ListNode* x = hea;
        x->next = NULL;
        while (ffront!=NULL){
            hea=ffront; 
            ffront=ffront->next;
            hea->next=x;
            x=hea;
        }
        return hea;
    }
    void reorderList(ListNode* head) {
        ListNode* it = head;
        int i = 0;
        while(it != NULL){
            i++;
            it = it->next;
        }
        int k = (i/2)+1; it = head; i = 1;
        ListNode* headb;
        while(it != NULL){
            if(i == k){
                headb = it->next;
                it->next = NULL;
            }
            it = it->next; i++;
        }
        headb = reverseList(headb);
        it = head;
        while(headb != NULL){
            ListNode* temp = headb;
            headb = headb->next;
            temp->next = it->next;
            it->next = temp;
            it = temp->next;
        }
       
    }
};