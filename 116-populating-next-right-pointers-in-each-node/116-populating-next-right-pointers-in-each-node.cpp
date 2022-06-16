
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node* next_node = NULL;
            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                node->next = next_node;
                next_node = node;
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
            }
        }
        return root;
    }
};