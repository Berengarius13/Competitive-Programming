/* * 
 * Just do merge sort
 * Write a function to merge two lists
 * Write a function to find middle of a list
 * 
 */
class Solution {
public:
    ListNode* Sort(ListNode* headd){
        if(headd->next == NULL) return headd;
        ListNode* middle = middleNode(headd);
        ListNode* before_middle = headd;
        while(before_middle->next != middle) before_middle = before_middle->next;
        before_middle->next = NULL;
        ListNode* a = Sort(headd);
        ListNode* b = Sort(middle);
        
        return mergeTwoLists(a, b);
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        return Sort(head);
    }
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 ==NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* n = new ListNode;
        ListNode* ans= n;
        
        while(l1 !=NULL && l2 !=NULL)
        {
            if(l1->val >=l2->val){
                n->next = l2;
                l2 = l2->next;
                n = n->next; 
            }
            else {
                n->next = l1;
                l1 = l1->next;
                n = n->next;
            }
        }
        if(l1 == NULL)
            n->next=l2;
        if(l2 == NULL)
            n->next=l1;
	
        return ans->next;
    }
};