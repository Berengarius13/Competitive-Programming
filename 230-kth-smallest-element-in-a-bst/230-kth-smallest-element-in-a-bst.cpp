/**
 * BST is inorder sorted, just remember that!
 */
class Solution {
private: 
    int ith = 0;
public:
    int inorder(TreeNode* node, int &k){
        if(node == NULL) return 0;
        int a = inorder(node->left, k);
        if(a) return a;
            if(node != NULL){
                ith++;
                if(ith == k)
                    return node->val;
            }
        int b = inorder(node->right, k);
        if(b) return b;
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};