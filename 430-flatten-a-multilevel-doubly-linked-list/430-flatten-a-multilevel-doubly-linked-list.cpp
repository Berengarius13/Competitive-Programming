class Solution {
public:
    Node* dfs(Node* node){
        if(node == NULL) return NULL;
        
        Node* Child = dfs(node->child);
        Node* Next = dfs(node->next);
        
        if(Child == NULL && Next == NULL) return node;
        if(Child == NULL) return Next;
        
            Node* temp = node->next;
            node->next = node->child;
            node->child = NULL;
            node->next->prev = node;
        
        if(Next == NULL) return Child;
        
            Child->next = temp;
            temp->prev  = Child;
        
        return Next;
    }
    Node* flatten(Node* head) {
        Node* node = head;
        dfs(node);
        return head;
    }
};









































/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/