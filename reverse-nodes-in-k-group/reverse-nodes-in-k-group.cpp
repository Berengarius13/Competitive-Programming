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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *b = head, *m = head, *f = head, *st = head;
        ListNode *ans;
        int i = 0;
        int len =0;
        int key=0;
        //
        while(head != NULL){
            head=head->next;
            len++;
        }
        head=b;
        key = (len/k)*k;
        //
        f = f->next;
        //
        if (head->next == NULL) return head;
        //
        ListNode* neu = new ListNode(0);
        ans = neu;
        
        while(f != NULL){
            i++;
            if(i%k==0){
                neu->next = b;
                neu=st;
                if(i == key){
                    neu->next=f;
                    break;
                }
                st = f; 
                m = f;
                b = f; 
                f = f->next; 
                continue;
            }
            m = f;
            f = f->next;
            m->next = b;
            b = m;
            
            
        }
        if(len == key){
            neu->next = m;
            st->next = NULL;
        }
        return ans->next;
        
        
    }
};