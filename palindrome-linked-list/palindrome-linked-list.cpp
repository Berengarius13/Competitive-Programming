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
    bool isPalindrome(ListNode* head) {
        bool ans=true;
        int i=0;
        ListNode* temp =head;
        while (temp!=NULL){
            temp=temp->next; 
            i++;
        }
        
        int m= (i+1)/2;
        ListNode* x=head;
        ListNode* head1=head; 
        ListNode* ffront=head; 
       
        for ( int j = 1; j < m; j++){
            head1=head1->next;
            x=x->next;
            ffront=ffront->next;
        }
         
        ffront=ffront->next;
        x->next=NULL;
          while (ffront!=NULL){
            head1=ffront; 
            ffront=ffront->next;
            head1->next=x;
            x=head1;
          }
          for ( int j =1; j <= m; j++){
              if( head->val == head1->val){
               
                  
              head1=head1->next;
              head=head->next;
                  continue;
              }
              else {
                  ans=false;
                  break;
              }
              head1=head1->next;
              head=head->next;
          }
        return ans;
        }
        
        
         
    
};