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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL || left == right )
            return head;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* mark_a = NULL;
        ListNode* mark_b = NULL;
        int i = 1;
        int last = -1;
        while(a != NULL){
            if(left == 1 && i == 1){
                mark_b = a;
            }
            if(i == left -1){
                mark_a = a;
                mark_b = b;
            }
            if(a->next == NULL){
                last = i;
            }
            
            if(i >= left and i < right){
                ListNode * c = b;
                b = b->next;
                c->next = a;
                a = c;
                i++; 
                continue;
            }
            
            if(i == right){
                if(right == last){
                    b = NULL;
                }
                if(left == 1){
                    mark_b->next = b;
                    head = a;
                }
                else{
                    mark_a->next = a;
                    mark_b->next = b;
                }
                break;
            }
            i++;
            a = a->next;
            b = b->next;
        }
        return head;
    }
};