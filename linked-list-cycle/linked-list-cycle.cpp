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
    bool hasCycle(ListNode *head) {
        bool ans = false; 
        if (head == NULL)
            return false;
        ListNode *ff = head->next;
        if(ff == head)
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