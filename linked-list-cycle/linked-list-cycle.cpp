/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Reverse the whole linked list and ff will return to initial position.
// Or can use fater and slower approach 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool ans = false; 
        if (head == NULL)
            return false; // Boundary condition
        ListNode *ff = head->next;
        if(ff == head)   // Condition if next pointer is pointing to itself (boundary condition)
            return true;
        ListNode *c  = head;
        ListNode *bb = head;
        ListNode *kk = head;
        c->next = NULL;
        while (ff != nullptr)
        {
            bb = ff;
            ff = ff->next;
            bb->next = c; 
            c = bb;
            if(ff == kk)
            {
                ans = true;
                break;
            }
        }
        return ans;
        
        
    }
};