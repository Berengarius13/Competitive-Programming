/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* Make a a diagram for this question, check the distance moved by each pointer l1 and l2 
let distance till entry of loop will be x1, x2 after that where l1 and l2 overlap and x3 after that the
distance travelled by l3 till entry of loop.
we know distance traveled by l2 is twice of l1
solving the following equations we get x1  = x3
which is a very important piece of informations which we can use to solve the quesetion*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        bool cycle = false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) 
            {
                cycle = true;
                break;
            }
        }
        if(!cycle) return NULL;
        slow = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};