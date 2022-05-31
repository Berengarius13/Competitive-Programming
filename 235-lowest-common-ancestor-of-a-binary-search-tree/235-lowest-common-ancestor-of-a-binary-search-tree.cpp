/**
 * In bst during traversal you will always find that 
   left is smaller than root and right is larger than root
 * Using this property we can conclude that
 * If root is greater than p and root is smaller than q then we have our answer
 * Or if root is q and and p is greater than q
 * Or if root is p and q is lesser than p
 * Inverse of above is that 
 * If root is greater than p and q than lsa is in left subtree
 * If root is smaller than p and q lsa is in rihgh subtree
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root -> val > p -> val) && (root -> val > q -> val)) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if ((root -> val < p -> val) && (root -> val < q -> val)) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }
};