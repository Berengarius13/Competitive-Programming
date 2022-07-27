/* Use post order traversal cuz you need access to left and right node, form middle node to connect */
/*
* Lets say L-N-R, in recursion just think result of one subproblem
* Connect R to the end_node-> right (of left side)
* Node left is null and node right is left
* make case if left is null, then just return node
* remember to reach the left most end use of temporary var 
*/
class Solution {
public:
    TreeNode* dfs(TreeNode* node){
        if(node == NULL) return NULL;
        
        TreeNode* left = dfs(node->left);
        TreeNode* right = dfs(node->right);
        if(!left && !right)  return node;
        
        if(!left) return node;
        TreeNode* temp = left; // Stupid mistake
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