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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	
	// Resolving the boundery cases
        if(l1==nullptr)
            return l2;
        else if(l2==nullptr)
            return l1;
			
        ListNode* head;
        ListNode* merged;
		
	// Finding the New_Head for the merged LinkedList
        if(l1->val<=l2->val)
        {
            head=l1;
            l1=l1->next;
        }
        else
        {
            head=l2;
            l2=l2->next;
        }
		
        merged=head; // Initialising the merged LL
		
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val<=l2->val)
            {
                merged->next=l1;
                l1=l1->next;
            }
            else
            {
                merged->next=l2;
                l2=l2->next;
            }
            merged=merged->next;
        }
		
	/*Checking whether any of the old LLs has any value left in it... if yes then just             append them all at the end of the final LL*/
        if(l1) merged->next=l1;
        if(l2) merged->next=l2;
        return head;
    }
};