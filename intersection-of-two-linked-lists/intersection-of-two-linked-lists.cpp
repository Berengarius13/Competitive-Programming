/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ans;
        ListNode* s;
        ans = NULL;
        s = headB;
        while (headA !=NULL && headB !=NULL){
            if(headA != headB)
            {
                headB= headB->next;
                if(headB == NULL ){
                    headA = headA->next;
                    headB=s;
                }
            }
            else 
            {
                ans =headA;
                break;
            }
            
        }
        return ans;
    }
};