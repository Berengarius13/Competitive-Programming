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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head; 
        int len = 0; 
        
        // Boundary conditions 
        if(head->next == NULL){
            return head;
        }
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        int i =0;
        temp = head; 
        while(temp != NULL){
            i++;
            if(i == ((len/2)+1)){
                head = temp;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
};
*/