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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1; ListNode* insert_a = list1; 
        ListNode* insert_b = list1;
        int i = 0; 
        while(temp != NULL){
            if(i == a-1)
                insert_a = temp;
            if(i == b+1)
                insert_b = temp;
                
            i++; temp = temp->next;
        }
        temp = list2;
        while(temp->next != NULL)
            temp = temp->next;
        
        insert_a->next = list2;
        temp->next = insert_b;
        return list1;
    }
};