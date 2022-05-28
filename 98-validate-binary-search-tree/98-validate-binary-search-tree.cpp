/**
* So the trick is to draw 8 nodes binary tree on notebook
* Done?
* Then start filling values from left most end, 
* You will fill 1, then to top node = 2, then to lower node = 3, then to parent of all three = 4.
* Next where do you fill, to right child of parent, or left child or right child of parent?
* Well you will take the latter choice why? Cuz it's ensures next sub tree min value is greater
  than the max value till now. Get it?
* Now keep doing it, you will realize that you are doing an inorder traversal of binary tree.
* So trick should be to inorder traverse, remember the previous node, and compare it with current.
* Returning method will fail cuz, when you return the "b", it will start doing post order traveral
* You somehow need to remember the previous value.
* Later comes designing the bool function.
* If false, you want to stop it and return a false from every function. Contenous return calls.
* If true keep checking
*/
class Solution {
private:
    TreeNode* prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true; // Keep continuing recursion calls same as return void
        
        if(isValidBST(root->left) == false)
            return false;
        if(prev != NULL && prev->val >= root->val) return false;
        prev = root; // Remember the previous value for next recursion call;
        if(isValidBST(root->right) == false)
            return false;
        
        return true; // Keep coninuing recursion calls/ same as return void
    }
};