/* Use post order traversal cuz you need access to left and right node, form middle node to connect */
class Solution {
public:
    TreeNode* dfs(TreeNode* node){
        if(node == NULL) return NULL;
        
        TreeNode* left = dfs(node->left);
        TreeNode* right = dfs(node->right);
        if(!left && !right)  return node;
        
        if(!left) return node;
        // if(!right){
        //     node->right = node->left;
        //     node->left = NULL;
        //     return node;
        // }
        TreeNode* temp = left;
        while(temp->right != NULL) temp = temp->right;
        temp->right = right;
        node->right = left;
        node->left = NULL;
        return node;
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};