/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = head; 
        if(head == NULL) // Boundary condition 
            return NULL;
        Node* b = head; Node * a = head;  
        b = b->next;
        
        while (a != NULL){   // Join Linked list like l1->l2-l1->l2
            a->next = new Node(a->val);
            a->next->next = b;
            a = b;
            if(b!=NULL)
            b = b->next;
        }
        a = head; b = head; 
        ans = head->next; // obvious 
        
        while (a != NULL){   // Move random one step ahead 
            if(a->random == NULL)
                a->next->random == NULL;
            else {a->next->random = a->random->next;}
            a = a->next->next;
        }
        a = head;
        a = a->next; 
        b = b->next->next; 
        while ( b != NULL)
        {
            head->next = b;
            head  = a; 
            a = a->next; 
            b = b->next; 
        }
        head->next =NULL; a->next = NULL;
        return ans; 
    }
};